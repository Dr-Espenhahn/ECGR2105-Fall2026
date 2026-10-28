test: main.o library.o userInterface.o 
	g++ main.o library.o userInterface.o -o test
main.o: main.cpp library.h userInterface.h
	g++ -c main.cpp
library.o: library.cpp library.h userInterface.h
	g++ -c library.cpp
userInterface.o: userInterface.cpp library.h userInterface.h
	g++ -c userInterface.cpp