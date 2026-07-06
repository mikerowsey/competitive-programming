foreach(VAR INPUT OUTPUT)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

set(PYTHON_VALIDATOR "
import sys
from pathlib import Path

def next_non_empty(lines, i):
    n = len(lines)
    while i < n and lines[i].strip() == '':
        i += 1
    return i

in_path = Path(sys.argv[1])
out_path = Path(sys.argv[2])

in_lines = in_path.read_text(encoding='utf-8').splitlines()
out_lines = out_path.read_text(encoding='utf-8').splitlines()

if not in_lines:
    print('Empty input', file=sys.stderr)
    sys.exit(1)

try:
    t = int(in_lines[0].strip())
except Exception:
    print('Invalid test count in input', file=sys.stderr)
    sys.exit(1)

if len(in_lines) < t + 1:
    print('Not enough input test lines', file=sys.stderr)
    sys.exit(1)

idx_out = 0
for case_id in range(1, t + 1):
    try:
        n, a, b = map(int, in_lines[case_id].split())
    except Exception:
        print(f'Invalid input line for case {case_id}', file=sys.stderr)
        sys.exit(1)

    idx_out = next_non_empty(out_lines, idx_out)
    if idx_out >= len(out_lines):
        print(f'Missing answer for case {case_id}', file=sys.stderr)
        sys.exit(1)

    ans = out_lines[idx_out].strip()
    idx_out += 1

    possible = ((a == 0 and b == 0) or (a > 0 and b > 0 and a + b <= n))

    if ans not in ('YES', 'NO'):
        print(f'Invalid answer token in case {case_id}: {ans}', file=sys.stderr)
        sys.exit(1)

    if ans == 'NO':
        if possible:
            print(f'Case {case_id}: expected YES but got NO', file=sys.stderr)
            sys.exit(1)
        continue

    if not possible:
        print(f'Case {case_id}: expected NO but got YES', file=sys.stderr)
        sys.exit(1)

    idx_out = next_non_empty(out_lines, idx_out)
    if idx_out >= len(out_lines):
        print(f'Case {case_id}: missing first permutation line', file=sys.stderr)
        sys.exit(1)
    p1 = out_lines[idx_out].split()
    idx_out += 1

    idx_out = next_non_empty(out_lines, idx_out)
    if idx_out >= len(out_lines):
        print(f'Case {case_id}: missing second permutation line', file=sys.stderr)
        sys.exit(1)
    p2 = out_lines[idx_out].split()
    idx_out += 1

    if len(p1) != n or len(p2) != n:
        print(f'Case {case_id}: permutation length mismatch', file=sys.stderr)
        sys.exit(1)

    try:
        perm1 = list(map(int, p1))
        perm2 = list(map(int, p2))
    except Exception:
        print(f'Case {case_id}: non-integer permutation value', file=sys.stderr)
        sys.exit(1)

    expected = list(range(1, n + 1))
    if sorted(perm1) != expected:
        print(f'Case {case_id}: first row is not a permutation 1..n', file=sys.stderr)
        sys.exit(1)
    if sorted(perm2) != expected:
        print(f'Case {case_id}: second row is not a permutation 1..n', file=sys.stderr)
        sys.exit(1)

    score1 = sum(1 for i in range(n) if perm1[i] > perm2[i])
    score2 = sum(1 for i in range(n) if perm1[i] < perm2[i])

    if score1 != a or score2 != b:
        print(
            f'Case {case_id}: score mismatch, got ({score1}, {score2}) expected ({a}, {b})',
            file=sys.stderr,
        )
        sys.exit(1)

idx_out = next_non_empty(out_lines, idx_out)
if idx_out < len(out_lines):
    print('Extra unexpected output lines after last case', file=sys.stderr)
    sys.exit(1)
")

execute_process(
    COMMAND
        ${CMAKE_COMMAND} -E env
        PYTHONUTF8=1
        python3
        -c
        "${PYTHON_VALIDATOR}"
        "${INPUT}"
        "${OUTPUT}"
    RESULT_VARIABLE VALIDATOR_EXIT_CODE
    OUTPUT_VARIABLE VALIDATOR_OUTPUT
    ERROR_VARIABLE VALIDATOR_ERROR
)

if(NOT VALIDATOR_EXIT_CODE EQUAL 0)
    message(FATAL_ERROR
        "Raab validator failed.\n\n"
        "Details:\n${VALIDATOR_ERROR}\n"
    )
endif()
