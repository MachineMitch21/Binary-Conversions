#include "binconverter.h"
#include <iostream>

#define DECIMAL "bd"
#define ASCII "bc"

int main(int argv, char *argc[]){

	std::cout << std::endl;
	std::cout << "Binary Conversion program BINNY" << std::endl;
	std::cout << "Written by: Mitch Schutt" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	BinConverter bin_con;
	std::string str(argc[2]);

	if(argc[1][0] == 'i' || argc[1][0] == 'c')
		std::cout << "Output: " << bin_con.getBin(str, argc[1][0]) << std::endl;

	else if(strcmp(argc[1], DECIMAL) != 0 || strcmp(argc[1], ASCII) != 0)
		std::cout << "Output: " << bin_con.binStr(str, argc[1]) << std::endl;
}


