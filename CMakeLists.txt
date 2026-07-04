cmake_minimum_required(VERSION 3.25)

project(
    competitive_programming
    VERSION 0.1.0
    DESCRIPTION "Competitive Programming Workshop"
    LANGUAGES CXX
)

# ---------------------------------------------------------------------------
# Tooling
# ---------------------------------------------------------------------------

# Keep compile_commands.json in the project root so clangd and other tools
# can find it regardless of the active build directory.
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${PROJECT_SOURCE_DIR}/compile_commands.json
    )
endif()

# ---------------------------------------------------------------------------
# Global language settings
# ---------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---------------------------------------------------------------------------
# Common project options
# ---------------------------------------------------------------------------

# Interface target used to propagate common compile settings
# to every executable in the project.
add_library(project_options INTERFACE)

target_compile_features(project_options
    INTERFACE
        cxx_std_23
)

target_compile_options(project_options
    INTERFACE
        -Wall
        -Wextra
        -Wpedantic
)

# ---------------------------------------------------------------------------
# Project layout
# ---------------------------------------------------------------------------

add_subdirectory(src)
