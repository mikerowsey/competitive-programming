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

option(CP_ENABLE_SANITIZERS "Enable address+undefined sanitizers" OFF)
option(CP_ENABLE_THREAD_SANITIZER "Enable thread sanitizer" OFF)

if(CP_ENABLE_SANITIZERS AND CP_ENABLE_THREAD_SANITIZER)
    message(FATAL_ERROR "CP_ENABLE_SANITIZERS and CP_ENABLE_THREAD_SANITIZER cannot both be ON")
endif()

if(CP_ENABLE_SANITIZERS)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
    else()
        message(WARNING "Sanitizers requested, but compiler '${CMAKE_CXX_COMPILER_ID}' is not supported")
    endif()
endif()

if(CP_ENABLE_THREAD_SANITIZER)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        add_compile_options(-fsanitize=thread -fno-omit-frame-pointer)
        add_link_options(-fsanitize=thread)
    else()
        message(WARNING "ThreadSanitizer requested, but compiler '${CMAKE_CXX_COMPILER_ID}' is not supported")
    endif()
endif()

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
