# Create the example executable
add_executable(cvision_example
    cvision_example.c
)

# Link against the cvision library
target_link_libraries(cvision_example
    PRIVATE
        cvision
        tvision
)

# Include directories for the example
target_include_directories(cvision_example
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}
)
