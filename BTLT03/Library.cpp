#include "Library.h"

Library::~Library() {
	for (size_t i = 0; i < danhsach.size(); i++) {
		if (danhsach[i] != NULL) {
			delete danhsach[i];
		}
	}
}
void Library::input() {
	nguoi_muon* temp = NULL;
	int n;
	cout << "Nhap so luong nguoi muon: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		temp = new nguoi_muon;
		if (temp != NULL) {
			temp->input();
			danhsach.push_back(temp);
		}
	}
}
void Library::output() {
	cout << "Nhan sach nguoi muon: \n";
	for (size_t i = 0; i < danhsach.size(); i++) {
		cout << i << ".\n";
		if (danhsach[i] != NULL) {
			danhsach[i]->output();
		}
	}
}
void Library::expired() {
	cout << "Nhung nguoi muon co sach het han: \n";
	for (size_t i = 0; i < danhsach.size(); i++) {
		if (danhsach[i] != NULL && danhsach[i]->expired()) {
			danhsach[i]->output();
		}
	}
}
void Library::count() {
	int SGK = 0, STT = 0;
	for (size_t i = 0; i < danhsach.size(); i++) {
		if (danhsach[i] != NULL) {
			SGK += danhsach[i]->count_SGK();
			STT += danhsach[i]->count_STT();
		}
	}
	if (SGK == STT) {
		cout << "So luong sach giao khoa va sach tieu thuyet bang nhau.\n";
	}
	else if (SGK > STT) {
		cout << "So luong sach giao khoa nhieu hon sach tieu thuyet.\n";
	}
	else {
		cout << "So luong sach giao khoa it hon sach tieu thuye.\n";
	}
}