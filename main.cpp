// liorbrown@outlook.co.il

#include "MyContainer.hpp"

using namespace Containers;

int main()
{
    MyContainer c;
    c.add(3);
    c.add(10);
    c.add(3);
    c.add(78);
    c.remove(3);
    c.add(32);
    c.add(-24);
    c.add(87);

    cout << c << endl;

    cout << "reverse:" << endl;

    for 
    (
        auto i = c.crbegin(); 
        i != c.crend(); 
        ++i
    )
        cout << *i << endl;
    
    cout << "acending:" << endl;

    for 
    (
        auto i = c.ascendingBegin(); 
        i != c.ascendingEnd(); 
        ++i
    )
        cout << *i << endl;
    

    cout << "descending:" << endl;
    for 
    (
        auto i = c.descendingBegin(); 
        i != c.descendingEnd(); 
        ++i
    )
        cout << *i << endl;

    cout << "Middle Out:" << endl;
    for 
    (
        auto i = c.MiddleOutBegin(); 
        i != c.MiddleOutEnd(); 
        ++i
    )
        cout << *i << endl;

    cout << "side cross:" << endl;
    for 
    (
        auto i = c.SideCrossBegin(); 
        i != c.SideCrossEnd(); 
        ++i
    )
        cout << *i << endl;
}