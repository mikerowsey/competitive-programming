file(GLOB PROBLEM_DIRS CONFIGURE_DEPENDS *)

foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    if(NOT IS_DIRECTORY "${PROBLEM_DIR}")
        continue()
    endif()

    get_filename_component(PROBLEM_NAME "${PROBLEM_DIR}" NAME)

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

    # Default to strict output matching unless overridden by per-problem metadata.
    set(CP_TEST_KIND "exact")
    set(CP_TEST_VALIDATOR "")
    set(CP_TEST_TIMEOUT_SECONDS 2)

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
                    -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                    -DINPUT=${TEST_INPUT_FILE}
                    -DTIMEOUT_SECONDS=${CP_TEST_TIMEOUT_SECONDS}
                    -P ${CP_TEST_VALIDATOR}
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
endforeach()
