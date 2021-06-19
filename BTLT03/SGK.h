#pragma once
#include "Book.h"
class SGK :public Book {
private:
	string mon_hoc;
public:
	SGK();
	void input();
	void output();
};
