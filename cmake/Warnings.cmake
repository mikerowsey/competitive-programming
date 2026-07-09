add_library(cp_project_warnings INTERFACE)
target_compile_options(
    cp_project_warnings
    INTERFACE
        -Wall
        -Wextra
        -Wpedantic
)
