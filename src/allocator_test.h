// allocator_test.h
#ifndef ALLOCATORTEST_H
#define ALLOCATORTEST_H

#include "engine/memory/counting_allocator.h"
#include "gtest/gtest.h"

namespace StevensDev
{

namespace sgdt
{

class AllocatorTest : public ::testing::Test
{
  public:

    // CONSTRUCTOR
    AllocatorTest();

    // TESTING SETUP
    virtual void SetUp();

    virtual void TearDown();
};

TEST( AllocationTest, get)
{
    StevensDev::sgdm::CountingAllocator<int> testCountingAllocator;
    int* testPointer = testCountingAllocator.get( 5 );
    EXPECT_EQ( 5, testCountingAllocator.getAllocationCount() );
    testCountingAllocator.release( testPointer, 5 );
    EXPECT_EQ( 5, testCountingAllocator.getReleaseCount() );
}

TEST( TotalAllocationTest, get)
{
    StevensDev::sgdm::CountingAllocator<int> testCountingAllocator;
    int* testPointer = testCountingAllocator.get( 4 );
    EXPECT_EQ( 9, testCountingAllocator.getTotalAllocationCount() );
    testCountingAllocator.release( testPointer, 4 );
    EXPECT_EQ( 9, testCountingAllocator.getTotalReleaseCount() );
}

TEST( ReleaseToZeroTest, get)
{
    StevensDev::sgdm::CountingAllocator<int> testCountingAllocator;
    int* testPointer = testCountingAllocator.get( 5 );
    EXPECT_EQ( 5, testCountingAllocator.getAllocationCount() );
    testCountingAllocator.release( testPointer, 5 );
    EXPECT_EQ( 5, testCountingAllocator.getReleaseCount() );
}

TEST( AssignmentOperator, assignment )
{
    StevensDev::sgdm::CountingAllocator<int> testCountingAllocator;
    StevensDev::sgdm::CountingAllocator<int> testCountingAllocator2;
    int* testPointer = testCountingAllocator.get( 5 );
    testCountingAllocator.release( testPointer, 5 );
    testCountingAllocator2 = testCountingAllocator;
    EXPECT_EQ( 5, testCountingAllocator2.getAllocationCount() );
}

}  // End namespace sgdt

}  // End namespace StevensDev

#endif // ALLOCATORTEST_H
