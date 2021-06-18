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
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay();
	int getMonth();
	int getYear();
	void add(int);
	void sub(int);
	Date sub(Date);
	void increase();
	void decrease();
	void input();
	void output();
};
