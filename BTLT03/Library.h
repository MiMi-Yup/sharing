#pragma once
#include "nguoi_muon.h"
class Library
{
private:
	vector<nguoi_muon*> danhsach;
public:
	~Library();
	void input();
	void output();
	void expired();
	void count();
};

