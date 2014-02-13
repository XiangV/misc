project(misc)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS -g)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
include_directories(algorithm/heapSort)
add_subdirectory(algorithm/heapSort)
