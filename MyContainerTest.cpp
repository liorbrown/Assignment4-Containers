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

void initContainer(MyContainer<double>& container)
{
    container.add(5.1);
    container.add(3.2);
    container.add(-7.7);
    container.add(10.4);
    container.add(3.2);
    container.add(6.8);
}

void initContainer(MyContainer<string>& container)
{
    container.add("Charls");
    container.add("Bob");
    container.add("Alice");
    container.add("Eli");
    container.add("Bob");
    container.add("Dan");
}

TEST_SUITE("Integers containers")
{
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
}

TEST_SUITE("Double container")
{
    TEST_SUITE("Container testing")
    {
        TEST_CASE("Init container and size test")
        {
            MyContainer<double> container;

            // Check empty container size
            CHECK_FALSE(container.size());

            // Init container - this method checks add() method
            initContainer(container);              

            // Check full container size
            CHECK_EQ(6, container.size());
        }

        TEST_CASE("Remove test")
        {
            MyContainer<double> container;

            // Check remove from empty container
            CHECK_THROWS_AS(container.remove(3.2), invalid_argument);

            initContainer(container);

            // Check remove for item that not in the container
            CHECK_THROWS_AS(container.remove(4), invalid_argument);

            container.remove(10.4);

            // Check remove of unique item 
            CHECK_EQ(5, container.size());

            container.remove(3.2);

            // Check remove of item exist twice
            CHECK_EQ(3, container.size());
        }
    }

    TEST_SUITE("Iterators testing")
    {
        TEST_CASE("Ascending iterator")
        {
            MyContainer<double> container;

            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            double arr[]{-7.7,3.2,3.2,5.1,6.8,10.4};
            size_t i = 0;

            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.ascendingBegin();

            CHECK_EQ(*item, -7.7);
            CHECK_EQ(*++item, 3.2);
            CHECK_EQ(*item++, 3.2);
            CHECK_EQ(*item, 3.2);
        }

        TEST_CASE("Descending iterator")
        {
            MyContainer<double> container;

            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            double arr[]{10.4,6.8,5.1,3.2,3.2,-7.7};
            size_t i = 0;

            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.descendingBegin();

            CHECK_EQ(*item, 10.4);
            CHECK_EQ(*++item, 6.8);
            CHECK_EQ(*item++, 6.8);
            CHECK_EQ(*item, 5.1);
        }

        TEST_CASE("SideCross iterator")
        {
            MyContainer<double> container;

            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            double arrEven[]{-7.7,10.4,3.2,6.8,3.2,5.1};
            size_t i = 0;

            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove(6.8);

            double arrOdd[]{-7.7,10.4,3.2,5.1,3.2};
            i = 0;

            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                CHECK_EQ(*item, arrOdd[i++]);

            auto item = container.SideCrossBegin();

            CHECK_EQ(*item, -7.7);
            CHECK_EQ(*++item, 10.4);
            CHECK_EQ(*item++, 10.4);
            CHECK_EQ(*item, 3.2);
        }

        TEST_CASE("Reverse iterator")
        {
            MyContainer<double> container;

            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            double arr[]{6.8,3.2,10.4,-7.7,3.2,5.1};
            size_t i = 0;

            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.crbegin();

            CHECK_EQ(*item, 6.8);
            CHECK_EQ(*++item, 3.2);
            CHECK_EQ(*item++, 3.2);
            CHECK_EQ(*item, 10.4);
        }

        TEST_CASE("Order iterator")
        {
            MyContainer<double> container;

            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            double arr[]{5.1,3.2,-7.7,10.4,3.2,6.8};
            size_t i = 0;

            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.cbegin();

            CHECK_EQ(*item, 5.1);
            CHECK_EQ(*++item, 3.2);
            CHECK_EQ(*item++, 3.2);
            CHECK_EQ(*item, -7.7);
        }

        TEST_CASE("MiddleOut iterator")
        {
            MyContainer<double> container;

            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            double arrEven[]{10.4,-7.7,3.2,3.2,6.8,5.1};
            size_t i = 0;

            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove(6.8);

            double arrOdd[]{-7.7,3.2,10.4,5.1,3.2};
            i = 0;

            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                CHECK_EQ(*item, arrOdd[i++]);       
            
            auto item = container.MiddleOutBegin();

            CHECK_EQ(*item, -7.7);
            CHECK_EQ(*++item, 3.2);
            CHECK_EQ(*item++, 3.2);
            CHECK_EQ(*item, 10.4);
        }
    }
}

