set(CP_ENABLE_PERF_TESTS OFF CACHE BOOL "Enable performance smoke tests")

set(CSES_PROBLEMS
    apple_division
    bit_strings
    chessboard_and_queens
    coin_piles
    creating_strings
    digit_queries
    distinct_numbers
    gray_code_bit
    grid_coloring_i
    grid_path_description
    increasing_array
    knight_moves_grid
    mex_grid_construction
    missing_number
    number_spiral
    palindrome_reorder
    permutations
    raab_game_i
    repetitions
    string_reorder
    tower_of_hanoi
    trailing_zeros
    two_knights
    two_sets
    weird_algorithm
)

foreach(PROBLEM_NAME IN LISTS CSES_PROBLEMS)
    set(PROBLEM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_NAME}")
    set(WIP_MARKER_FILE "${PROBLEM_DIR}/.wip")
    set(MAIN_FILE "${PROBLEM_DIR}/main.cpp")
    set(TEST_INPUT_FILE "${PROBLEM_DIR}/test_input.txt")
    set(TEST_OUTPUT_FILE "${PROBLEM_DIR}/test_output.txt")
    set(TEST_CONFIG_FILE "${PROBLEM_DIR}/test.config.cmake")

    if(EXISTS "${WIP_MARKER_FILE}")
        message(STATUS "Skipping ${PROBLEM_NAME}: marked as WIP (.wip)")
        continue()
    endif()

    if(NOT EXISTS "${MAIN_FILE}")
        message(STATUS "Skipping ${PROBLEM_NAME}: missing main.cpp")
        continue()
    endif()

    add_executable(
        ${PROBLEM_NAME}
        "${MAIN_FILE}"
    )

    target_compile_features(
        ${PROBLEM_NAME}
        PRIVATE
            cxx_std_23
    )

    target_compile_options(
        ${PROBLEM_NAME}
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )

    # Defaults for per-problem test metadata.
    set(CP_TEST_KIND "exact")
    set(CP_TEST_VALIDATOR "")
    set(CP_TEST_TIMEOUT_SECONDS 2)

    # Optional performance smoke settings.
    set(CP_PERF_ENABLED OFF)
    set(CP_PERF_INPUT "")
    set(CP_PERF_MAX_MS 0)
    set(CP_PERF_RUNS 3)

    if(EXISTS "${TEST_CONFIG_FILE}")
        include("${TEST_CONFIG_FILE}")
    endif()

    if(CP_TEST_KIND STREQUAL "exact")
        if(EXISTS "${TEST_INPUT_FILE}" AND EXISTS "${TEST_OUTPUT_FILE}")
            add_test(
                NAME cses.${PROBLEM_NAME}
                COMMAND
                    ${CMAKE_COMMAND}
                    -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                    -DINPUT=${TEST_INPUT_FILE}
                    -DEXPECTED=${TEST_OUTPUT_FILE}
                    -DTIMEOUT_SECONDS=${CP_TEST_TIMEOUT_SECONDS}
                    -P ${PROJECT_SOURCE_DIR}/cmake/run_test.cmake
            )
        else()
            message(STATUS "Skipping test cses.${PROBLEM_NAME}: missing test_input.txt or test_output.txt")
        endif()
    elseif(CP_TEST_KIND STREQUAL "semantic")
        if(NOT EXISTS "${TEST_INPUT_FILE}")
            message(STATUS "Skipping test cses.${PROBLEM_NAME}: missing test_input.txt")
        elseif(CP_TEST_VALIDATOR STREQUAL "")
            message(STATUS "Skipping test cses.${PROBLEM_NAME}: CP_TEST_VALIDATOR is not set")
        elseif(NOT EXISTS "${CP_TEST_VALIDATOR}")
            message(STATUS "Skipping test cses.${PROBLEM_NAME}: validator not found: ${CP_TEST_VALIDATOR}")
        else()
            add_test(
                NAME cses.${PROBLEM_NAME}
                COMMAND
                    ${CMAKE_COMMAND}
                    -DTEST_NAME=cses.${PROBLEM_NAME}
                    -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                    -DINPUT=${TEST_INPUT_FILE}
                    -DVALIDATOR=${CP_TEST_VALIDATOR}
                    -DTIMEOUT_SECONDS=${CP_TEST_TIMEOUT_SECONDS}
                    -P ${PROJECT_SOURCE_DIR}/cmake/run_semantic_test.cmake
            )
        endif()
    else()
        message(STATUS "Skipping test cses.${PROBLEM_NAME}: unknown CP_TEST_KIND='${CP_TEST_KIND}'")
    endif()

    if(TEST cses.${PROBLEM_NAME})
        set_tests_properties(
            cses.${PROBLEM_NAME}
            PROPERTIES
                LABELS "cses;${PROBLEM_NAME}"
        )
    endif()

    if(CP_ENABLE_PERF_TESTS AND CP_PERF_ENABLED)
        if(CP_PERF_INPUT STREQUAL "")
            set(CP_PERF_INPUT "${TEST_INPUT_FILE}")
        endif()

        if(NOT EXISTS "${CP_PERF_INPUT}")
            message(STATUS "Skipping perf test perf.cses.${PROBLEM_NAME}: missing input '${CP_PERF_INPUT}'")
        elseif(CP_PERF_MAX_MS LESS_EQUAL 0)
            message(STATUS "Skipping perf test perf.cses.${PROBLEM_NAME}: CP_PERF_MAX_MS must be > 0")
        else()
            add_test(
                NAME perf.cses.${PROBLEM_NAME}
                COMMAND
                    ${CMAKE_COMMAND}
                    -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                    -DINPUT=${CP_PERF_INPUT}
                    -DMAX_MS=${CP_PERF_MAX_MS}
                    -DRUNS=${CP_PERF_RUNS}
                    -P ${PROJECT_SOURCE_DIR}/cmake/run_perf_smoke.cmake
            )

            set_tests_properties(
                perf.cses.${PROBLEM_NAME}
                PROPERTIES
                    LABELS "cses;perf;${PROBLEM_NAME}"
            )
        endif()
    endif()
endforeach()
