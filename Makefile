program: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o program

main.o: main.cpp Executive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp BinaryTree.h BinaryTree.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean: 
	rm *.o program