foreach(VAR PROGRAM INPUT)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

if(NOT DEFINED TIMEOUT_SECONDS)
    set(TIMEOUT_SECONDS 5)
endif()

execute_process(
    COMMAND "${PROGRAM}"
    INPUT_FILE "${INPUT}"
    OUTPUT_VARIABLE ACTUAL_OUTPUT
    ERROR_VARIABLE ACTUAL_ERROR
    RESULT_VARIABLE EXIT_CODE
    TIMEOUT ${TIMEOUT_SECONDS}
)

if(NOT EXIT_CODE EQUAL 0)
    message(FATAL_ERROR
        "Program exited with code ${EXIT_CODE}\n\n"
        "Stderr:\n"
        "${ACTUAL_ERROR}"
    )
endif()

file(READ "${INPUT}" INPUT_TEXT)
string(REPLACE "\r\n" "\n" INPUT_TEXT "${INPUT_TEXT}")
string(REPLACE "\n" ";" INPUT_LINES "${INPUT_TEXT}")

file(WRITE "${CMAKE_BINARY_DIR}/raab_validator_input.txt" "${INPUT_TEXT}")
file(WRITE "${CMAKE_BINARY_DIR}/raab_validator_output.txt" "${ACTUAL_OUTPUT}")

execute_process(
    COMMAND
        ${CMAKE_COMMAND} -E env
        PYTHONUTF8=1
        python3
        -c
"import sys\nfrom pathlib import Path\n\ndef next_non_empty(lines, i):\n    n = len(lines)\n    while i < n and lines[i].strip() == '':\n        i += 1\n    return i\n\nin_path = Path(sys.argv[1])\nout_path = Path(sys.argv[2])\n\nin_lines = in_path.read_text(encoding='utf-8').splitlines()\nout_lines = out_path.read_text(encoding='utf-8').splitlines()\n\nif not in_lines:\n    print('Empty input', file=sys.stderr)\n    sys.exit(1)\n\ntry:\n    t = int(in_lines[0].strip())\nexcept Exception:\n    print('Invalid test count in input', file=sys.stderr)\n    sys.exit(1)\n\nif len(in_lines) < t + 1:\n    print('Not enough input test lines', file=sys.stderr)\n    sys.exit(1)\n\nidx_out = 0\nfor case_id in range(1, t + 1):\n    try:\n        n, a, b = map(int, in_lines[case_id].split())\n    except Exception:\n        print(f'Invalid input line for case {case_id}', file=sys.stderr)\n        sys.exit(1)\n\n    idx_out = next_non_empty(out_lines, idx_out)\n    if idx_out >= len(out_lines):\n        print(f'Missing answer for case {case_id}', file=sys.stderr)\n        sys.exit(1)\n\n    ans = out_lines[idx_out].strip()\n    idx_out += 1\n\n    possible = ((a == 0 and b == 0) or (a > 0 and b > 0 and a + b <= n))\n\n    if ans not in ('YES', 'NO'):\n        print(f'Invalid answer token in case {case_id}: {ans}', file=sys.stderr)\n        sys.exit(1)\n\n    if ans == 'NO':\n        if possible:\n            print(f'Case {case_id}: expected YES but got NO', file=sys.stderr)\n            sys.exit(1)\n        continue\n\n    if not possible:\n        print(f'Case {case_id}: expected NO but got YES', file=sys.stderr)\n        sys.exit(1)\n\n    idx_out = next_non_empty(out_lines, idx_out)\n    if idx_out >= len(out_lines):\n        print(f'Case {case_id}: missing first permutation line', file=sys.stderr)\n        sys.exit(1)\n    p1 = out_lines[idx_out].split()\n    idx_out += 1\n\n    idx_out = next_non_empty(out_lines, idx_out)\n    if idx_out >= len(out_lines):\n        print(f'Case {case_id}: missing second permutation line', file=sys.stderr)\n        sys.exit(1)\n    p2 = out_lines[idx_out].split()\n    idx_out += 1\n\n    if len(p1) != n or len(p2) != n:\n        print(f'Case {case_id}: permutation length mismatch', file=sys.stderr)\n        sys.exit(1)\n\n    try:\n        arr1 = [int(x) for x in p1]\n        arr2 = [int(x) for x in p2]\n    except Exception:\n        print(f'Case {case_id}: non-integer permutation values', file=sys.stderr)\n        sys.exit(1)\n\n    expected = list(range(1, n + 1))\n    if sorted(arr1) != expected or sorted(arr2) != expected:\n        print(f'Case {case_id}: lines are not permutations 1..n', file=sys.stderr)\n        sys.exit(1)\n\n    sa = 0\n    sb = 0\n    for x, y in zip(arr1, arr2):\n        if x > y:\n            sa += 1\n        elif y > x:\n            sb += 1\n\n    if sa != a or sb != b:\n        print(f'Case {case_id}: score mismatch got ({sa},{sb}) expected ({a},{b})', file=sys.stderr)\n        sys.exit(1)\n\nprint('OK')"
        "${CMAKE_BINARY_DIR}/raab_validator_input.txt"
        "${CMAKE_BINARY_DIR}/raab_validator_output.txt"
    RESULT_VARIABLE VALIDATOR_EXIT_CODE
    OUTPUT_VARIABLE VALIDATOR_OUTPUT
    ERROR_VARIABLE VALIDATOR_ERROR
)

if(NOT VALIDATOR_EXIT_CODE EQUAL 0)
    message(FATAL_ERROR
        "Raab validator failed.\n\n"
        "Details:\n${VALIDATOR_ERROR}\n"
        "Program output:\n${ACTUAL_OUTPUT}"
    )
endif()
