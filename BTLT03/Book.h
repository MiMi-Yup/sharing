#pragma once
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;
class Book {
protected:
	int gia;
	string ten_sach;
	string tac_gia;
	string nha_xuat_ban;
	string ngay_ra_mat;
	string vi_tri;
	Date ngay_muon;
public:
	int flag = 0;
	/// <summary>
	/// 1. Sach GK
	/// 2. Sach TT
	/// </summary>
	Book();
	virtual void input();
	virtual void output();
	bool expired(Date now);
};
