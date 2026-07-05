get_filename_component(
    PROBLEM_NAME
    ${CMAKE_CURRENT_SOURCE_DIR}
    NAME
)

add_executable(
    ${PROBLEM_NAME}
    main.cpp
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
