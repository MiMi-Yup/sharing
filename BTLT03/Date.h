#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(Date&);
	Date(int day = 1, int month = 1, int year = 1);
	int getDay();
	int getMonth();
	int getYear();
	Date sub(Date);
	void input();
	void output();
};
