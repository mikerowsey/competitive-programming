foreach(VAR INPUT OUTPUT)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

set(PYTHON_VALIDATOR "
import sys
from pathlib import Path

in_path = Path(sys.argv[1])
out_path = Path(sys.argv[2])

input_tokens = in_path.read_text(encoding='utf-8').split()
output_tokens = out_path.read_text(encoding='utf-8').split()

if len(input_tokens) < 2:
    print('Invalid input header', file=sys.stderr)
    sys.exit(1)

try:
    n = int(input_tokens[0])
    target = int(input_tokens[1])
except Exception:
    print('Invalid n/target values', file=sys.stderr)
    sys.exit(1)

if len(input_tokens) != n + 2:
    print('Input length does not match n', file=sys.stderr)
    sys.exit(1)

values = list(map(int, input_tokens[2:]))

possible = False
seen = set()
for value in values:
    if target - value in seen:
        possible = True
        break
    seen.add(value)

if len(output_tokens) == 1 and output_tokens[0] == 'IMPOSSIBLE':
    if possible:
        print('Expected a valid pair but got IMPOSSIBLE', file=sys.stderr)
        sys.exit(1)
    sys.exit(0)

if len(output_tokens) != 2:
    print('Output must be IMPOSSIBLE or two indices', file=sys.stderr)
    sys.exit(1)

try:
    i = int(output_tokens[0])
    j = int(output_tokens[1])
except Exception:
    print('Non-integer output token', file=sys.stderr)
    sys.exit(1)

if not (1 <= i <= n and 1 <= j <= n):
    print('Index out of bounds', file=sys.stderr)
    sys.exit(1)

if i == j:
    print('Indices must be distinct', file=sys.stderr)
    sys.exit(1)

if values[i - 1] + values[j - 1] != target:
    print('Chosen indices do not sum to target', file=sys.stderr)
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
        "Sum of Two Values validator failed.\n\n"
        "Details:\n${VALIDATOR_ERROR}\n"
    )
endif()
