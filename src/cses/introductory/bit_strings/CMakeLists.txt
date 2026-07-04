get_filename_component(
    PROBLEM_NAME
    ${CMAKE_CURRENT_SOURCE_DIR}
    NAME
)
add_executable(
    ${PROBLEM_NAME}
    main.cpp
)

target_include_directories(
    ${PROBLEM_NAME}    
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROBLEM_NAME}
    PRIVATE
        project_options
)
