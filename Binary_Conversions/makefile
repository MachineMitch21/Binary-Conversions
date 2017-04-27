CPPC=g++
CPPFLAGS= --std=c++0x -Wall -g

default: test 
	
test: main.o
	$(CPPC) $(CPPFLAGS) -o test main.o

main.o: binconverter.o
	$(CPPC) $(CPPFLAGS) -c main.cpp

binconverter.o: binconverter.cpp binconverter.h 
	$(CPPC) $(CPPFLAGS) -c binconverter.cpp
clean:
	$(RM) test *.o *~
