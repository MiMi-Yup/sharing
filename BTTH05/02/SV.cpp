#include "SV.h"
#include <iostream>
using namespace std;

SV::SV() {
	flag = 0;
	MSSV = 0;
	credit = 0;
	avg_score = 0.0f;
}
SV::SV(int MSSV, string name, string address, int credit, float avg_score) {
	this->MSSV = MSSV;
	this->name = name;
	this->address = address;
	this->credit = (credit < 0 ? 0 : credit);
	if (avg_score < 0.0f) {
		this->avg_score = 0.0f;
	}
	else if (avg_score > 10.0f) {
		this->avg_score = 10.0f;
	}
	else this->avg_score = avg_score;
}
void SV::input() {
	cout << "Nhap MSSV: "; cin >> MSSV; cin.ignore();
	cout << "Nhap ho va ten: "; getline(cin, name);
	cout << "Nhap dia chi: "; getline(cin, address);
	do {
		cout << "Nhap so tin chi: "; cin >> credit;
		cout << "Nhap diem trung binh: "; cin >> avg_score;
		if (credit <= 0.0f
			|| avg_score < 0.0f
			|| avg_score>10.0f) {
			cout << "Khong hop le, nhap lai.\n";
		}
	} while ((credit <= 0.0f || avg_score < 0.0f || avg_score>10.0f));
	cin.ignore();
}
void SV::output() {
	cout << "MSSV: " << MSSV << "\n";
	cout << "Ho va ten: " << name << "\n";
	cout << "Dia chi: " << address << "\n";
	cout << "So tin chi: " << credit << "\n";
	cout << "Diem trung binh: " << avg_score << "\n";
}
float SV::getAvg_score() {
	return avg_score;
}
int SV::getMSSV() {
	return MSSV;
}