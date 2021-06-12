#pragma once
#include <vector>
#include "cong_sucmanh.h"
#include "cong_hocthuat.h"
#include "cong_giaothuong.h"
#include "Hoangtu.h"
#include <iostream>
using namespace std;

class laudai
{
private:
	vector<cong*> list;
	int menu() {
		int choose;
		do {
			cout << "Loai cong: \n"
				<< "\t1. Cong giao thuong.\n"
				<< "\t2.Cong hoc thuat.\n"
				<< "\t3.Cong suc manh.\n"
				<< "\t4. Tro ve.\n";
			cout << "\tLua chon cua ban: ";
			cin >> choose;
			if (choose < 1 || choose>4) {
				cout << "Khong hop le, nhap lai.\n";
			}
		} while (choose < 1 || choose>4);
		return choose;
	}
public:
	void input() {
		cout << "Nhap so luong cong: ";
		int n;
		cong* temp = NULL;
		cin >> n;
		for (int i = 0; i < n; i++) {
			switch (menu())
			{
			case 1:
				temp = new cong_giaothuong;
				break;
			case 2:
				temp = new cong_hocthuat;
				break;
			case 3:
				temp = new cong_sucmanh;
				break;
			case 4:
				return;
			default:
				break;
			}
			temp->input();
			list.push_back(temp);
		}
	}
	void quacong(Hoangtu&hoangtu) {
		for (size_t i = 0; i < list.size(); i++) {
			if (!list[i]->quacong(hoangtu)) {
				cout << "Hoang tu chet giua duong.\n";
				return;
			}
		}
		cout << "Hoang tu thanh cong.\n";
		cout << "Chi so con lai cua hoang tu:\n";
		hoangtu.output();
	}
};


