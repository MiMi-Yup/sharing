#include "SVDH.h"
#include <iostream>
using namespace std;

SVDH::SVDH() {
	flag = 1;
	thesis_score = 0.0f;
}
SVDH::SVDH(int MSSV, string name, string address, int credit, float avg_score, string thesis_name, float thesis_score) :SV(MSSV, name, address, credit, avg_score) {
	this->thesis_name = thesis_name;
	if (thesis_score < 0.0f) {
		this->thesis_score = 0.0f;
	}
	else if (thesis_score > 10.0f) {
		this->thesis_score = 10.0f;
	}
	else this->thesis_score = thesis_score;
}
void SVDH::input() {
	cout << "----------------NHAP SINH VIEN DAI HOC----------------\n";
	SV::input();
	cout << "Nhap ten luan van: "; getline(cin, thesis_name);
	
	do {
		cout << "Nhap diem luan van: ";
		cin >> thesis_score;
		if (thesis_score < 0.0f
			|| thesis_score>10.0f) {
			cout << "Khong hop le, nhap lai.\n";
		}
	} while (thesis_score < 0.0f || thesis_score > 10.0f);
	cout << "------------------------------------------------------\n";
	cin.ignore();
}
void SVDH::output() {
	cout << "----------------SINH VIEN DAI HOC----------------\n";
	SV::output();
	cout << "Ten luan van: " << thesis_name << "\n";
	cout << "Diem luan van: " << thesis_score << "\n";
	cout << "-------------------------------------------------\n";
}
bool SVDH::passed() {
	if (credit >= 170
		&& avg_score >= 5.0f
		&& thesis_score >= 5.0f) {
		return true;
	}
	return false;
}