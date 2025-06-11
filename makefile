CXX=g++
CXXFLAGS=-std=c++2a -g -c

.PHONY: clean Main test valgrind build

Main: buildMain
	./main.out

test: buildTest
	./test.out

valgrind: buildMain buildTest
	valgrind --leak-check=yes ./main.out
	valgrind --leak-check=yes ./test.out

buildMain: main.o MyContainer.o
	$(CXX) $^ -o main.out

buildTest: MyContainerTest.o MyContainer.o
	$(CXX) $^ -o test.out

main.o: main.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o *.out