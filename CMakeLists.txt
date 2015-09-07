cmake_minimum_required(VERSION 2.8)
project( test )

find_package ( Threads )
include_directories( gtest/include )
link_directories( build )
add_executable( assign_1 game.m.cpp )

add_executable( assign_1_test main_test_all.cpp )
target_link_libraries( assign_1_test gtest gtest_main )
target_link_libraries( assign_1_test ${CMAKE_THREAD_LIBS_INIT} )

