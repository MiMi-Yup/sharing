#include "quanly.h"
#include <iostream>
using namespace std;

int menu();

bool exec(quanly& DSSV, int mode = menu());

int main() {
	quanly DSSV;
	while (exec(DSSV));
	return(0);
}

int menu() {
	int choose;
	do {
		system("cls");
		cout << "Cac chuc nang:\n"
			<< "1. Nhap danh sach.\n"
			<< "2. Xuat danh sach.\n"
			<< "3. Dem so luong sinh vien du dieu kien tot nghiep.\n"
			<< "4. Sinh vien dai hoc co diem trung binh cao nhat.\n"
			<< "5. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban: ";
		cin >> choose;
		if (choose < 1 || choose>5) {
			cout << "Khong hop le, nhap lai.\n";
			system("pause");
		}
	} while (choose < 1 || choose>5);
	cin.ignore();
	return choose;
}

bool exec(quanly& DSSV, int mode) {
	system("cls");
	switch (mode)
	{
	case 1:
		DSSV.input();
		break;
	case 2:
		DSSV.output();
		break;
	case 3:
		cout << "So luong sinh vien tot nghiep la: " << DSSV.passed_counter() << "\n";
		break;
	case 4:
		DSSV.maxAvg_score()->output();
		break;
	case 5:
		return false;
	default:
		break;
	}
	system("pause");
	return true;
}