project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_tests_run
        unit_tests/gl/exceptions/glShaderCompileExceptionTest.cpp
)