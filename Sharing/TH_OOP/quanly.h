#pragma once
#include <iostream>
#include "NVCN.h"
#include "NVSX.h"
using namespace std;


class quanly
{
private:
	NV** danhsach;
	int n;
public:
	int menu() {
		int choose;
		do {
			cout << "1. Nhan vien loi.\n"
				<< "2. Nhan vien cong nhat.\n"
				<< "3. Nhan vien san xuat.\n";
			cout << "Lua chon cua ban: ";
			cin >> choose;
			if (choose < 1 || choose>3) {
				cout << "Khong hop le.\n";
			}
		} while (choose < 1 || choose>3);
		cin.ignore();
		return choose;
	}
public:
	quanly() {
		n = 0;
		danhsach = NULL;
	}
	~quanly() {
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				if (danhsach[i] != NULL) {
					delete danhsach[i];
				}
			}
		}
		delete danhsach;
		danhsach = NULL;
	}
	void input() {
		cout << "So luong nhan vien: "; cin >> n;
		danhsach = new NV * [n];
		for (int i = 0; i < n; i++) {
			switch (menu())
			{
			case 1:
				danhsach[i] = new NV;
				if (danhsach[i] != NULL) {
					danhsach[i]->input();
				}
				break;
			case 2:
				danhsach[i] = new NVCN;
				if (danhsach[i] != NULL) {
					danhsach[i]->input();
				}
				break;
			case 3:
				danhsach[i] = new NVSX;
				if (danhsach[i] != NULL) {
					danhsach[i]->input();
				}
				break;
			default:
				break;
			}
		}
	}
	void output() {
		for (int i = 0; i < n; i++) {
			if (danhsach[i] != NULL) {
				danhsach[i]->output();
			}
		}
	}
	void sumSalary() {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (danhsach[i] != NULL) {
				sum += danhsach[i]->getSalary();
			}
		}
		cout << "Tong luong phai tra cho nhan su: " << sum << "\n";
	}
	void xuat_luong() {
		string temp;
		cout << "Nhap ten nhan vien can tinh luong: "; getline(cin, temp);
		for (int i = 0; i < n; i++) {
			if (temp.compare(danhsach[i]->getName()) == 0) {
				cout << "Nhan vien: " << temp << " duoc nhan luong: " << danhsach[i]->getSalary() << "\n";
				break;
			}
		}
	}
};

