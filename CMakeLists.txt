cmake_minimum_required(VERSION 3.25)

project(
    competitive_programming
    VERSION 0.1.0
    DESCRIPTION "Competitive Programming Workshop"
    LANGUAGES CXX
)

include(cmake/CompilerOptions.cmake)
include(cmake/Warnings.cmake)
include(cmake/Sanitizers.cmake)
include(cmake/ClangTidy.cmake)
include(cmake/Testing.cmake)

add_subdirectory(src)
