I did this project as part of my undergraduate studies in Computer and Software Engineering at Ariel University in the C++ course. In this project, we were asked to implement a generic container of objects of any type that could be compared. We were also asked to implement several iterators for the container. [This](https://github.com/BenjaminSaldman/CPP_EX4_25) is the link to the assignment instructions.

Functionality:
1. Just like all standard iterators of the language, the iterators I implemented are intended for use only under the condition that there are no changes to the container while the iterator is running, meaning that if the user performs an addition and/or deletion of an element after creating a specific operator, the iterator's behavior from here on out is unpredictable and the user must take this into account and not use the same iterator again, but create a new one if necessary
2. In addition, some iterators depend not only on adding and deleting an object but also on the content of the object itself, and therefore even a change in the value of one of the objects makes the iterator's behavior from here on out "undefined." To avoid this problem and for the sake of simplicity and uniformity, I defined all iterators as const iterator to avoid changing the objects during the iterator run
3. For the container itself, I stuck to the guidelines and implemented only the operations required in the assignment, and not other operations that are usually found in containers such as the [] operator, etc.
4. According to the accepted approach in the language, the responsibility for the class type to be comparable is the user's sole responsibility. If he tries to create the container for a type that is not comparable, he will encounter compilation errors.

Classes:

The code itself is implemented in only one class template called "MyContainer". Because the class is a template, all implementation is performed within the hpp file and there is no cpp file at all.
Under the class are 6 subclasses of the various iterators:
1) AscendingOrder
2) DescendingOrder
3) SideCrossOrder
4) ReverseOrder
5) Order
6) MiddleOutOrder

Additional files:
main.cpp - This file basically runs the various classes, and their basic functionality
MyContainerTest.cpp - A file containing unit tests for all classes and their methods, except for the print operator, which is tested in the main.cpp file
makefile - This file allows you to compile and run the program, as well as compile and run the test file. In addition, it allows you to run a valgrind test on the program itself and the tests, as well as the option to clean all binaries.

Code design considerations:

In implementing the iterators, I examined 2 main options:
1) The iterator will contain only a pointer to the elements of the original container, and all the iterator logic will be in the promotion operator to the next element
2) The iterator will contain a copy of the original container sorted according to the desired logic, and will run on this copy directly

In the end, I decided that although the first option is more "classic" in terms of the iterator structure, and is also more memory-efficient,
I preferred the second option in the name of the principle of uniformity and simplicity, because it allowed me to perform the sorting when creating the iterator, and the transition itself between the elements to be implemented in a completely identical way between all the different types of iterators. Additionally, because in any case, as I mentioned at the beginning, iterators are of const type, there is no need to access the original objects

I wrote all 1922 lines of code for this assignment myself without any consultation or any other use of artificial intelligence tools, in order to learn as much about myself as possible while performing the task in the most efficient way.
