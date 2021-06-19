#include "STT.h"

STT::STT() {
	flag = 2;
}
void STT::input() {
	Book::input();
	cout << "Nhap chu de: "; getline(cin, chu_de);
	cout << "Nhap nhan vat chinh: "; getline(cin, nhan_vat_chinh);
}
void STT::output() {
	cout << "\n-------------------SACH TIEU THUYET--------------\n";
	Book::output();
	cout << "Chu de: " << chu_de << "\n";
	cout << "Nhan vat chinh: " << nhan_vat_chinh << "\n";
}