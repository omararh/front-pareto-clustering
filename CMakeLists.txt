cmake_minimum_required(VERSION 3.5)

project(code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code main.cpp solver.cpp solverInterval.cpp solverDP.cpp mediansDP.cpp)
