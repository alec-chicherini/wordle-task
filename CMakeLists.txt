cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

set(CMAKE_C_COMPILER "/usr/bin/clang-13")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-13")
set(CMAKE_CXX_STANDARD 20)
add_compile_options(
    -Werror
    -Wall
)
project(wordle_task)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Gui Widgets REQUIRED)
add_executable(${CMAKE_PROJECT_NAME} main.cxx)
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Gui Qt5::Widgets)
