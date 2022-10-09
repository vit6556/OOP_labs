cmake_minimum_required(VERSION 3.0)
project(lab_2 VERSION 1.0.0 LANGUAGES CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(libraries)
add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE tractrix)
target_link_libraries(${PROJECT_NAME} PRIVATE menu)
