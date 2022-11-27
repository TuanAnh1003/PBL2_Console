#include "Product.h"
#include "Date.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;
Product::Product() {

}
Product::Product(string ID, string name, string brand, string color, double priceF, double priceE, string status, double discount, int amount) {
	this->ID = ID;
	this->name = name;
	this->brand = brand;
	this->color = color;
	this->priceF = priceF;
	//this->priceE = priceE;
	this->status = status;
	//this->discount = discount;
	this->amount = amount;
}
Product::~Product() {

}
istream& operator >> (istream& in, Product& tmp) {
	cout << "Enter the device name:"; getline(in, tmp.name);
	cout << "Enter the device brand:"; getline(in, tmp.brand);
	cout << "Enter the device color:"; getline(in, tmp.color);
	cout << "Enter the device price first:"; in >> tmp.priceF;
	//cout << "Enter the device price discount: "; in >> tmp.priceE;
	//cout << "Enter the device discount: "; in >> tmp.discount;
	cout << "Enter the device price amount: "; in >> tmp.amount;
	return in;
}
/*ostream& operator << (ostream& out, Product tmp) {
	out << tmp.ID << endl << tmp.name << endl << tmp.brand << endl << tmp.color << endl << (size_t)tmp.priceF << endl << (size_t)tmp.priceE << endl << tmp.status << endl << tmp.discount << endl << tmp.amount << endl;
	return out;
} */

void Product::setID(string nId) {
	this->ID = nId;
}
string Product::getID() {
	return ID;
}
void Product::setName(string nName) {
	this->name = nName;
}
string Product::getName() {
	return name;
}
void Product::setBrand(string nBrand) {
	this->brand = nBrand;
}
string	Product::getBrand() {
	return brand;
}
void Product::setColor(string nColor) {
	this->color = nColor;
}
string Product::getColor() {
	return color;
}
void Product::setPriceF(double nPriceF) {
	this->priceF = nPriceF;
}
double Product::getPriceF() {
	return priceF;
}
void Product::setStatus(string nStatus) {
	this->status = nStatus;
}
void Product::setAmount(int nAmount) {
	this->amount = nAmount;
}
void Product::UpdateAmount(int bonusAmount) {
	this->amount += bonusAmount;
}
void Product::setInputDate(Date nInputDate) {
	this->inputDate = nInputDate;
}
void Product::UpdateSales(int nSales) {
	this->sales += nSales;
}
void Product::UpdateRevenue() {
	this->revenue = this->sales * this->priceF;
}
void Product::Add() {
	cout << "Ma san pham : ";
	fflush(stdin); getline(cin, ID); fflush(stdin);
	cout << "Ten san pham : ";
	fflush(stdin); getline(cin, name); fflush(stdin);
	cout << "Hang : ";
	fflush(stdin); getline(cin, brand); fflush(stdin);
	cout << "Mau sac : ";
	fflush(stdin); getline(cin, color); fflush(stdin);
	cout << "Gia : "; cin >> priceF;
	cout << "So luong : "; cin >> amount;
	if (amount > 0) {
		status = "Con hang";
	}
	else {
		status = "Het hang";
	}
	sales = 0;
	revenue = sales * priceF;
	inputDate.setCurrentDate();
}

void Product::Show() {
	cout << "Ma san pham : " << ID << endl;
	cout << "Ten san pham : " << name << endl;
	cout << "Hang : " << brand << endl;
	cout << "Mau sac : " << color << endl;
	cout << "Gia goc: " << (size_t)priceF << "Vnd" << endl;
	cout << "So luong trong kho: " << amount << endl;
	cout << "Doanh so hien tai : " << sales << endl;
	cout << "Doanh thu hien tai : " << (size_t)revenue << endl;
	cout << "Trang thai: " << status << endl;
	cout << "Ngay nhap kho: " << inputDate << endl;
}
void Product::ReadFile(ifstream& filein) {
	getline(filein, ID, ',');
	getline(filein, name, ',');
	getline(filein, brand, ',');
	getline(filein, color, ',');
	filein >> priceF;
	filein.seekg(1, 1);
	filein >> amount;
	filein.seekg(1, 1);
	filein >> sales;
	filein.seekg(1, 1);
	filein >> revenue;
	filein.seekg(1, 1);
	getline(filein, status, ',');
	string dd, mm, yy;
	getline(filein, dd,'-');
	inputDate.setDay(dd);
	getline(filein, mm, '-');
	inputDate.setMonth(mm);
	getline(filein, yy,',');
	inputDate.setYear(yy);
	
}
void Product::WriteFILE(ostream& fileout) {
	fileout << ID << ',' << name << ',' << brand << ',' << color << ',' << priceF << ',' << amount << ',' << sales << ',' << revenue << ',' << status << ',' << inputDate << ',';
}