// main_test_all.cpp
#include <gtest/gtest.h>
#include "allocator_test.h"
#include "dynamic_array_test.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}

