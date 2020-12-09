cmake_minimum_required(VERSION 3.16)
project(OGLhangman)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/glfw)
include_directories(include)
add_subdirectory(test/Google_tests)
include_directories(src)

set(SOURCE_FILES
        main.cpp
        src/glad.c
        src/helpers.cpp
        src/glBoilerplateAndHelpers/sprite.cpp
        src/glBoilerplateAndHelpers/sprite.h
        src/glBoilerplateAndHelpers/texture.cpp
        src/glBoilerplateAndHelpers/texture.h
        src/chessSpriteHandler.cpp
        src/chessSpriteHandler.h
        src/input.cpp
        src/input.h
        src/uiElements.cpp src/uiElements.h)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(Google_Tests_run PRIVATE src)

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})

set(WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/src)

file(COPY src/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY chess-sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY glow.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR})