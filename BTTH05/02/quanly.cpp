#include "quanly.h"
#include <iostream>
using namespace std;

bool find(vector<SV*>list, int MSSV) {
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i]->getMSSV() == MSSV)return true;
	}
	return false;
}

int mode() {
	int choose;
	do {
		cout << "\tLoai sinh vien:\n"
			<< "\t1. Sinh vien dai hoc.\n"
			<< "\t2. Sinh vien cao dang.\n"
			<< "\t3.Tro ve.\n"
			<< "\tLua chon cua ban: ";
		cin >> choose;
		if (choose < 1 || choose>3)cout << "Khong hop le, nhap lai.\n";
	} while (choose < 1 || choose>3);
	cin.ignore();
	return choose;
}

quanly::~quanly() {
	for (size_t i = 0; i < list.size(); i++) {
		delete list[i];
		list[i] = NULL;
	}
}
void quanly::input() {
	int n;
	SV* temp = NULL;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "Sinh vien thu " << i << ":\n";
		switch (mode())
		{
		case 1:
			temp = new SVDH;
			((SVDH*)temp)->input();
			if (!find(list, temp->getMSSV())) {
				list.push_back(temp);
			}
			else cout << "Da co sinh vien trong danh sach.\n";
			break;
		case 2:
			temp = new SVCD;
			((SVCD*)temp)->input();
			if (!find(list, temp->getMSSV())) {
				list.push_back(temp);
			}
			else cout << "Da co sinh vien trong danh sach.\n";
			break;
		case 3:
			return;
		default:
			break;
		}
		system("pause");
	}
}
void quanly::output() {
	for (size_t i = 0; i < list.size(); i++) {
		switch (list[i]->flag)
		{
		case 1:
			((SVDH*)list[i])->output();
			break;
		case 2:
			((SVCD*)list[i])->output();
			break;
		default:
			break;
		}
	}
}
int quanly::passed_counter() {
	int count = 0;
	for (size_t i = 0; i < list.size(); i++) {
		switch (list[i]->flag)
		{
		case 1:
			count +=((SVDH*)list[i])->passed();
			break;
		case 2:
			count +=((SVCD*)list[i])->passed();
			break;
		default:
			break;
		}
	}
	return count;
}
SVDH* quanly::maxAvg_score() {
	size_t index = 0;
	float max = 0.0f;
	for (size_t i = 1; i < list.size(); i++) {
		if (list[i]->flag == 1 && list[i]->getAvg_score() > max) {
			index = i;
			max = list[i]->getAvg_score();
		}
	}
	if (list[index]->flag == 1) {
		return ((SVDH*)list[index]);
	}
	return NULL;
}