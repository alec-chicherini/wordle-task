cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

#CMake
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(
    -Werror
    -Wall
)
project(http-server)

message(INFO "CMAKE_CXX_COMPILE_FEATURES = ${CMAKE_CXX_COMPILE_FEATURES}")
message(INFO "CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")

find_package(userver REQUIRED COMPONENTS core)

# The Service
set(SOURCE_FILES__ main.cpp http_handler_subdomain_static.cpp http_handler_subdomain_static.hpp )
list(TRANSFORM SOURCE_FILES__ PREPEND "src/")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES__})
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} userver::core)

# Unit Tests
#add_executable(${PROJECT_NAME}_unittest
#    src/hello_test.cpp
#)
#target_link_libraries(${PROJECT_NAME}_unittest PRIVATE ${PROJECT_NAME}_objs userver::utest)
#add_google_tests(${PROJECT_NAME}_unittest)

# Benchmarks
#add_executable(${PROJECT_NAME}_benchmark
#    src/hello_benchmark.cpp
#)
#target_link_libraries(${PROJECT_NAME}_benchmark PRIVATE ${PROJECT_NAME}_objs userver::ubench)
#add_google_benchmark_tests(${PROJECT_NAME}_benchmark)
