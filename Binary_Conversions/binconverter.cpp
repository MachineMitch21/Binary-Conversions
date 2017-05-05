
#include "binconverter.h"

BinConverter::BinConverter(){

}

BinConverter::~BinConverter(){

}

//Convert the str param to binary
std::string BinConverter::getBin(std::string str, char c){

	//If second param is i, convert as decimal else convert as ascii text
	return (c == 'i' ? bin_i(str.c_str()) : bin_c(str.c_str()));
}

//Convert binary to decimal or ascii text depending on flag param
std::string BinConverter::binStr(std::string bin_str, std::string flag){

	//Check to be sure bin_str is a true binary string
	if(isBinStr(bin_str))
		
		//If flag equal to "bd" convert binary string to a decimal, if flag equal to "bc" convert binary string to ascii text
		//Else return the Invalid flag string
		return (flag == "bd" ? binToDec(bin_str) : flag == "bc" ? binToStr(bin_str) : "Invalid flag: bd for DECIMAL, bc for ASCII");
	else
		return "Invalid binary string: Should be 1s and 0s";
}

std::string BinConverter::bin_i(const char* _val){
	
	int val = atoi(_val);
	std::string _bin;

	//Divide val by two on each iteration
	for(; val > 0; val /= 2){
		//Get the remainder of val / 2 using modulus (1 or 0), this is where the magic happens
		_bin += std::to_string(val % 2);
	}

	rev(_bin);
	return _bin;
}

std::string BinConverter::bin_c(const char* _val){
	
	std::string _bin;
	
	//Create a string from _val param and loop through it
	std::string ascii(_val);
	for(unsigned int i = 0; i < ascii.length(); i++){

		//Convert the current index of the ascii text to it's integer equivalent explicitly
		int val = (int)ascii[i];
		//Do like we did in the bin_i method and loop through val, dividing by 2 on each iteration
		for(; val > 0; val /= 2){
			_bin = _bin + std::to_string(val % 2);
		}
	}

	rev(_bin);
	return _bin;
}

//Reverse a string
void BinConverter::rev(std::string &str){
	int n = str.length();
	for(int i = 0; i < n/2; i++){
		//Swap the character at index i with the character at (The length of the string - the current index - 1)
		//Starting at index 0 and the last index of the string, 
		//this will work its way in until while i < the index at (the length of the string divided by 2)
		std::swap(str[i], str[n-i-1]);
	}
}


//Helper method to check whether a given string is a proper binary string (1s and 0s)
bool BinConverter::isBinStr(std::string str){
	bool isBin = false;
	
	for(unsigned int i = 0; i < str.length(); i++){
		//We check the current index against conditions '1' and '0' and assign isBin true if 
		//the condition is met and false if not, then we check isBin and break out of the for loop if it is false
		(str[i] == '1' || str[i] == '0' ? isBin = true : isBin = false);
		
		if(!isBin)
			break;
	}
	return isBin;
}

std::string BinConverter::binToDec(std::string bin_str){
	
	int n = bin_str.length();
	int p = n - 1;
	int dec = 0;
	int bin = 0;

	for(int i = 0; i < n; i++){
		bin = bin_str[i] - '0';
		dec += (pow(2, p - i) * bin);
	}
	
	return std::to_string(dec);
}

std::string BinConverter::binToStr(std::string bin_str){
	
	int n = bin_str.length();
	int byte_track = 0;
	std::string byte;
	std::string ascii;
	char c;
	bool doAppend = false;

	for(int i = 0; i < n; i++){
		
		byte += bin_str[i];
		byte_track++;	

		if(byte_track == 8 || i == n - 1){
			doAppend = true;
			byte_track = 0;
		}
		
		if(doAppend){
			c = std::stoi(binToDec(byte));
			ascii += c;
			byte.clear();
			doAppend = false;
		}
	}

	return ascii;
}
