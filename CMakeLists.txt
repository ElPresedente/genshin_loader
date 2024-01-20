cmake_minimum_required(VERSION 3.27)
project(genshin_loader)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(/bigobj)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(genshin_loader main.cpp)
