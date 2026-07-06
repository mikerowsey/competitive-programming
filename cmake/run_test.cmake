foreach(VAR PROGRAM INPUT EXPECTED)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

if(NOT DEFINED TIMEOUT_SECONDS)
    set(TIMEOUT_SECONDS 2)
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

file(READ "${EXPECTED}" EXPECTED_OUTPUT)

# Keep strict comparison while avoiding platform-specific CRLF noise.
string(REPLACE "\r\n" "\n" ACTUAL_OUTPUT "${ACTUAL_OUTPUT}")
string(REPLACE "\r\n" "\n" EXPECTED_OUTPUT "${EXPECTED_OUTPUT}")

# Ignore trailing spaces/tabs at line ends and final newline differences.
string(REGEX REPLACE "[ \t]+\n" "\n" ACTUAL_OUTPUT "${ACTUAL_OUTPUT}")
string(REGEX REPLACE "[ \t]+\n" "\n" EXPECTED_OUTPUT "${EXPECTED_OUTPUT}")
string(REGEX REPLACE "[ \t]+$" "" ACTUAL_OUTPUT "${ACTUAL_OUTPUT}")
string(REGEX REPLACE "[ \t]+$" "" EXPECTED_OUTPUT "${EXPECTED_OUTPUT}")
string(REGEX REPLACE "\n+$" "" ACTUAL_OUTPUT "${ACTUAL_OUTPUT}")
string(REGEX REPLACE "\n+$" "" EXPECTED_OUTPUT "${EXPECTED_OUTPUT}")

if(NOT ACTUAL_OUTPUT STREQUAL EXPECTED_OUTPUT)
    message(FATAL_ERROR
        "Output mismatch.\n\n"
        "Expected:\n"
        "${EXPECTED_OUTPUT}\n\n"
        "Actual:\n"
        "${ACTUAL_OUTPUT}"
    )
endif()

