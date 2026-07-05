foreach(VAR PROGRAM INPUT EXPECTED)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

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
    message(FATAL_ERROR
        "Output mismatch.\n\n"
        "Expected:\n"
        "${EXPECTED_OUTPUT}\n\n"
        "Actual:\n"
        "${ACTUAL_OUTPUT}"
    )
endif()

