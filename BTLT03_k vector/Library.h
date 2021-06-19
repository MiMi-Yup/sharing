#pragma once
#include "nguoi_muon.h"
class Library
{
private:
	int n;
	nguoi_muon** danhsach;
public:
	~Library();
	void input();
	void output();
	void expired();
	void count();
};

