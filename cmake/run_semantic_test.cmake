foreach(VAR TEST_NAME PROGRAM INPUT VALIDATOR)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

if(NOT DEFINED TIMEOUT_SECONDS)
    set(TIMEOUT_SECONDS 5)
endif()

string(MAKE_C_IDENTIFIER "${TEST_NAME}" TEST_NAME_ID)
set(OUTPUT_FILE "${CMAKE_BINARY_DIR}/${TEST_NAME_ID}.stdout.txt")
set(ERROR_FILE "${CMAKE_BINARY_DIR}/${TEST_NAME_ID}.stderr.txt")

execute_process(
    COMMAND "${PROGRAM}"
    INPUT_FILE "${INPUT}"
    OUTPUT_FILE "${OUTPUT_FILE}"
    ERROR_FILE "${ERROR_FILE}"
    RESULT_VARIABLE EXIT_CODE
    TIMEOUT ${TIMEOUT_SECONDS}
)

if(NOT EXIT_CODE EQUAL 0)
    file(READ "${ERROR_FILE}" PROGRAM_ERROR)
    message(FATAL_ERROR
        "Program exited with code ${EXIT_CODE}\n\n"
        "Stderr:\n${PROGRAM_ERROR}"
    )
endif()

execute_process(
    COMMAND
        ${CMAKE_COMMAND}
        -DPROGRAM=${PROGRAM}
        -DINPUT=${INPUT}
        -DOUTPUT=${OUTPUT_FILE}
        -DSTDERR_FILE=${ERROR_FILE}
        -P ${VALIDATOR}
    RESULT_VARIABLE VALIDATOR_EXIT_CODE
    OUTPUT_VARIABLE VALIDATOR_STDOUT
    ERROR_VARIABLE VALIDATOR_STDERR
)

if(NOT VALIDATOR_EXIT_CODE EQUAL 0)
    file(READ "${OUTPUT_FILE}" ACTUAL_OUTPUT)
    message(FATAL_ERROR
        "Semantic validator failed for ${TEST_NAME}.\n\n"
        "Validator output:\n${VALIDATOR_STDOUT}${VALIDATOR_STDERR}\n"
        "Program output:\n${ACTUAL_OUTPUT}"
    )
endif()
