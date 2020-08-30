set(GTEST_SHUFFLE 1)

include_directories(include)

add_executable(
    ticTacToeTest
    main.cpp
    tic_tac_toe_test.cpp
    ../src/tic_tac_toe.cpp
)

target_include_directories(ticTacToeTest PUBLIC ../lib/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ticTacToeTest PUBLIC gtest)
