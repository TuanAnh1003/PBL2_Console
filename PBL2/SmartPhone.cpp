#include "SmartPhone.h"
#include "Product.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

SmartPhone::SmartPhone() {
	this->ID = "";
	this->name = "";
	this->brand = "";
	this->color = "";
	this->priceF = 0;
	this->status = "";
	this->amount = 0;
	this->ram = "";
	this->rom = "";
}
SmartPhone::~SmartPhone() {

}
SmartPhone::SmartPhone(string ID, string name, string brand, string color, double priceF, double priceE, string status, double discount, int amount, string ram, string rom) {
	this->ID = ID;
	this->name = name;
	this->brand = brand;
	this->color = color;
	this->priceF = priceF;
	this->status = status;
	this->amount = amount;
	this->ram = ram;
	this->rom = rom;
}

void SmartPhone::Show() {
	Product::Show();
	cout << "RAM: " << ram << endl;
	cout << "ROM: " << rom << endl;
}
void SmartPhone::ReadFile(ifstream& filein) {
	Product::ReadFile(filein);
	getline(filein, ram, ',');
	getline(filein, rom);
}

void SmartPhone::WiteFILE(ostream& fileout) {
	Product::WriteFILE(fileout);
	fileout << ram << ',' << rom << endl;
}