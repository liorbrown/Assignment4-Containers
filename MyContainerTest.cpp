// liorbrown@outlook.co.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.hpp"
#include "MyContainer.hpp"

using namespace Containers;

void initContainer(MyContainer<>& container)
{
    container.add(5);
    container.add(3);
    container.add(-7);
    container.add(10);
    container.add(3);
    container.add(6);
}

TEST_SUITE("Container testing")
{
    TEST_CASE("Init container and size test")
    {
        MyContainer container;

        // Check empty container size
        CHECK_FALSE(container.size());

        // Init container - this method checks add() method
        initContainer(container);              

        // Check full container size
        CHECK_EQ(6, container.size());
    }

    TEST_CASE("Remove test")
    {
        MyContainer container;

        // Check remove from empty container
        CHECK_THROWS_AS(container.remove(3), invalid_argument);

        initContainer(container);

        // Check remove for item that not in the container
        CHECK_THROWS_AS(container.remove(4), invalid_argument);

        container.remove(10);

        // Check remove of unique item 
        CHECK_EQ(5, container.size());

        container.remove(3);

        // Check remove of item exist twice
        CHECK_EQ(3, container.size());
    }
}

TEST_SUITE("Iterators testing")
{
    TEST_CASE("Ascending iterator")
    {
        MyContainer container;

        for
        (
            auto item = container.ascendingBegin();
            item != container.ascendingEnd();
            ++item
        ) 
            CHECK(false);

        initContainer(container);

        int arr[]{-7,3,3,5,6,10};
        size_t i = 0;

        for
        (
            auto item = container.ascendingBegin();
            item != container.ascendingEnd();
            ++item
        )
            CHECK_EQ(*item, arr[i++]);
        
        auto item = container.ascendingBegin();

        CHECK_EQ(*item, -7);
        CHECK_EQ(*++item, 3);
        CHECK_EQ(*item++, 3);
        CHECK_EQ(*item, 3);
    }

    TEST_CASE("Descending iterator")
    {
        MyContainer container;

        for
        (
            auto item = container.descendingBegin();
            item != container.descendingEnd();
            ++item
        ) 
            CHECK(false);

        initContainer(container);

        int arr[]{10,6,5,3,3,-7};
        size_t i = 0;

        for
        (
            auto item = container.descendingBegin();
            item != container.descendingEnd();
            ++item
        )
            CHECK_EQ(*item, arr[i++]);
        
        auto item = container.descendingBegin();

        CHECK_EQ(*item, 10);
        CHECK_EQ(*++item, 6);
        CHECK_EQ(*item++, 6);
        CHECK_EQ(*item, 5);
    }

    TEST_CASE("SideCross iterator")
    {
        MyContainer container;

        for
        (
            auto item = container.SideCrossBegin();
            item != container.SideCrossEnd();
            ++item
        ) 
            CHECK(false);

        initContainer(container);

        int arrEven[]{-7,10,3,6,3,5};
        size_t i = 0;

        for
        (
            auto item = container.SideCrossBegin();
            item != container.SideCrossEnd();
            ++item
        )
            CHECK_EQ(*item, arrEven[i++]);
        
        container.remove(6);

        int arrOdd[]{-7,10,3,5,3};
        i = 0;

        for
        (
            auto item = container.SideCrossBegin();
            item != container.SideCrossEnd();
            ++item
        )
            CHECK_EQ(*item, arrOdd[i++]);

        auto item = container.SideCrossBegin();

        CHECK_EQ(*item, -7);
        CHECK_EQ(*++item, 10);
        CHECK_EQ(*item++, 10);
        CHECK_EQ(*item, 3);
    }

    TEST_CASE("Reverse iterator")
    {
        MyContainer container;

        for
        (
            auto item = container.crbegin();
            item != container.crend();
            ++item
        ) 
            CHECK(false);

        initContainer(container);

        int arr[]{6,3,10,-7,3,5};
        size_t i = 0;

        for
        (
            auto item = container.crbegin();
            item != container.crend();
            ++item
        )
            CHECK_EQ(*item, arr[i++]);
        
        auto item = container.crbegin();

        CHECK_EQ(*item, 6);
        CHECK_EQ(*++item, 3);
        CHECK_EQ(*item++, 3);
        CHECK_EQ(*item, 10);
    }

    TEST_CASE("Order iterator")
    {
        MyContainer container;

        for
        (
            auto item = container.cbegin();
            item != container.cend();
            ++item
        ) 
            CHECK(false);

        initContainer(container);

        int arr[]{5,3,-7,10,3,6};
        size_t i = 0;

        for
        (
            auto item = container.cbegin();
            item != container.cend();
            ++item
        )
            CHECK_EQ(*item, arr[i++]);
        
        auto item = container.cbegin();

        CHECK_EQ(*item, 5);
        CHECK_EQ(*++item, 3);
        CHECK_EQ(*item++, 3);
        CHECK_EQ(*item, -7);
    }

    TEST_CASE("MiddleOut iterator")
    {
        MyContainer container;

        for
        (
            auto item = container.MiddleOutBegin();
            item != container.MiddleOutEnd();
            ++item
        ) 
            CHECK(false);

        initContainer(container);

        int arrEven[]{10,-7,3,3,6,5};
        size_t i = 0;

        for
        (
            auto item = container.MiddleOutBegin();
            item != container.MiddleOutEnd();
            ++item
        )
            CHECK_EQ(*item, arrEven[i++]);
        
        container.remove(6);

        int arrOdd[]{-7,3,10,5,3};
        i = 0;

        for
        (
            auto item = container.MiddleOutBegin();
            item != container.MiddleOutEnd();
            ++item
        )
            CHECK_EQ(*item, arrOdd[i++]);       
        
        auto item = container.MiddleOutBegin();

        CHECK_EQ(*item, -7);
        CHECK_EQ(*++item, 3);
        CHECK_EQ(*item++, 3);
        CHECK_EQ(*item, 10);
    }
}