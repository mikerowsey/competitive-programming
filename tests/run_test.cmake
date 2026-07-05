execute_process(
    COMMAND "${PROGRAM}"
    INPUT_FILE "${INPUT}"
    OUTPUT_VARIABLE ACTUAL_OUTPUT
    RESULT_VARIABLE EXIT_CODE
)

if(NOT EXIT_CODE EQUAL 0)
    message(FATAL_ERROR
        "Program exited with code ${EXIT_CODE}"
    )
endif()

file(READ "${EXPECTED}" EXPECTED_OUTPUT)

if(NOT ACTUAL_OUTPUT STREQUAL EXPECTED_OUTPUT)
    string(LENGTH "${EXPECTED_OUTPUT}" EXPECTED_LENGTH)
    string(LENGTH "${ACTUAL_OUTPUT}" ACTUAL_LENGTH)

    message(FATAL_ERROR
        "Output mismatch.\n"
        "Expected length: ${EXPECTED_LENGTH}\n"
        "Actual length:   ${ACTUAL_LENGTH}\n\n"
        "Expected:\n${EXPECTED_OUTPUT}\n\n"
        "Actual:\n${ACTUAL_OUTPUT}"
    )
endif()
