add_test(
    NAME cses.weird_algorithm
    COMMAND
        ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:weird_algorithm>
        -DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/cses/weird_algorithm/test_input.txt
        -DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/cses/weird_algorithm/test_output.txt
        -P ${CMAKE_CURRENT_SOURCE_DIR}/run_test.cmake
)

add_test(
    NAME cses.missing_number
    COMMAND
        ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:missing_number>
        -DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/cses/missing_number/test_input.txt
        -DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/cses/missing_number/test_output.txt
        -P ${CMAKE_CURRENT_SOURCE_DIR}/run_test.cmake
)
