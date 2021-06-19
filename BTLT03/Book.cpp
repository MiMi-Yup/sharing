#include "Book.h"

Book::Book() {
	gia = 0;
	flag = 0;
}
void Book::input() {
	cout << "Nhap ten sach: "; getline(cin, ten_sach);
	cout << "Nhap ten tac gia: "; getline(cin, tac_gia);
	cout << "Nhap nha xuat ban: "; getline(cin, nha_xuat_ban);
	cout << "Nhap ngay ra mat: "; getline(cin, ngay_ra_mat);
	cout << "Nhap gia sach: "; cin >> gia;
	cin.ignore();
	cout << "Nhap vi tri cuon sach: "; getline(cin, vi_tri);
	cout << "Nhap ngay muon sach: "; ngay_muon.input();
}
void Book::output() {
	cout << "Ten sach: " << ten_sach << "\n";
	cout << "Tac gia: " << tac_gia << "\n";
	cout << "Nha xuat ban: " << nha_xuat_ban << "\n";
	cout << "Ngay ra mat: " << ngay_ra_mat << "\n";
	cout << "Gia sach: " << gia << "\n";
	cout << "Vi tri cuon sach: " << vi_tri << "\n";
	cout << "Ngay muon: "; ngay_muon.output(); cout << endl;
}
bool Book::expired(Date now) {
	now = now.sub(ngay_muon);
	if (now.getYear() > 0 || now.getMonth() > 0)return true;
	if (now.getDay() > 30)return true;
	return false;
}