cmake_minimum_required(VERSION 3.18)
project(OGLInfoProj)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

# Including GLAD
add_subdirectory(lib/glfw)
add_subdirectory(test/Google_tests/lib/googletest)
include_directories(include)
include_directories(src)




set(
        SOURCE_FILES
        src/glad.c
        src/tutorial/hello_triangle/hello_triangle.cpp
        src/tutorial/hello_triangle/hello_triangle.h
        src/helpers/helpers.cpp src/helpers/helpers.h
        src/gl/gl_helpers.cpp
        src/gl/gl_helpers.h
        main.cpp
        src/gl/exceptions/glException.h src/gl/exceptions/glShaderCompileException.cpp test/Google_tests/unit_tests/gl/exceptions/glShaderCompileExceptionTest.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
# Linking Gtest


# got it working with the help of:
# https://stackoverflow.com/questions/48077769/c-how-to-run-programs-in-clion-when-you-need-to-include-opengl-libraries
# https://www.glfw.org/docs/3.0/build.html