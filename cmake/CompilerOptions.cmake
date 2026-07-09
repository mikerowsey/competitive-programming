add_library(cp_project_options INTERFACE)
target_compile_features(cp_project_options INTERFACE cxx_std_23)
set_target_properties(cp_project_options PROPERTIES CXX_EXTENSIONS OFF)

# Generate compile_commands.json for clangd.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Keep compile_commands.json in the project root so clangd always finds it.
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${PROJECT_SOURCE_DIR}/compile_commands.json
    )
endif()
