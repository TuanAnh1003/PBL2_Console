#include "Date.h"
#include <string>
#include <sstream>
#include <ctime>
Date::Date() {

}
Date::Date(string dd, string mm, string yy) {
	this->dd = dd;
	this->mm = mm;
	this->yy = yy;
}
int Date::getDay() {
	stringstream tmp(this->dd);
	int x = 0;
	tmp >> x;
	return x;
}
int Date::getMonth() {
	stringstream tmp(this->mm);
	int x = 0;
	tmp >> x;
	return x;
}
int Date::getYear() {
	stringstream tmp(this->yy);
	int x = 0;
	tmp >> x;
	return x;
}
void Date::SetNULL() {
	this->dd = "NULL";
	this->mm = "NULL";
	this->yy = "NULL";
}
void Date::setCurrentDate() {
	//time_t now = time(0);// current date/time based on current system
	//tm* ltm = localtime(&now);
	//this->dd = to_string(ltm->tm_mday);
	//this->mm = to_string(1 + ltm->tm_mon);
	//this->yy = to_string(1900 + ltm->tm_year);
}
void Date::setDay(string nDay) {
	this->dd = nDay;
}
void Date::setMonth(string nMonth) {
	this->mm = nMonth;
}
void Date::setYear(string nYear) {
	this->yy = nYear;
}
void Date::operator = (const Date& a) {
	this->dd = a.dd;
	this->mm = a.mm;
	this->yy = a.yy;
}
bool isLeapYear(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int NumOfDayInMonth(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if (isLeapYear(nYear)) nNumOfDays = 29;
		else nNumOfDays = 28;
		break;
	}
	return nNumOfDays;
}
int Date::CheckDate() {
	if (this->getYear() < 0) return 0;
	if (this->getMonth() < 1 || this->getMonth() > 12) return 0;
	if (this->getDay() < 1 || this->getDay() > NumOfDayInMonth(this->getMonth(), this->getYear())) return 0;
	return 1;
}
ostream& operator << (ostream& out, Date a) {
	out << a.dd << "/" << a.mm << "/" << a.yy;
	return out;
}

istream& operator >> (istream& in, Date& a) {
	while (a.CheckDate() != 1) {
		cout << "(Vui long nhap ngay thang nam la cac gia tri hop le!)\n";
		cout << "\nNhap ngay: ";
		getline(in, a.dd); fflush(stdin);
		cout << "\nNhap thang: ";
		getline(in, a.mm); fflush(stdin);
		cout << "\nNhap nam: ";
		getline(in, a.yy); fflush(stdin);
	}
	return in;
}