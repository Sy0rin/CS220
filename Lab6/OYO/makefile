
PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = FeetInches.o ListTestTemplate.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

ListTestTemplate.o : ListTestTemplate.cpp ListCollection.h
	$(CC) $(CPPFLAGS) -c ListTestTemplate.cpp

FeetInches.o : FeetInches.h FeetInches.cpp
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
