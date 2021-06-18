#include "PS.h"

PS::PS(int tuso, int mauso) {
	this->tuso = tuso;
	this->mauso = mauso;
}
PS::PS(const PS& ps) {
	this->tuso = ps.tuso;
	this->mauso = ps.mauso;
}
int PS::UCLN(int a, int b) {
	while (a * b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}
istream& operator>>(istream& is, PS& ps) {
	do {
		cout << "Nhap tu so: ";
		is >> ps.tuso;
		cout << "Nhap mau so khac 0: ";
		is >> ps.mauso;
		if (ps.mauso == 0)cout << "Phan so khong hop le, nhap lai.\n";
	} while (ps.mauso == 0);
	return is;
}
ostream& operator<<(ostream& os, PS ps) {
	os << ps.getTu() << "/" << ps.getMau() << "\n";
	return os;
}
int PS::getTu() {
	return this->tuso;
}
int PS::getMau() {
	return this->mauso;
}
void PS::setTu(int tuso) {
	this->tuso = tuso;
}
void PS::setMau(int tuso) {
	if (tuso != 0) {
		this->tuso = tuso;
	}
	else {
		cout << "Cap nhap that bai.\n";
	}
}
void PS::Shorter() {
	int uc = UCLN(tuso, mauso);
	tuso /= uc;
	mauso /= uc;
}
PS& PS::operator++() {
	this->tuso += mauso;
	this->Shorter();
	return *this;
}
PS PS::operator++(int) {
	PS temp(*this);
	this->tuso += mauso;
	this->Shorter();
	return temp;
}