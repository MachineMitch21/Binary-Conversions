
#include "binconverter.h"

BinConverter::BinConverter(){

}

BinConverter::~BinConverter(){

}

int BinConverter::binToInt(std::string str){
	
	if(isBinStr(str)){

	}
	else{
		return -1;
	}
	
	return 0;
}

std::string BinConverter::getBin(std::string str, char c){
	return (c == 'i' ? bin_i(str.c_str()) : bin_c(str.c_str()));
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
