cmake_minimum_required(VERSION 3.0)
project(lab_1 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp matrix/matrix.cpp)
set(HEADERS matrix/matrix.h)

add_executable(${PROJECT_NAME} ${SOURCES})