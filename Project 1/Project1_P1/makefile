
PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o CustomerData.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

CustomerData.o : CustomerData.h PersonData.h CustomerData.cpp
	$(CC) $(CPPFLAGS) -c CustomerData.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
