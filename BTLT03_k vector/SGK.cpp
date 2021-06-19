#include "SGK.h"

SGK::SGK() {
	flag = 1;
}
void SGK::input() {
	Book::input();
	cout << "Nhap mon hoc: "; getline(cin, mon_hoc);
}
void SGK::output() {
	cout << "\n-------------------SACH GIAO KHOA--------------\n";
	Book::output();
	cout << "Mon hoc: " << mon_hoc << "\n";
}