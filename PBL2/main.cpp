#include "Manage.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;
string key, index;
int a;
void Display(string displayScene);
void pressAnyKey();
bool ascending(double left, double right);
bool descending(double left, double right);
int main() {
    Manage staff;
    staff.ReadFILE("db_laptop.csv");
    staff.ReadFILE("db_smartphone.csv");
    staff.ReadFILE("db_smartwatch.csv");
    staff.WriteFile("db_laptop.csv");
    /*while (true) {
        Display("MainMenu.txt");
        cout << "Enter your option: "; fflush(stdin); getline(cin, key);
        switch (key[0]) {
        case '1':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO ADD NEW DEVICE!\n";
            staff.Add();
            staff.WriteFile("db_laptop.csv");
            pressAnyKey();
            break;
        case '2':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO SEARCH!\n";
            cout << "Nhap ma sp cua thiet bi muon tim kiem: "; cin >> index;
            staff.Search(index);
            pressAnyKey();
            break;
        case '3':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO VIEW INFORMATION OF ALL DEVICE!\n";
            staff.ShowInfor();
            pressAnyKey();
            break;
        case '4':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO UPDATE INFORMATION!\n";
            cout << "Nhap ma sp cua thiet bi muon cap nhat: "; cin >> index;
            staff.Update(index);
            pressAnyKey();
            break;
        case '5':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO DELETE DEVICE!\n";
            cout << "Enter the device's ID you want to delete: ";cin >> index;
            staff.Delete(index);
            pressAnyKey();
            break;
        case '6':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO SORT BY PRICE!\n";
            staff.Sort(ascending);
            staff.ShowInfor();
            pressAnyKey();
            break;
        case '7':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO IMPORT!\n";
            cout << "Enter the device's ID you want to import: "; cin >> index;
            cout << "Nhap so luong: "; cin >> a;
            staff.Import(index, a);
            pressAnyKey();
            break;
        case '8':
            system("cls");
            cout << "YOU HAVE CHOOSE FUNCTION TO EXPORT!\n";
            cout << "Enter the device's ID you want to export: "; cin >> index;
            cout << "Nhap so luong: "; cin >> a;
            staff.Export(index, a);
            pressAnyKey();
            break;
        case '0':
            cout << "\nYou have chosen to exit the program!\n";
            _getwch();
            return 0;
        default:
            cout << "\nWrong choice please choose again!";
            pressAnyKey();
            break;
        }
    } */
    system("pause");
    return 0;
}

bool ascending(double left, double right) {
	return left > right;
}
bool descending(double left, double right) {
	return left < right;
}
void Display(string displayScene) {
    ifstream f;
    f.open(displayScene);
    if (!f)
        cout << "Failed to find file " << displayScene << "!\n";
    string line;
    while (getline(f, line))
        cout << line << endl;
}
void pressAnyKey() {
    cout << "\n\nPress any key to continue...";
    _getwch();
    system("cls");
}