#include "quanly.h"
using namespace std;

int menu() {
	int choose;
	do {
		cout << "1. Nhap danh sach nhan su.\n"
			<< "2. Luong cho tung nhan su.\n"
			<< "3. Xuat luong cho toan bo nhan su.\n"
			<< "4. Tong luong phai tra cho nhan su 1 thang.\n"
			<< "5. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban: \n";
		cin >> choose;
		if (choose < 1 || choose>5) {
			cout << "Khong hop le.\n";
		}
	} while (choose < 1 || choose>5);
	cin.ignore();
	return choose;
}
bool exec(quanly& danhsach, int mode = menu()) {
	switch (mode)
	{
	case 1:
		danhsach.input();
		break;
	case 2:
		danhsach.xuat_luong();
		break;
	case 3:
		danhsach.output();
		break;
	case 4:
		danhsach.sumSalary();
		break;
	case 5:
		return false;
	default:
		break;
	}
	return true;
}
int main() {
	quanly danhsach;
	while (exec(danhsach));
	return(0);
}