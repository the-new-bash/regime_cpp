cmake_minimum_required(VERSION 2.8.12)
project(regime_cpp)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(regime src/regime.cpp include/regime.h)
target_link_libraries(regime ${CONAN_LIBS})
