
PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = ListCollection.o ListTest.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

ListTest.o : ListTest.cpp
	$(CC) $(CPPFLAGS) -c ListTest.cpp

ListCollection.o :  ListCollection.h ListCollection.cpp
	$(CC) $(CPPFLAGS) -c ListCollection.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
