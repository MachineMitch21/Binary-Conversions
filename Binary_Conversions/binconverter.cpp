
#include "binconverter.h"

BinConverter::BinConverter(){

}

BinConverter::~BinConverter(){

}

std::string BinConverter::getBin(std::string str, char c){
	return (c == 'i' ? bin_i(str.c_str()) : bin_c(str.c_str()));
}

std::string BinConverter::binStr(std::string bin_str, std::string flag){
	if(isBinStr(bin_str))
		return (flag == "bd" ? binToDec(bin_str) : flag == "bc" ? binToStr(bin_str) : "Invalid flag: bd for DECIMAL, bc for ASCII");
	else
		return "Invalid binary string: Should be 1s and 0s";
}

std::string BinConverter::bin_i(const char* _val){

	int val = atoi(_val);
	std::string _bin;

	for(; val > 0; val /= 2){
		_bin = _bin + std::to_string(val % 2);
	}

	rev(_bin);
	return _bin;
}

std::string BinConverter::bin_c(const char* _val){
	
	std::string _bin;
	
	std::string temp(_val);
	for(unsigned int i = 0; i < temp.length(); i++){

		int val = (int)_val[i];
		for(; val > 0; val /= 2){
			_bin = _bin + std::to_string(val % 2);
		}
	}

	rev(_bin);
	return _bin;
}

void BinConverter::rev(std::string &str){
	int n = str.length();
	for(int i = 0; i < n/2; i++){
		std::swap(str[i], str[n-i-1]);
	}
}

bool BinConverter::isBinStr(std::string str){
	bool isBin = false;

	for(unsigned int i = 0; i < str.length(); i++){
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
