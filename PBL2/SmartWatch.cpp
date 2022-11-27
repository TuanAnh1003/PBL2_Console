#include "SmartWatch.h"
#include "Product.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

SmartWatch::SmartWatch() {
	
}

SmartWatch::SmartWatch(string ID, string name, string brand, string color, double priceF, double priceE, string status, double discount, int amount, string size) {
	
}
SmartWatch::~SmartWatch() {

}

void SmartWatch::Show() {
	Product::Show();
	cout << "Size: " << size << endl;
}
void SmartWatch::Add() {
	Product::Add();
	cout << "Size: "; getline(cin, size);
}
void SmartWatch::ReadFILE(ifstream& filein) {
	Product::ReadFile(filein);
	getline(filein, size);
}

void SmartWatch::WriteFILE(ostream& fileout) {
	Product::WriteFILE(fileout);
	fileout << size << endl;
}