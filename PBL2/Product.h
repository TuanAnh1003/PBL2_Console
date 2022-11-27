#pragma once
#include "Date.h"
#include <iostream>
#include <string.h>
#include <ctime>
#include <vector>
using namespace std;
class Product {
public:
	string ID;
	string name;
	string brand;
	string color;
	double priceF;
	double amount;
	int sales;
	double revenue;
	string status;
	Date inputDate;
public:
	Product();
	Product(string, string, string, string, double, double, string, double, int);
	~Product();
	friend istream& operator >> (istream& in, Product& sv);
	friend ostream& operator << (ostream& out, Product a);
	void setID(string id);
	string getID();
	void setName(string);
	string getName();
	void setBrand(string);
	string getBrand();
	void setColor(string);
	string getColor();
	void setPriceF(double);
	double getPriceF();
	void setStatus(string);
	void setAmount(int);
	void UpdateSales(int);
	void UpdateRevenue();
	void UpdateAmount(int);
	void setInputDate(Date);
	virtual void Add();
	virtual void Show();
	virtual void ReadFile(ifstream&);
	virtual void WriteFILE(ostream&);
};