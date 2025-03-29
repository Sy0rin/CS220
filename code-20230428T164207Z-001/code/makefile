
PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = proj2Test.o FeetInches.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

proj2Test.o : miniDList.h miniArrayQueue.h miniArrayStack.h miniDListQueue.h miniDListStack.h proj2Test.cpp
	$(CC) $(CPPFLAGS) -c proj2Test.cpp

FeetInches.o : FeetInches.h
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