TEST_SUITE("String container")
{
    TEST_SUITE("Container testing")
    {
        TEST_CASE("Init container and size test")
        {
            MyContainer<string> container;

            // Check empty container size
            CHECK_FALSE(container.size());

            // Init container - this method checks add() method
            initContainer(container);              

            // Check full container size
            CHECK_EQ(6, container.size());
        }

        TEST_CASE("Remove test")
        {
            MyContainer<string> container;

            // Check remove from empty container
            CHECK_THROWS_AS(container.remove("Bob"), invalid_argument);

            initContainer(container);

            // Check remove for item that not in the container
            CHECK_THROWS_AS(container.remove("Lior"), invalid_argument);

            container.remove("Eli");

            // Check remove of unique item 
            CHECK_EQ(5, container.size());

            container.remove("Bob");

            // Check remove of item exist twice
            CHECK_EQ(3, container.size());
        }
    }

    TEST_SUITE("Iterators testing")
    {
        TEST_CASE("Ascending iterator")
        {
            MyContainer<string> container;

            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            string arr[]{"Alice","Bob","Bob","Charls","Dan","Eli"};
            size_t i = 0;

            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.ascendingBegin();

            CHECK_EQ(*item, "Alice");
            CHECK_EQ(*++item, "Bob");
            CHECK_EQ(*item++, "Bob");
            CHECK_EQ(*item, "Bob");
        }

        TEST_CASE("Descending iterator")
        {
            MyContainer<string> container;

            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            string arr[]{"Eli","Dan","Charls","Bob","Bob","Alice"};
            size_t i = 0;

            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.descendingBegin();

            CHECK_EQ(*item, "Eli");
            CHECK_EQ(*++item, "Dan");
            CHECK_EQ(*item++, "Dan");
            CHECK_EQ(*item, "Charls");
        }

        TEST_CASE("SideCross iterator")
        {
            MyContainer<string> container;

            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            string arrEven[]{"Alice","Eli","Bob","Dan","Bob","Charls"};
            size_t i = 0;

            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove("Dan");

            string arrOdd[]{"Alice","Eli","Bob","Charls","Bob"};
            i = 0;

            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                CHECK_EQ(*item, arrOdd[i++]);

            auto item = container.SideCrossBegin();

            CHECK_EQ(*item, "Alice");
            CHECK_EQ(*++item, "Eli");
            CHECK_EQ(*item++, "Eli");
            CHECK_EQ(*item, "Bob");
        }

        TEST_CASE("Reverse iterator")
        {
            MyContainer<string> container;

            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            string arr[]{"Dan","Bob","Eli","Alice","Bob","Charls"};
            size_t i = 0;

            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.crbegin();

            CHECK_EQ(*item, "Dan");
            CHECK_EQ(*++item, "Bob");
            CHECK_EQ(*item++, "Bob");
            CHECK_EQ(*item, "Eli");
        }

        TEST_CASE("Order iterator")
        {
            MyContainer<string> container;

            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            string arr[]{"Charls","Bob","Alice","Eli","Bob","Dan"};
            size_t i = 0;

            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            )
                CHECK_EQ(*item, arr[i++]);
            
            auto item = container.cbegin();

            CHECK_EQ(*item, "Charls");
            CHECK_EQ(*++item, "Bob");
            CHECK_EQ(*item++, "Bob");
            CHECK_EQ(*item, "Alice");
        }

        TEST_CASE("MiddleOut iterator")
        {
            MyContainer<string> container;

            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            ) 
                CHECK(false);

            initContainer(container);

            string arrEven[]{"Eli","Alice","Bob","Bob","Dan","Charls"};
            size_t i = 0;

            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove("Dan");

            string arrOdd[]{"Alice","Bob","Eli","Charls","Bob"};
            i = 0;

            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                CHECK_EQ(*item, arrOdd[i++]);       
            
            auto item = container.MiddleOutBegin();

            CHECK_EQ(*item, "Alice");
            CHECK_EQ(*++item, "Bob");
            CHECK_EQ(*item++, "Bob");
            CHECK_EQ(*item, "Eli");
        }
    }
}