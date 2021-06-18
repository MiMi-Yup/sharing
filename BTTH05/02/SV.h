#pragma once
#include <string>
using namespace std;
class quanly;
class SV
{
protected:
	int MSSV;
	string name;
	string address;
	int credit;
	float avg_score;
public:
	short flag = 0;
	/// <summary>
	/// 1. Sinh vien dai hoc
	/// 2. Sinh vien cao dang
	/// </summary>
	SV();
	SV(int, string, string, int, float);
	void input();
	void output();
	float getAvg_score();
	int getMSSV();
	bool passed() {}
};

