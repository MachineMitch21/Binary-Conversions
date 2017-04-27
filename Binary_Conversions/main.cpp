#include "binconverter.h"
#include <iostream>

int main(int argv, char *argc[]){

	BinConverter bin_con;
	std::string str(argc[2]);
	std::cout << bin_con.getBin(str, argc[1][0]) << std::endl;
}


