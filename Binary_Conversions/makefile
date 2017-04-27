CPPC=g++
CPPFLAGS= --std=c++0x -Wall -g

default: bin_con 
	
bin_con: main.o binconverter.o
	$(CPPC) main.o binconverter.o -o bin_con

main.o: main.cpp
	$(CPPC) $(CPPFLAGS) -c main.cpp

binconverter.o: binconverter.cpp  
	$(CPPC) $(CPPFLAGS) -c binconverter.cpp
clean:
	$(RM) bin_con *.o *~
