
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
		//the condition is met and false if not, then we check isBin and break out of the for loop if
        //it is false
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

	//Loop through bin_str
	for(int i = 0; i < n; i++){
		//Subtract the 0 char from the current index of bin_str to get the 1 or 0 as an integer
		//and assign it to our bin int variable
		bin = bin_str[i] - '0';
		//We know that binary values are found by multiplying 2 by a power depending on the index 
		//of the binary digit.  We have already initialized p as n - 1 because the final digit in the
		//binary sequence will be multiplied to the power of 0.
		dec += (pow(2, p - i) * bin);
	}
	
	return std::to_string(dec);
}

std::string BinConverter::binToStr(std::string bin_str){
	
	int n = bin_str.length();
	int byte_track = 0;
	std::string byte;
	std::string ascii;
	char ascii_char;
	bool doAppend = false;

	for(int i = 0; i < n; i++){
		//Append current binary digit to our byte string and increment the byte_track
		byte += bin_str[i];
		byte_track++;	

		//If byte_track is 8, we have a byte so we will need to calculate the ascii value of this byte
		//We also need to make sure we calculate the ascii value of binary digits if is one less than
		//the length of bin_str
		if(byte_track == 8 || i == n - 1){
			doAppend = true;
			//Reset byte_track
			byte_track = 0;
		}
		
		if(doAppend){
			//Get the integer equivalent this current byte and assign it to our ascii_char variable
			//The compiler will implicitly cast the int to its char equivalent
			ascii_char = std::stoi(binToDec(byte));
			ascii += ascii_char;

			//Reset doAppend and byte for 
			byte.clear();
			doAppend = false;
		}
	}

	return ascii;
}
