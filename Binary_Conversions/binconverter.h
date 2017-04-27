
#include <string.h>
#include <string>
#include <stdlib.h>

class BinConverter{

public:
	BinConverter();
	~BinConverter();

	std::string getBin(std::string str, char c);

private:
	std::string bin_i(const char* _val);
	std::string bin_c(const char* _val);
	void rev(std::string &str);
};
