cmake_minimum_required(VERSION 3.22)
project(SBExercise3152)

set(CMAKE_CXX_STANDARD 14)

add_executable(SBExercise3152 src/main.cpp include/IGraph.h include/ListIGraph.h src/ListIGraph.cpp include/MatrixIGraph.h src/MatrixIGraph.cpp)

target_include_directories(SBExercise3152 PUBLIC include)
