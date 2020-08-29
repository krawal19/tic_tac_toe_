cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11")

project(tic_tac_toe)

include_directories(include)

add_executable ( 
  ticTacToe
  src/main.cpp 
  src/tic_tac_toe.cpp)
