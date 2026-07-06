file(GLOB PROBLEM_DIRS CONFIGURE_DEPENDS *)

foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    if(IS_DIRECTORY "${PROBLEM_DIR}")
        get_filename_component(PROBLEM_NAME "${PROBLEM_DIR}" NAME)

        set(WIP_MARKER_FILE "${PROBLEM_DIR}/.wip")
        set(MAIN_FILE "${PROBLEM_DIR}/main.cpp")
        set(TEST_INPUT_FILE "${PROBLEM_DIR}/test_input.txt")
        set(TEST_OUTPUT_FILE "${PROBLEM_DIR}/test_output.txt")

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

        if(EXISTS "${TEST_INPUT_FILE}" AND EXISTS "${TEST_OUTPUT_FILE}")
            if(PROBLEM_NAME STREQUAL "raab_game_i")
                add_test(
                    NAME cses.${PROBLEM_NAME}
                    COMMAND
                        ${CMAKE_COMMAND}
                        -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                        -DINPUT=${TEST_INPUT_FILE}
                        -P ${PROJECT_SOURCE_DIR}/cmake/validate_raab_game_i.cmake
                )
            else()
                add_test(
                    NAME cses.${PROBLEM_NAME}
                    COMMAND
                        ${CMAKE_COMMAND}
                        -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                        -DINPUT=${TEST_INPUT_FILE}
                        -DEXPECTED=${TEST_OUTPUT_FILE}
                        -P ${PROJECT_SOURCE_DIR}/cmake/run_test.cmake
                )
            endif()

            set_tests_properties(
                cses.${PROBLEM_NAME}
                PROPERTIES
                    LABELS "cses;${PROBLEM_NAME}"
            )
        else()
            message(STATUS "Skipping test cses.${PROBLEM_NAME}: missing test_input.txt or test_output.txt")
        endif()
    endif()
endforeach()
