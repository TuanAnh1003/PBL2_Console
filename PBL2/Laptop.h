#pragma once
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

class Laptop : public Product {
private:
	string card;
	string weight;
public:
	void Show();
	void setCard(string);
	void setWeight(string);
	void Add();
	friend ostream& operator << (ostream& out, Laptop a);
	void ReadFile(ifstream&);
	void WiteFILE(ostream& fileout);
};