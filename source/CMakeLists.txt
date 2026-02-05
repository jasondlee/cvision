# Collect all source files
file(GLOB CVISION_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Create the cvision library
add_library(cvision ${CVISION_SOURCES})

# Set include directories for the library
target_include_directories(cvision
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link against tvision
target_link_libraries(cvision
    PUBLIC
        tvision
)

# Set library properties
set_target_properties(cvision PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${CMAKE_SOURCE_DIR}/include/cvision/cvision.h"
)
