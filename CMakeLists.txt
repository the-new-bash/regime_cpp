#=============================
# Library
#=============================
cmake_minimum_required(VERSION 3.13)
project(regime LANGUAGES C CXX)

if (NOT EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    message(FATAL_ERROR "Dependencies need to be installed: conan install <conanfile.py path>")
endif ()

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(regime STATIC src/regime.cpp src/v1/errors.cpp src/v1/responses.cpp src/v1/types.cpp test/v1/round.cpp test/v1/types.hpp test/v1/responses.hpp test/v1/requests.hpp src/v1/requests.cpp include/v1/objects.hpp src/v1/objects.cpp)
include_directories(include)
target_link_libraries(regime PRIVATE ${CONAN_LIBS})
target_compile_options(regime PUBLIC -O0 --coverage)
target_link_options(regime PUBLIC --coverage)

#=============================
# Unit Testing
#=============================
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_TARGET ${PROJECT_NAME}_test)
add_executable(${TEST_TARGET} test/v1/round.cpp test/v1/helpers.hpp test/v1/helpers.cpp)
target_link_libraries(${TEST_TARGET} GTest::GTest GTest::Main)
target_link_libraries(${TEST_TARGET} regime)
gtest_discover_tests(${TEST_TARGET})

#=============================
# Coverage
#=============================
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/${TEST_TARGET}.dir/test/v1)
add_custom_target(
        gcov
        COMMAND mkdir -p ${PROJECT_SOURCE_DIR}/coverage
        COMMAND ${CMAKE_MAKE_PROGRAM} test
        COMMAND find -iname '*.gcno' -exec cp {} ${PROJECT_SOURCE_DIR}/coverage "\;"
        COMMAND find -iname '*.gcda' -exec cp {} ${PROJECT_SOURCE_DIR}/coverage "\;"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
add_custom_command(
        TARGET gcov
        COMMAND find ${PROJECT_SOURCE_DIR}/src -iname '*.cpp' -exec gcov -bf {} -o . "\;"
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/coverage
)
