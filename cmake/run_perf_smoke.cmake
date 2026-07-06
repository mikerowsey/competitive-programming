foreach(VAR PROGRAM INPUT MAX_MS)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

if(NOT DEFINED RUNS)
    set(RUNS 3)
endif()

if(RUNS LESS 1)
    message(FATAL_ERROR "RUNS must be >= 1")
endif()

set(PYTHON_SCRIPT "
import subprocess
import sys
import time

program = sys.argv[1]
input_path = sys.argv[2]
max_ms = float(sys.argv[3])
runs = int(sys.argv[4])

timings = []
for _ in range(runs):
    with open(input_path, 'rb') as fin:
        start = time.perf_counter()
        proc = subprocess.run([program], stdin=fin, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE)
        elapsed_ms = (time.perf_counter() - start) * 1000.0
    if proc.returncode != 0:
        sys.stderr.write(f'Program exited with code {proc.returncode}\\n')
        if proc.stderr:
            sys.stderr.write(proc.stderr.decode('utf-8', errors='replace'))
        sys.exit(2)
    timings.append(elapsed_ms)

median_ms = sorted(timings)[len(timings) // 2]
if median_ms > max_ms:
    sys.stderr.write(f'Perf smoke check failed: median={median_ms:.3f}ms > budget={max_ms:.3f}ms; samples={timings}\\n')
    sys.exit(1)

print(f'Perf smoke check passed: median={median_ms:.3f}ms <= budget={max_ms:.3f}ms; samples={timings}')
")

execute_process(
    COMMAND
        ${CMAKE_COMMAND} -E env
        PYTHONUTF8=1
        python3
        -c
        "${PYTHON_SCRIPT}"
        "${PROGRAM}"
        "${INPUT}"
        "${MAX_MS}"
        "${RUNS}"
    RESULT_VARIABLE PERF_EXIT_CODE
    OUTPUT_VARIABLE PERF_OUTPUT
    ERROR_VARIABLE PERF_ERROR
)

if(NOT PERF_EXIT_CODE EQUAL 0)
    message(FATAL_ERROR "${PERF_ERROR}")
endif()

message(STATUS "${PERF_OUTPUT}")
