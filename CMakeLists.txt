cmake_minimum_required(VERSION 3.27)

set(VCPKG_ROOT "D:/vcpkg")

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(genshin_loader)

set(CMAKE_CXX_STANDARD 20)

find_package(tiny-process-library CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
PKG_CHECK_MODULES(GTKMM gtkmm-4.0)
include_directories(${GTK4_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

link_directories(${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/lib ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/debug/lib)

add_executable(genshin_loader main.cc icon.rc
        main_window.cpp
        main_window.hpp
        config.cpp
        config.hpp)
target_link_libraries(genshin_loader PRIVATE
        tiny-process-library::tiny-process-library
        JsonCpp::JsonCpp
        ${GTK4_LIBRARIES}
        ${GTKMM_LIBRARIES}
)
