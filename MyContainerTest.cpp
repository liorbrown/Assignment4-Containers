// liorbrown@outlook.co.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.hpp"
#include "MyContainer.hpp"

using namespace Containers;

/// @brief Init int container with some default values
/// @param container Container to init
void initContainer(MyContainer<>& container)
{
    container.add(5);
    container.add(3);
    container.add(-7);
    container.add(10);
    container.add(3);
    container.add(6);
}

/// @brief Init double container with some default values
/// @param container Container to init
void initContainer(MyContainer<double>& container)
{
    container.add(5.1);
    container.add(3.2);
    container.add(-7.7);
    container.add(10.4);
    container.add(3.2);
    container.add(6.8);
}

/// @brief Init strings container with some default values
/// @param container Container to init
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

            // Init container with default values
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

            // Run on empty container using AscendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            int expected[]{-7,3,3,5,6,10};
            size_t i = 0;

            // Run on all items in container using Ascending iterator
            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.ascendingBegin();

            // Check value of first item
            CHECK_EQ(*item, -7);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 3);
        }

        TEST_CASE("Descending iterator")
        {
            MyContainer container;

            // Run on empty container using DescendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            int expected[]{10,6,5,3,3,-7};
            size_t i = 0;

            // Run on all items in container using DescendingOrder iterator
            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.descendingBegin();

            // Check value of first item
            CHECK_EQ(*item, 10);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 6);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 6);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 5);
        }

        TEST_CASE("SideCross iterator")
        {
            MyContainer container;

            // Run on empty container using SideCrossOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Sets array of expected values of even size container
            int arrEven[]{-7,10,3,6,3,5};
            size_t i = 0;

            // Run on all items in even size container using SideCrossOrder iterator
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove(6);

            // Sets array of expected values of odd size container
            int arrOdd[]{-7,10,3,5,3};
            i = 0;

            // Run on all items in odd size container using SideCrossOrder iterator
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrOdd[i++]);

            auto item = container.SideCrossBegin();

            // Check value of first item
            CHECK_EQ(*item, -7);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 10);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 10);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 3);
        }

        TEST_CASE("Reverse iterator")
        {
            MyContainer container;

            // Run on empty container using ReverseOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            int expected[]{6,3,10,-7,3,5};
            size_t i = 0;

            // Run on all items in container using ReverseOrder iterator
            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.crbegin();

            // Check value of first item
            CHECK_EQ(*item, 6);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 10);
        }

        TEST_CASE("Order iterator")
        {
            MyContainer container;

            // Run on empty container using Order iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            int expected[]{5,3,-7,10,3,6};
            size_t i = 0;

            // Run on all items in container using Order iterator
            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.cbegin();

            // Check value of first item
            CHECK_EQ(*item, 5);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, -7);
        }

        TEST_CASE("MiddleOut iterator")
        {
            MyContainer container;

            // Run on empty container using MiddleOutOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Sets array of expected values of even size container
            int arrEven[]{10,-7,3,3,6,5};
            size_t i = 0;

            // Run on all items in even size container using MiddleOutOrder iterator
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove(6);

            // Sets array of expected values of odd size container
            int arrOdd[]{-7,3,10,5,3};
            i = 0;

            // Run on all items in odd size container using MiddleOutOrder iterator
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrOdd[i++]);       
            
            auto item = container.MiddleOutBegin();

            // Check value of first item
            CHECK_EQ(*item, -7);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3);

            // Ensure that item++ operator forward the iterator 
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
            // Init container with default values
            initContainer(container);              

            // Check full container size
            CHECK_EQ(6, container.size());
        }

        TEST_CASE("Remove test")
        {
            MyContainer<double> container;

            // Check remove from empty container
            CHECK_THROWS_AS(container.remove(3.2), invalid_argument);

            // Init container with default values
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

            // Run on empty container using AscendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            double expected[]{-7.7,3.2,3.2,5.1,6.8,10.4};
            size_t i = 0;

            // Run on all items in container using AscendingOrder iterator
            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.ascendingBegin();

            // Check value of first item
            CHECK_EQ(*item, -7.7);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3.2);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3.2);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 3.2);
        }

        TEST_CASE("Descending iterator")
        {
            MyContainer<double> container;

            // Run on empty container using DescendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            double expected[]{10.4,6.8,5.1,3.2,3.2,-7.7};
            size_t i = 0;

            // Run on all items in container using DescendingOrder iterator
            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.descendingBegin();

            // Check value of first item
            CHECK_EQ(*item, 10.4);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 6.8);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 6.8);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 5.1);
        }

        TEST_CASE("SideCross iterator")
        {
            MyContainer<double> container;

            // Run on empty container using SideCrossOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Sets array of expected values of even size container
            double arrEven[]{-7.7,10.4,3.2,6.8,3.2,5.1};
            size_t i = 0;

            // Run on all items in even size container using SideCrossOrder iterator
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove(6.8);

            // Sets array of expected values of odd size container
            double arrOdd[]{-7.7,10.4,3.2,5.1,3.2};
            i = 0;

            // Run on all items in odd size container using SideCrossOrder iterator
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrOdd[i++]);

            auto item = container.SideCrossBegin();

            // Check value of first item
            CHECK_EQ(*item, -7.7);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 10.4);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 10.4);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 3.2);
        }

        TEST_CASE("Reverse iterator")
        {
            MyContainer<double> container;

            // Run on empty container using ReverseOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            double expected[]{6.8,3.2,10.4,-7.7,3.2,5.1};
            size_t i = 0;

            // Run on all items in container using ReverseOrder iterator
            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.crbegin();

            // Check value of first item
            CHECK_EQ(*item, 6.8);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3.2);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3.2);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, 10.4);
        }

        TEST_CASE("Order iterator")
        {
            MyContainer<double> container;

            // Run on empty container using Order iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            double expected[]{5.1,3.2,-7.7,10.4,3.2,6.8};
            size_t i = 0;

            // Run on all items in container using Order iterator
            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i++]);
            
            auto item = container.cbegin();

            // Check value of first item
            CHECK_EQ(*item, 5.1);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3.2);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3.2);

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, -7.7);
        }

        TEST_CASE("MiddleOut iterator")
        {
            MyContainer<double> container;

            // Run on empty container using AscendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Sets array of expected values of even size container
            double arrEven[]{10.4,-7.7,3.2,3.2,6.8,5.1};
            size_t i = 0;

            // Run on all items in even size container using MiddleOutOrder iterator
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrEven[i++]);
            
            container.remove(6.8);

            // Sets array of expected values of odd size container
            double arrOdd[]{-7.7,3.2,10.4,5.1,3.2};
            i = 0;

            // Run on all items in odd size container using MiddleOutOrder iterator
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
                // Equals current item with expected item
                CHECK_EQ(*item, arrOdd[i++]);       
            
            auto item = container.MiddleOutBegin();

            // Check value of first item
            CHECK_EQ(*item, -7.7);

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, 3.2);

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, 3.2);

            // Ensure that item++ operator forward the iterator 
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
            // Init container with default values
            initContainer(container);              

            // Check full container size
            CHECK_EQ(6, container.size());
        }

        TEST_CASE("Remove test")
        {
            MyContainer<string> container;

            // Check remove from empty container
            CHECK_THROWS_AS(container.remove("Bob"), invalid_argument);

            // Init container with default values
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

            // Run on empty container using AscendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            string expected[]{"Alice","Bob","Bob","Charls","Dan","Eli"};
            size_t i = 0;

            // Run on all items in container using AscendingOrder iterator
            for
            (
                auto item = container.ascendingBegin();
                item != container.ascendingEnd();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), expected[i++].size());
            }
            
            auto item = container.ascendingBegin();

            // Check value of first item
            CHECK_EQ(*item, "Alice");

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, "Bob");

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, "Bob");

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, "Bob");
        }

        TEST_CASE("Descending iterator")
        {
            MyContainer<string> container;

            // Run on empty container using DescendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            string expected[]{"Eli","Dan","Charls","Bob","Bob","Alice"};
            size_t i = 0;

            // Run on all items in container using DescendingOrder iterator
            for
            (
                auto item = container.descendingBegin();
                item != container.descendingEnd();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), expected[i++].size());
            }
            
            auto item = container.descendingBegin();

            // Check value of first item
            CHECK_EQ(*item, "Eli");

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, "Dan");

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, "Dan");

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, "Charls");
        }

        TEST_CASE("SideCross iterator")
        {
            MyContainer<string> container;

            // Run on empty container using SideCrossOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Sets array of expected values of even size container
            string arrEven[]{"Alice","Eli","Bob","Dan","Bob","Charls"};
            size_t i = 0;

            // Run on all items in even size container using SideCrossOrder iterator
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, arrEven[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), arrEven[i++].size());
            }
            
            container.remove("Dan");

            // Sets array of expected values of odd size container
            string arrOdd[]{"Alice","Eli","Bob","Charls","Bob"};
            i = 0;

            // Run on all items in odd size container using SideCrossOrder iterator
            for
            (
                auto item = container.SideCrossBegin();
                item != container.SideCrossEnd();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, arrOdd[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), arrOdd[i++].size());
            }

            auto item = container.SideCrossBegin();

            // Check value of first item
            CHECK_EQ(*item, "Alice");

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, "Eli");

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, "Eli");

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, "Bob");
        }

        TEST_CASE("Reverse iterator")
        {
            MyContainer<string> container;

            // Run on empty container using ReverseOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            string expected[]{"Dan","Bob","Eli","Alice","Bob","Charls"};
            size_t i = 0;

            // Run on all items in container using ReverseOrder iterator
            for
            (
                auto item = container.crbegin();
                item != container.crend();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), expected[i++].size());
            }
            
            auto item = container.crbegin();

            // Check value of first item
            CHECK_EQ(*item, "Dan");

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, "Bob");

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, "Bob");

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, "Eli");
        }

        TEST_CASE("Order iterator")
        {
            MyContainer<string> container;

            // Run on empty container using Order iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Set array of expected values order
            string expected[]{"Charls","Bob","Alice","Eli","Bob","Dan"};
            size_t i = 0;

            // Run on all items in container using Order iterator
            for
            (
                auto item = container.cbegin();
                item != container.cend();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, expected[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), expected[i++].size());
            }
            
            auto item = container.cbegin();

            // Check value of first item
            CHECK_EQ(*item, "Charls");

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, "Bob");

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, "Bob");

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, "Alice");
        }

        TEST_CASE("MiddleOut iterator")
        {
            MyContainer<string> container;

            // Run on empty container using AscendingOrder iterator,
            // and ensure its not throws and not get into loop
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            ) 
                CHECK(false);

            // Init container with default values
            initContainer(container);

            // Sets array of expected values of even size container
            string arrEven[]{"Eli","Alice","Bob","Bob","Dan","Charls"};
            size_t i = 0;

            // Run on all items in even size container using MiddleOutOrder iterator
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, arrEven[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), arrEven[i++].size());
            }
            
            container.remove("Dan");

            // Sets array of expected values of odd size container
            string arrOdd[]{"Alice","Bob","Eli","Charls","Bob"};
            i = 0;

            // Run on all items in odd size container using MiddleOutOrder iterator
            for
            (
                auto item = container.MiddleOutBegin();
                item != container.MiddleOutEnd();
                ++item
            )
            {
                // Equals current item with expected item
                CHECK_EQ(*item, arrOdd[i]);

                // Checks -> operator by equals strings size()
                CHECK_EQ(item->size(), arrOdd[i++].size());
            }
            
            auto item = container.MiddleOutBegin();

            // Check value of first item
            CHECK_EQ(*item, "Alice");

            // Ensure that ++item operator returns value after forwarding
            CHECK_EQ(*++item, "Bob");

            // Ensure that item++ operator returns value before forwarding
            CHECK_EQ(*item++, "Bob");

            // Ensure that item++ operator forward the iterator 
            CHECK_EQ(*item, "Eli");
        }
    }
}