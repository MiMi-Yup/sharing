#include "nguoi_muon.h"

int _menu() {
	int choose;
	do {
		cout<<"\tLoai sach:"
			<<"\n\t1.Sach giao khoa."
			<<"\n\t2.Sach tieu thuyet."
			<<"\n\tChon loai : ";
		cin >> choose;
		if (choose < 1 || choose>2) {
			cout << "Khong hop le, nhap lai.\n";
			system("pause");
		}
	} while (choose < 1 || choose>2);
	cin.ignore();
	return choose;
}

nguoi_muon::nguoi_muon() {
	so_sach = 0;
	danhsach = NULL;
}
nguoi_muon::~nguoi_muon() {
	for (int i = 0; i < so_sach; i++) {
		if (danhsach[i] != NULL) {
			delete danhsach[i];
		}
	}
	delete danhsach;
}

void nguoi_muon::input() {
	system("cls");
	Book* temp = NULL;
	cout << "Nhap ho va ten: "; getline(cin, name);
	cout << "Nhap CMND: "; getline(cin, cmnd);
	cout << "Nhap so dien thoai: "; getline(cin, sdt);
	do {
		cout << "Nhap so sach muon muon: ";
		cin >> so_sach;
		if (so_sach < 0 || so_sach>4) {
			cout << "Khong hop le, nhap lai.\n";
		}
	} while (so_sach < 0 || so_sach>4);
	cin.ignore();
	danhsach = new Book * [so_sach];
	for (int i = 0; i < so_sach; i++) {
		switch (_menu())
		{
		case 1:
			temp = new SGK;
			if (temp != NULL) {
				temp->input();
				danhsach[i] = temp;
			}
			break;
		case 2:
			temp = new STT;
			if (temp != NULL) {
				temp->input();
				danhsach[i] = temp;
			}
			break;
		default:
			break;
		}
	}
	system("pause");
}
void nguoi_muon::output() {
	cout << "Ho va ten: " << name << "\n";
	cout << "CMND: " << cmnd << "\n";
	cout << "So dien thoai: " << sdt << "\n";
	cout << "So sach muon: " << so_sach << "\n";
	for (int i = 0; i < so_sach; i++) {
		if (danhsach[i] != NULL) {
			danhsach[i]->output();
		}
	}
}

bool nguoi_muon::expired(Date now) {
	for (int i = 0; i < so_sach; i++) {
		if (danhsach[i] != NULL) {
			if (danhsach[i]->expired(now)) {
				return true;
			}
		}
	}
	return false;
}
int nguoi_muon::count_SGK() {
	int count = 0;
	for (int i = 0; i < so_sach; i++) {
		if (danhsach[i] != NULL && danhsach[i]->flag == 1) {
			count++;
		}
	}
	return count;
}

int nguoi_muon::count_STT() {
	int count = 0;
	for (int i = 0; i < so_sach; i++) {
		if (danhsach[i] != NULL && danhsach[i]->flag == 2) {
			count++;
		}
	}
	return count;
}