#include "Library.h"

Library::~Library() {
	for (int i = 0; i < n; i++) {
		if (danhsach[i] != NULL) {
			delete danhsach[i];
		}
	}
	delete danhsach;
}
void Library::input() {
	nguoi_muon* temp = NULL;
	cout << "Nhap so luong nguoi muon: ";
	cin >> n;
	cin.ignore();
	danhsach = new nguoi_muon * [n];
	for (int i = 0; i < n; i++) {
		temp = new nguoi_muon;
		if (temp != NULL) {
			temp->input();
			danhsach[i] = temp;
		}
	}
}
void Library::output() {
	cout << "Nhan sach nguoi muon: \n";
	for (int i = 0; i < n; i++) {
		cout << "\n<<<Nguoi muon thu " << i << ">>>\n";
		if (danhsach[i] != NULL) {
			danhsach[i]->output();
		}
	}
}
void Library::expired() {
	Date temp;
	cout << "Nhap ngay hien tai: "; temp.input();
	cout << "Nhung nguoi muon co sach het han: \n";
	for (int i = 0; i < n; i++) {
		if (danhsach[i] != NULL && danhsach[i]->expired(temp)) {
			cout << "\n<<<Nguoi muon>>>\n";
			danhsach[i]->output();
		}
	}
}
void Library::count() {
	int SGK = 0, STT = 0;
	for (int i = 0; i < n; i++) {
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