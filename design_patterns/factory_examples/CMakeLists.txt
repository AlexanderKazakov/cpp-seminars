cmake_minimum_required(VERSION 3.8)
project(factory_examples)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE basic_src "basic/*")
add_executable(basic ${basic_src})

file(GLOB_RECURSE with_map_src "with_map/*")
add_executable(with_map ${with_map_src})

file(GLOB_RECURSE with_static_map_initialization_src "with_static_map_initialization/*")
add_executable(with_static_map_initialization ${with_static_map_initialization_src})
