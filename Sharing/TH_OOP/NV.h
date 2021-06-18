#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class NV
{
protected:
	string name;
	Date birth;
	Date start;
	bool gioitinh;
	string address;
	int salary;
	const int chisophucloi = 956;
public:
	NV() {
		salary = 0;
		gioitinh = NULL;
	}
	NV(string name, Date birth, Date start, bool gioitinh, string address, int salary) {
		this->name = name;
		this->birth = birth;
		this->start = start;
		this->gioitinh = gioitinh;
		this->address = address;
		this->salary = salary;
	}
	virtual void input() {
		cout << "Ho va ten: "; getline(cin, name); cout << endl;
		cout << "Ngay sinh: "; birth.input(); cout << endl;
		cout << "Ngay vao cong ty: "; start.input(); cout << endl;
		cout << "Gioi tinh: "
			<< "0. Nam\n"
			<< "1. Nu.\n";
		cin >> gioitinh;
		cin.ignore();
		cout << "Dia chi: "; getline(cin, address); cout << endl;
		cout << "Luong co ban: "; cin >> salary; cout << endl;
		salary += (2021 - start.getYear()) * chisophucloi;
	}
	virtual void output() {
		cout << "Ho va ten: " << name << "\n";
		cout << "Ngay sinh: "; birth.output(); cout << endl;
		cout << "Ngay vao cong ty: "; start.output(); cout << endl;
		cout << "Gioi tinh: ";
		if (gioitinh) {
			cout << "Nu.";
		}
		else cout << "Nam.";
		cout << endl;
		cout << "Dia chi: " << address << endl;
	}
	int getSalary() {
		return salary;
	}
	string getName() {
		return name;
	}
};

