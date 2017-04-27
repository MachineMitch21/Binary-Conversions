
#include "binconverter.h"

BinConverter::BinConverter(){

}

BinConverter::~BinConverter(){

}

std::string BinConverter::getBin(std::string str, char c){
	return (c == 'i' ? bin_i(c_str(str)) : bin_c(c_str(str)));
}

std::string BinConverter::bin_i(char* _val){

	int val = atoi(_val);
	std::string _bin;

	for(; val > 0; val /= 2){
		_bin = _bin + std::to_string(val % 2);
	}

	rev(_bin);
	return _bin;
}

std::string bin_c(char* _val){
	
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

void rev(std::string &str){
	int n = str.length();
	for(int i = 0; i < n/2; i++){
		std::swap(str[i], str[n-i-1]);
	}
}
