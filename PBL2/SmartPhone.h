#pragma once
#include "Product.h"

class SmartPhone : public Product {
private:
	string ram;
	string rom;
public:
	SmartPhone();
	SmartPhone(string, string, string, string, double, double, string, double, int, string, string);
	~SmartPhone();
	void Show();
	void ReadFile(ifstream&);
	void WiteFILE(ostream&);
};