CPPC		= g++
CPPFLAGS	= --std=c++0x -Wall -g
TARGET 		= binny

default: $(TARGET) 
	
$(TARGET): main.o binconverter.o
	$(CPPC) main.o binconverter.o -o $(TARGET)

main.o: main.cpp
	$(CPPC) $(CPPFLAGS) -c main.cpp

binconverter.o: binconverter.cpp  
	$(CPPC) $(CPPFLAGS) -c binconverter.cpp

clean:
	$(RM) $(TARGET) *.o *~
