#pragma once
#include "Product.h"
#include "Laptop.h"
#include "SmartPhone.h"
#include "SmartWatch.h"
#include <vector>

class Manage {
private:
	string username;
	string password;
	vector<Product*> list;
	int length;
public:
	int NumOfDV(string);
	void ReadFILE(string);
	void WriteFile(string);
	void ShowInfor();
	void setLength(int);
	void Add();
	int Update(string);
	int Delete(string);
	int Search(string);
	void Sort(bool (double, double));
	int Import(string, int);
	int Export(string, int);
};