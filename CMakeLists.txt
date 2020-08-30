cmake_minimum_required(VERSION 3.10.2)
project(tic_tac_toe)

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_executable ( 
  ticTacToe
  src/main.cpp 
  src/tic_tac_toe.cpp)

add_subdirectory(lib/googletest)
add_subdirectory(test)