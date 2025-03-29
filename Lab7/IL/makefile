
PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = FeetInches.o ListTest-1.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

ListTest-1.o : ListTest-1.cpp ListCollection.h
	$(CC) $(CPPFLAGS) -c ListTest-1.cpp

FeetInches.o : FeetInches.h FeetInches.cpp
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
