#include "Library.h"
using namespace std;
int menu() {
	int choose;
	do {
		system("cls");
		cout << "1. Nhap danh sach nguoi muon.\n"
			<< "2. Xuat danh sach.\n"
			<< "3. Danh sach nguoi doc qua han.\n"
			<< "4. So sanh so luong muon sach giao khoa va sach tieu thuyet.\n"
			<< "5. Thoat chuong trinh.\n";
		cin >> choose;
		if (choose < 1 || choose>5) {
			cout << "Khong hop le, nhap lai.\n";
			system("pause");
		}
	} while (choose < 1 || choose>5);
	cin.ignore();
	return choose;
}
bool exec(Library& thuvien, int mode = menu()) {
	system("cls");
	switch (mode)
	{
	case 1:
		thuvien.input();
		break;
	case 2:
		thuvien.output();
		break;
	case 3:
		thuvien.expired();
		break;
	case 4:
		thuvien.count();
		break;
	case 5:
		return false;
	default:
		break;
	}
	system("pause");
	return true;
}
int main() {
	Library thuvien;
	while (exec(thuvien));
	return(0);
}