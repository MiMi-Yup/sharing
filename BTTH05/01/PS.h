#pragma once
#include <iostream>
using namespace std;

class PS
{
private:
	int tuso;
	int mauso;
	int UCLN(int, int);
public:
	PS(int = 0, int = 1);
	PS(const PS&);
	friend istream& operator>>(istream&, PS&);
	friend ostream& operator<<(ostream&, PS);
	int getTu();
	int getMau();
	void setTu(int);
	void setMau(int);
	void Shorter();
	PS& operator++();
	PS operator++(int);
};