cmake_minimum_required(VERSION 3.27)
project(genshin_loader)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(/bigobj)

add_subdirectory(tiny-process-library)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(genshin_loader main.cpp)
target_link_libraries(genshin_loader tiny-process-library)
