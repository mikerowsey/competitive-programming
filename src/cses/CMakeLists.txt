file(GLOB PROBLEM_DIRS CONFIGURE_DEPENDS *)

foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    if(IS_DIRECTORY "${PROBLEM_DIR}")
        get_filename_component(PROBLEM_NAME "${PROBLEM_DIR}" NAME)

        add_executable(
            ${PROBLEM_NAME}
            "${PROBLEM_DIR}/main.cpp"
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

        add_test(
            NAME cses.${PROBLEM_NAME}
            COMMAND
                ${CMAKE_COMMAND}
                -DPROGRAM=$<TARGET_FILE:${PROBLEM_NAME}>
                -DINPUT=${PROBLEM_DIR}/test_input.txt
                -DEXPECTED=${PROBLEM_DIR}/test_output.txt
                -P ${PROJECT_SOURCE_DIR}/cmake/run_test.cmake
        )
    endif()
endforeach()
