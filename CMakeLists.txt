cmake_minimum_required(VERSION 2.8.12)
project(regime_cpp)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCE_FILES "src/*cpp")

add_library(regime ${SOURCE_FILES})
target_link_libraries(regime ${CONAN_LIBS})
