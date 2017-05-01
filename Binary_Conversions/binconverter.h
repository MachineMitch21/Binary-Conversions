
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <cmath>

class BinConverter{

public:
	BinConverter();
	~BinConverter();

	std::string getBin(std::string str, char c);
	std::string binStr(std::string bin_str, std::string flag);

private:
	std::string bin_i(const char* _val);
	std::string bin_c(const char* _val);
	void rev(std::string &str);
	bool isBinStr(std::string str);
	std::string binToDec(std::string bin_str);
	std::string binToStr(std::string bin_str);
};
