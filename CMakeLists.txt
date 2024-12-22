cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

set(CMAKE_C_COMPILER "/usr/bin/clang-13")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-13")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(
    -Werror
    -Wall
)
project(wordle_task)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Gui Widgets REQUIRED)
add_executable(${CMAKE_PROJECT_NAME} main.cxx GameState.cxx GameState.h WidgetButtons.cxx WidgetButtons.h WidgetKeyboard.cxx WidgetButtons.h WidgetGame.h WidgetGame.cxx)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Gui Qt5::Widgets stdc++fs)

