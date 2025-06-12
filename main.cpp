// liorbrown@outlook.co.il

#include "MyContainer.hpp"

using namespace Containers;

int main()
{
    // Creates new MyContainer of int
    MyContainer container;

    // Init container
    container.add(3);
    container.add(10);
    container.add(3);
    container.add(78);

    // Remove all the 3 from container
    container.remove(3);

    container.add(32);
    container.add(-24);
    container.add(87);

    // Print container using << operator
    cout << container << endl;

    cout << "reverse:" << endl;

    // Runs on all container using ReversOrder iterator, and print it
    for 
    (
        auto i = container.crbegin(); 
        i != container.crend(); 
        ++i
    )
        cout << *i << endl;
    
    cout << "acending:" << endl;

    // Runs on all container using AscendingOrder iterator, and print it
    for 
    (
        auto i = container.ascendingBegin(); 
        i != container.ascendingEnd(); 
        ++i
    )
        cout << *i << endl;
    
    cout << "descending:" << endl;

    // Runs on all container using DescendingOrder iterator, and print it
    for 
    (
        auto i = container.descendingBegin(); 
        i != container.descendingEnd(); 
        ++i
    )
        cout << *i << endl;

    cout << "Middle Out:" << endl;

    // Runs on all container using ReversOrder iterator, and print it
    for 
    (
        auto i = container.MiddleOutBegin(); 
        i != container.MiddleOutEnd(); 
        ++i
    )
        cout << *i << endl;

    cout << "side cross:" << endl;

    // Runs on all container using SideCrossOrder iterator, and print it
    for 
    (
        auto i = container.SideCrossBegin(); 
        i != container.SideCrossEnd(); 
        ++i
    )
        cout << *i << endl;
    
    // Creates new MyContainer of strings
    MyContainer<string> stringsContainer;

    // Init container
    stringsContainer.add("David");
    stringsContainer.add("lior");
    stringsContainer.add("David");
    stringsContainer.add("magi");

    // Remove all the "David"" from container
    stringsContainer.remove("David");

    stringsContainer.add("didi");
    stringsContainer.add("Eli");
    stringsContainer.add("Bamba");

    // Print container using << operator
    cout << stringsContainer << endl;

    cout << "reverse:" << endl;

    // Runs on all container using ReversOrder iterator, and print it
    for 
    (
        auto i = stringsContainer.crbegin(); 
        i != stringsContainer.crend(); 
        ++i
    )
        cout << *i << endl;
    
    cout << "ascending:" << endl;

    // Runs on all container using AscendingOrder iterator, and print it
    for 
    (
        auto i = stringsContainer.ascendingBegin(); 
        i != stringsContainer.ascendingEnd(); 
        ++i
    )
        cout << *i << endl;
    
    cout << "descending:" << endl;

    // Runs on all container using DescendingOrder iterator, and print it
    for 
    (
        auto i = stringsContainer.descendingBegin(); 
        i != stringsContainer.descendingEnd(); 
        ++i
    )
        cout << *i << endl;

    cout << "Middle Out:" << endl;

    // Runs on all container using ReversOrder iterator, and print it
    for 
    (
        auto i = stringsContainer.MiddleOutBegin(); 
        i != stringsContainer.MiddleOutEnd(); 
        ++i
    )
        cout << *i << endl;

    // Runs on all container using SideCrossOrder iterator, and print it
    cout << "side scross:" << endl;
    for 
    (
        auto i = stringsContainer.SideCrossBegin(); 
        i != stringsContainer.SideCrossEnd(); 
        ++i
    )
        cout << *i << endl;
}