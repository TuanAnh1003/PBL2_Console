#pragma once
#include "Product.h"

class SmartWatch : public Product {
private:
	string size;
public:
	SmartWatch();
	SmartWatch(string, string, string, string, double, double, string, double, int, string);
	~SmartWatch();
	void Show();
	void ReadFILE(ifstream& filein);
	void WriteFILE(ostream&);
	void Add();
};
