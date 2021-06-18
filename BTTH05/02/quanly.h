#pragma once
#include <vector>
#include "SVDH.h"
#include "SVCD.h"
class quanly
{
private:
	vector<SV*> list;
public:
	~quanly();
	void input();
	void output();
	int passed_counter();
	SVDH* maxAvg_score();
};

