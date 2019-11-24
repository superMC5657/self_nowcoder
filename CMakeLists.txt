cmake_minimum_required(VERSION 3.14)
project(self_nowcoder)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(forOffer src/forOffer/0000_main.cpp)
add_executable(forJob src/forJob/0_main.cpp)
add_executable(insterest src/insterest/0000_main.cpp)