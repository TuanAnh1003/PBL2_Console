#include "Manage.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void Manage::setLength(int nlength) {
    this->length = nlength;
}
void Manage::ShowInfor() {
    for (int i = 0; i < this->length; i++) {
        cout << "\n\n\n\t THONG TIN THIET BI THU " << i + 1 << endl;
        list.at(i)->Show();
    }
}
void Manage::Add() {
    Product* x;
    cout << "\n\n\n\tNHAP THONG TIN THIET BI THU " << this->length + 1 << endl;
    x = new Laptop;
    x->Add();
    list.push_back(x);
    setLength(length + 1);
}
int Manage::Delete(string id) {
    int i, found = 0;
    for (i = 0; i < this->length; i++) {
        if (list[i]->ID == id) {
            found = 1;
            list.erase(list.begin() + i);
            break;
        }
    }
    if (found == 0) {
        cout << "Device's ID = " << id << " do not exit!\n";
        return 0;
    }
    else {
        cout << "Device's ID = " << id << " deleted!\n";
        this->length--;
        return 1;
    }
}
int Manage::Update(string id) {
    int i, found = 0;
    for (i = 0; i < this->length; i++) {
        if (list[i]->ID == id) {
            found = 1;
            cout << "\n\n\n\tCAP NHAT THONG TIN THIET BI THU " << i + 1 << endl;
            cin.ignore();
            list[i]->Add();
            break;
        }
    }
    if (found == 0) {
        cout << "Device's ID = " << id << " do not exit!\n";
        return 0;
    }
    else {
        cout << "Device's ID = " << id << " updated!\n";
        return 1;
    }
}
int Manage::Search(string id) {
    int i, found = 0;
    for (i = 0; i < this->length; i++) {
        if (list[i]->ID == id) {
            found = 1;
            cout << "\n\n\n\t THONG TIN THIET BI CO MA SP : " << id << endl;
            list[i]->Show();
            break;
        }
    }
    if (found == 0) {
        cout << "Device's ID = " << id << " do not exit!\n";
        return 0;
    }
}
void Swap(Product *&a, Product *&b) {
    Product* tmp = a;
    a = b;
    b = tmp;
}
void Manage::Sort(bool CompFunc(double, double)) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            double a = list[i]->getPriceF();
            double b = list[j]->getPriceF();
            if (CompFunc(a, b)) {
                Swap(list[i], list[j]);
            }
        }
    }
    cout << "Already arranged!\n";
}
int Manage::Import(string id, int bonus) {
    int i, found = 0;
    for (i = 0; i < this->length; i++) {
        if (list[i]->ID == id) {
            found = 1;
            list[i]->UpdateAmount(bonus);
            break;
        }
    }
    if (found == 0) {
        cout << "Device's ID = " << id << " do not exit!\n";
        return 0;
    }
}

int Manage::Export(string id, int bonus) {
    int i, found = 0;
    for (i = 0; i < this->length; i++) {
        if (list[i]->ID == id) {
            found = 1;
            list[i]->UpdateAmount(-bonus);
            list[i]->UpdateSales(bonus);
            list[i]->UpdateRevenue();
            break;
        }
    }
    if (found == 0) {
        cout << "Device's ID = " << id << " do not exit!\n";
        return 0;
    }
}
int Manage::NumOfDV(string filename) {
    ifstream filein;
    char c;
    int numchars, numlines;
    filein.open(filename);
    numchars = 0;
    numlines = 0;
    filein.get(c);
    while (filein) {
        while (filein && c != '\n') {
            numchars = numchars + 1;
            filein.get(c);
        }
        numlines = numlines + 1;
        filein.get(c);
    }
    filein.close();
    return numlines - 1;
}
void Manage::ReadFILE(string filename) {
    ifstream filein;
    filein.open(filename, ios_base::in);
    int bonuslength = NumOfDV(filename);
    Product* x = NULL;
    string line;
    //getline(filein, line, '\n'); // Mean skip the first line? Right?
    for (int i = this->length; i < this->length + bonuslength; i++) {
        char c;
        filein >> c;
        filein.seekg(-1, 1);
        if (c == 'L') {
            x = new Laptop();
            x->ReadFile(filein);
        }
        else if (c == 'S') {
            x = new SmartPhone();
            x->ReadFile(filein);
        }
        else if (c == 'W') {
            x = new SmartWatch();
            x->ReadFile(filein);
        }
        list.push_back(x);
    }
    setLength(this->length + bonuslength);
    filein.close();
}
void Manage::WriteFile(string filename) {
    ofstream filein;
    filein.open(filename, ios_base::out);
    for (int i = 0; i < this->length; i++) {
        string index = list[i]->getID();
        string index1 = "LT01";
        string index2 = "SP01";
        string index3 = "W01";
        if (index[0] == index1[0]) {
            Laptop* a = dynamic_cast<Laptop*>(list[i]);
            //a->Show();
            a->WriteFILE(filein);
        }
        else if (index[0] == index2[0]) {
            SmartPhone* a = dynamic_cast<SmartPhone*>(list[i]);
            //a->Show();
            a->WriteFILE(filein);
        }
        else if (index[0] == index3[0]) {
            SmartWatch* a = dynamic_cast<SmartWatch*>(list[i]);
            //a->Show();
            a->WriteFILE(filein);
        }
        else {
            cout << "x";
            list[i]->WriteFILE(filein);
        }
    }
    filein.close();
}

