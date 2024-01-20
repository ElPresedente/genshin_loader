cmake_minimum_required(VERSION 3.27)
project(genshin_loader)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(/bigobj)

add_subdirectory(tiny-process-library)

include_directories(${CMAKE_SOURCE_DIR}/json/include
        ${CMAKE_SOURCE_DIR}/PEGTL/include
        ${CMAKE_SOURCE_DIR}/config/include
)

add_executable(genshin_loader main.cpp icon.rc)
target_link_libraries(genshin_loader tiny-process-library)
