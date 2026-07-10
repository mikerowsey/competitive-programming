set(CSES_PROBLEMS
    apartments
    apple_division
    bit_strings
    chessboard_and_queens
    coin_piles
    collecting_numbers
    collecting_numbers_ii
    creating_strings
    digit_queries
    distinct_numbers
    ferris_wheel
    gray_code_bit
    grid_coloring_i
    grid_path_description
    increasing_array
    knight_moves_grid
    maximum_subarray_sum
    mex_grid_construction
    missing_coin_sum
    missing_number
    movie_festival
    number_spiral
    palindrome_reorder
    permutations
    raab_game_i
    repetitions
    restaurant_customers
    stick_lengths
    string_reorder
    sum_of_two_values
    tower_of_hanoi
    trailing_zeros
    two_knights
    two_sets
    weird_algorithm
)

foreach(PROBLEM_NAME IN LISTS CSES_PROBLEMS)
    set(PROBLEM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_NAME}")
    set(WIP_MARKER_FILE "${PROBLEM_DIR}/.wip")
    set(MAIN_FILE "${PROBLEM_DIR}/${PROBLEM_NAME}.cpp")

    if(EXISTS "${WIP_MARKER_FILE}")
        message(STATUS "Skipping ${PROBLEM_NAME}: marked as WIP (.wip)")
        continue()
    endif()

    if(NOT EXISTS "${MAIN_FILE}")
        message(STATUS "Skipping ${PROBLEM_NAME}: missing ${PROBLEM_NAME}.cpp")
        continue()
    endif()

    add_executable(
        ${PROBLEM_NAME}
        "${MAIN_FILE}"
    )

    target_link_libraries(
        ${PROBLEM_NAME}
        PRIVATE
            cp_project_options
            cp_project_warnings
            cp_sanitizers
    )
endforeach()

if(BUILD_TESTING AND CP_ENABLE_GOOGLETEST)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)

    include(GoogleTest)

    foreach(PROBLEM_NAME IN LISTS CSES_PROBLEMS)
        set(PROBLEM_MAIN_CPP "${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_NAME}/${PROBLEM_NAME}.cpp")
        set(PROBLEM_GTEST_CPP "${PROJECT_SOURCE_DIR}/tests/${PROBLEM_NAME}/${PROBLEM_NAME}_gtest.cpp")

        if(NOT EXISTS "${PROBLEM_MAIN_CPP}" OR NOT EXISTS "${PROBLEM_GTEST_CPP}")
            continue()
        endif()

        set(PROBLEM_GTEST_TARGET "${PROBLEM_NAME}_gtest")

        add_executable(
            ${PROBLEM_GTEST_TARGET}
            "${PROBLEM_MAIN_CPP}"
            "${PROBLEM_GTEST_CPP}"
        )

        target_compile_definitions(
            ${PROBLEM_GTEST_TARGET}
            PRIVATE
                CP_DISABLE_MAIN
                CP_REPO_ROOT="${PROJECT_SOURCE_DIR}"
        )

        target_link_libraries(
            ${PROBLEM_GTEST_TARGET}
            PRIVATE
                cp_project_options
                cp_project_warnings
                cp_sanitizers
                GTest::gtest_main
        )

        gtest_discover_tests(
            ${PROBLEM_GTEST_TARGET}
            TEST_PREFIX gtest.cses.${PROBLEM_NAME}.
        )
    endforeach()
endif()
