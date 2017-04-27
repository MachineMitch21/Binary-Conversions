
#include <string.h>
#include <string>
#include <stdlib.h>

class BinConverter{

public:
	BinConverter();
	~BinConverter();

	std::string getBin(std::string str, char c);

private:
	std::string bin_i(char* _val);
	std::string bin_c(char* _val);
	void rev(std::string &str);
};
