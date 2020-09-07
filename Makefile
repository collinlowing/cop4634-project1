CFLAGS = -g -Wall
CC = g++

objects = myshell.o parse.o

myshell: $(objects)
	$(CC) -o myshell $(objects)

myshell.o: myshell.cpp
parse.o: parse.cpp parse.hpp

clean:
	rm myshell *.o *.gc* *.dSYM
