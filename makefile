# makefile for main.cpp, a simple console typing game

all:type

type: main.o
	g++ -g -pedantic main.o -o type

main.o: main.cpp
	g++ -c -g -pedantic main.cpp -o main.o 


clean: 
	del -rf type *.o