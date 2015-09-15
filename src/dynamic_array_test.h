// dynamic_array_test.h
#ifndef DYNAMICARRAYTEST_H
#define DYNAMICARRAYTEST_H

#include "gtest/gtest.h"
#include "engine/containers/dynamic_array.h"

class DynamicArrayTest : public ::testing::Test
{
  public:

    DynamicArrayTest();

    virtual void SetUp();

    virtual void TearDown();
};

TEST( ArrayPushTest, basicPush )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->push( 5 );
    testDynamicArray->push( 3 );
    EXPECT_EQ( 5, testDynamicArray->at( 0 ) );
    EXPECT_EQ( 3, testDynamicArray->at( 1 ) );
    delete testDynamicArray;
}

TEST( ArrayPushTest, pushToReallocate )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->push( 5 );
    testDynamicArray->push( 3 );
    testDynamicArray->push( 4 );
    testDynamicArray->push( 2 );
    testDynamicArray->push( 1 );
    testDynamicArray->push( 7 );
    EXPECT_EQ( 10, testDynamicArray->getCapacity() );
    EXPECT_EQ( 7, testDynamicArray->at( 5 ) );
    EXPECT_EQ( 5, testDynamicArray->at( 0 ) );
    delete testDynamicArray;
}

TEST( ArrayPushTest, pushFront )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->pushFront( 1 );
    EXPECT_EQ( 1, testDynamicArray->at( 0 ) );
    testDynamicArray->pushFront( 6 );
    EXPECT_EQ( 6, testDynamicArray->at( 0 ) );
    delete testDynamicArray;
}

TEST( ArrayPopTest, basicPop )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->pushFront( 1 );
    testDynamicArray->pushFront( 6 );
    EXPECT_EQ( 1, testDynamicArray->pop() );
    EXPECT_EQ( 6, testDynamicArray->pop() );
    delete testDynamicArray;
}

TEST( ArrayPopTest, popFront )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->pushFront( 1 );
    testDynamicArray->pushFront( 6 );
    EXPECT_EQ( 6, testDynamicArray->popFront() );
    EXPECT_EQ( 1, testDynamicArray->popFront() );
    delete testDynamicArray;
}

TEST( ArrayRemoveTest, removeAtBasic )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->pushFront( 1 );
    testDynamicArray->pushFront( 6 );
    testDynamicArray->push( 7 );
    EXPECT_EQ( 1, testDynamicArray->removeAt( 1 ) );
    EXPECT_EQ( 7, testDynamicArray->at( 1 ) );
    delete testDynamicArray;
}

TEST( ArrayRemoveTest, removeAtLength )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->pushFront( 1 );
    testDynamicArray->pushFront( 6 );
    testDynamicArray->push( 7 );
    EXPECT_EQ( 7, testDynamicArray->removeAt( 2 ) );
    EXPECT_EQ( 1, testDynamicArray->at( 1 ) );
    delete testDynamicArray;
}

TEST( ArrayRemoveTest, removeOutOfBounds )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    EXPECT_ANY_THROW( testDynamicArray->removeAt( 5 ) );
    EXPECT_ANY_THROW( testDynamicArray->removeAt( -1 ) );
    delete testDynamicArray;
}

TEST( ArrayInsertTest, insertAtBasic )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->insertAt( 10, 0 );
    testDynamicArray->insertAt( 9, 2 );
    testDynamicArray->insertAt( 8, 4 );
    EXPECT_EQ( 10, testDynamicArray->at( 0 ) );
    EXPECT_EQ( 9, testDynamicArray->at( 2 ) );
    EXPECT_EQ( 8, testDynamicArray->at( 4 ) );
    delete testDynamicArray;
}

TEST( ArrayInsertTest, insertAtPopulatedArray )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray->pushFront( 1 );
    testDynamicArray->pushFront( 6 );
    testDynamicArray->push( 7 );
    testDynamicArray->insertAt( 2, 1 );
    EXPECT_EQ( 2, testDynamicArray->at( 1 ) );
    EXPECT_EQ( 7, testDynamicArray->at( 3 ) );
    delete testDynamicArray;
}

TEST( ArrayInsertTest, insertOutOfBounds )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    EXPECT_ANY_THROW( testDynamicArray->insertAt( 1, 5 ) );
    EXPECT_ANY_THROW( testDynamicArray->insertAt( 1, -1 ) );
    delete testDynamicArray;
}

TEST( AtExceptionTest, atOutOfBounds )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    EXPECT_ANY_THROW( testDynamicArray->at( 5 ) );
    EXPECT_ANY_THROW( testDynamicArray->at( -1 ) );
    delete testDynamicArray;
}

TEST( operatorOverload, assignmentOperator )
{
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray;
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray2 =
        new StevensDev::sgdc::DynamicArray<int>(
        new StevensDev::sgdm::CountingAllocator<int> );
    testDynamicArray2->push( 15 );
    testDynamicArray2->push( 21 );
    testDynamicArray = testDynamicArray2;
    EXPECT_EQ( 15, testDynamicArray->at( 0 ) );
    EXPECT_EQ( 21, testDynamicArray->at( 1 ) );
    delete testDynamicArray;
}

TEST( memoryUsage, memoryLeakOnReallocation )
{
    StevensDev::sgdm::CountingAllocator<int>* testCountingAllocator =
        new StevensDev::sgdm::CountingAllocator<int>();
    StevensDev::sgdc::DynamicArray<int>* testDynamicArray =
        new StevensDev::sgdc::DynamicArray<int>(
        testCountingAllocator );
    testDynamicArray->push( 5 );
    testDynamicArray->push( 3 );
    testDynamicArray->push( 4 );
    testDynamicArray->push( 2 );
    testDynamicArray->push( 1 );
    testDynamicArray->push( 7 );
    EXPECT_EQ( 10, testCountingAllocator->getOutstandingCount() );
    delete testDynamicArray;
}

TEST( memoryUsage, memoryLeakOutstanding )
{
    StevensDev::sgdm::CountingAllocator<int>* testCountingAllocator =
        new StevensDev::sgdm::CountingAllocator<int>();
    EXPECT_EQ( 0, testCountingAllocator->getTotalOutstandingCount() );
}


#endif // DYNAMICARRAYTEST_H
