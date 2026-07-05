cmake_minimum_required(VERSION 3.25)

project(
    competitive_programming
    VERSION 0.1.0
    DESCRIPTION "Competitive Programming Workshop"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Keep compile_commands.json in the project root so clangd always finds it.
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${PROJECT_SOURCE_DIR}/compile_commands.json
    )
endif()

include(CTest)
add_subdirectory(src)
