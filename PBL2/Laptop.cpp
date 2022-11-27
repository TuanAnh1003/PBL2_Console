#include "Laptop.h"
#include "Product.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
void Laptop::Show() {
	Product::Show();
	cout << "Card do hoa :" << card << endl;
	cout << "Trong luong : " << weight << endl;
}
void Laptop::Add() {
	Product::Add();
	cin.ignore();
	cout << "Card do hoa :"; fflush(stdin); getline(cin, card); fflush(stdin);
	cout << "Trong luong : "; fflush(stdin); getline(cin, weight); fflush(stdin);
}
void Laptop::setCard(string ncard) {
	this->card = ncard;
}
void Laptop::setWeight(string nweight) {
	this->weight = nweight;
}
/* ostream& operator << (ostream& out, Laptop tmp) {
	out << tmp.ID << endl << tmp.name << endl << tmp.brand << endl << tmp.color << endl << (size_t)tmp.priceF << endl << (size_t)tmp.priceE << endl << tmp.status << endl << tmp.discount << endl << tmp.amount << endl << tmp.card << endl << tmp.weight << endl;
	return out;
}*/

void Laptop::ReadFile(ifstream& filein) {
	Product::ReadFile(filein);
	getline(filein, card, ',');
	getline(filein, weight);
}
void Laptop::WiteFILE(ostream& fileout) {
	Product::WriteFILE(fileout);
	fileout << card << ',' << weight << endl;
}