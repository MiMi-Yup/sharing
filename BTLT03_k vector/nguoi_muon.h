#pragma once
#include <iostream>
#include <vector>
#include "SGK.h"
#include "STT.h"

using namespace std;
class nguoi_muon
{
private:
	string name;
	string cmnd;
	string sdt;
	int so_sach;
	Book** danhsach;
public:
	nguoi_muon();
	void input();
	void output();
	bool expired(Date);
	int count_SGK();
	int count_STT();
	~nguoi_muon();
};

