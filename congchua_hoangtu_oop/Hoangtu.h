#pragma once
#include <iostream>
using namespace std;
class cong;
class Hoangtu
{
private:
	int sotien, sucmanh, tritue;
public:
	void input() {
		cout << "-----Hoang Tu-------\n";
		cout << "Nhap so tien: "; cin >> sotien;
		cout << "Nhap suc manh: "; cin >> sucmanh;
		cout << "Nhap tritue: "; cin >> tritue;
	}
	void output() {
		cout << "Hoang tu con lai: \n";
		cout << "So tien: " << sotien << endl;
		cout << "Suc manh: " << sucmanh << endl;
		cout << "Tritue: " << tritue << endl;
	}
	void set(int sotien, int sucmanh, int tritue) {
		this->sotien = sotien;
		this->sucmanh = sucmanh;
		this->tritue = tritue;
	}
	int get_sotien() {
		return sotien;
	}
	int get_sucmanh() {
		return sucmanh;
	}
	int get_tritue() {
		return tritue;
	}
};

