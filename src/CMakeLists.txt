cmake_minimum_required(VERSION 2.8)
project( test )

add_subdirectory(gtest-1.7.0)

enable_testing()

find_package ( Threads )
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable( assign_1 game.m.cpp )
add_executable( assign_1_test main_test_all.cpp )

target_link_libraries( assign_1_test gtest gtest_main )
target_link_libraries( assign_1_test ${CMAKE_THREAD_LIBS_INIT} )

add_test(NAME unit_test COMMAND assign_1_test)

