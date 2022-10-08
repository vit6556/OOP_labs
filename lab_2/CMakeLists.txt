cmake_minimum_required(VERSION 3.0)
project(lab_2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp tractrix/tractrix.cpp)
set(HEADERS tractrix/tractrix.h)

add_executable(${PROJECT_NAME} ${SOURCES})