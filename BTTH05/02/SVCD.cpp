#include "SVCD.h"
#include <iostream>
using namespace std;

SVCD::SVCD() {
	flag = 2;
	graduation_score = 0.0f;
}
SVCD::SVCD(int MSSV, string name, string address, int credit, float avg_score, float graduation_score) :SV(MSSV, name, address, credit, avg_score) {
	if (graduation_score < 0.0f) {
		this->graduation_score = 0.0f;
	}
	else if (graduation_score > 10.0f) {
		this->graduation_score = 10.0f;
	}
	else this->graduation_score = graduation_score;
}
void SVCD::input() {
	cout << "----------------NHAP SINH VIEN CAO DANG----------------\n";
	SV::input();
	do {
		cout << "Nhap diem tot nghiep: ";
		cin >> graduation_score;
		if (graduation_score < 0.0f
			|| graduation_score>10.0f) {
			cout << "Khong hop le, nhap lai.\n";
		}
	} while (graduation_score < 0.0f || graduation_score > 10.0f);
	cout << "-------------------------------------------------------\n";
	cin.ignore();
}
void SVCD::output() {
	cout << "----------------SINH VIEN CAO DANG----------------\n";
	SV::output();
	cout << "Diem tot nghiep: " << graduation_score << "\n";
	cout << "--------------------------------------------------\n";
}
bool SVCD::passed() {
	if (credit >= 120
		&& avg_score >= 5.0f
		&& graduation_score >= 5.0f) {
		return true;
	}
	return false;
}