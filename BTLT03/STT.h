#pragma once
#include "Book.h"
class STT :
    public Book{
private:
	string chu_de;
	string nhan_vat_chinh;
public:
	STT();
	void input();
	void output();
};
