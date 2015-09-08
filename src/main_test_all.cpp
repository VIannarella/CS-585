// main_test_all.cpp
#include <gtest/gtest.h>
#include "src/add.h"
#include "src/subtract.h"

TEST( testAdd, addTwoNumbers )
{
    StevensDev::Add a;
    EXPECT_EQ( 8, a.addElements( 3, 5 ) );
}

TEST( testSubtract, subtractTwoNumbers )
{
    StevensDev::Subtract s;
    EXPECT_EQ( 5, s.subtractElements( 8, 3 ) );
}

TEST( testSubtract2, subtractToNegative )
{
    StevensDev::Subtract s;
    EXPECT_EQ( -1, s.subtractElements( 8, 9 ) );
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}

