cmake_minimum_required(VERSION 3.18)
project(OGLInfoProj)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

# Including GLAD
add_subdirectory(glfw)
include_directories(include)

set(SOURCE_FILES main.cpp src/glad.c)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})

# got it working with the help of:
# https://stackoverflow.com/questions/48077769/c-how-to-run-programs-in-clion-when-you-need-to-include-opengl-libraries
# https://www.glfw.org/docs/3.0/build.html