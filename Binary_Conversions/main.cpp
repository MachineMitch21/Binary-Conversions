#include "binconverter.h"
#include <iostream>

int main(int argv, char *argc[]){

	BinConverter bin_con;
	
	std::cout << bin_con.getBin(std::to_string(argc[2]), argc[1][0]) << std::endl;
}


