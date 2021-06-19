#include "Date.h"
#include <iostream>
using namespace std;


bool check(int day, int month, int year) {
	if (month > 12 || month < 0 ||
		year < 0 ||
		day > 31 || day < 0) {
		cout << "Khong hop le";
		return false;
	}
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (day > 31) {
			cout << "Ngay khong hop le";
			return false;
		}
		break;
	case 2:
		if (year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0)) {
			if (day > 29) {
				cout << "Ngay khong hop le";
				return false;
			}
		}
		break;
	default:
		if (day > 30) {
			cout << "Ngay khong hop le";
			return false;
		}
		break;
	}
	return true;
}
void cab_sub(int& day, int& month, int& year) {
	while (month < 0) {
		month += 12;
		year--;
	}
repeat:	switch (month)
{
case 1:case 2:case 4:case 6:case 8:case 9:case 11:
	if (day < 0) {
		day += 31;
		month--;
		if (month < 0) {
			month = 12;
			year--;
		}
		goto repeat;
	}
	break;
case 3:
	if (day < 0) {
		if (year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0)) {
			day += 29;
			month--;
			goto repeat;
		}
		else {
			day += 28;
			month--;
			goto repeat;
		}
	}
	break;
default:
	if (day < 0) {
		day += 30;
		month--;
		goto repeat;
	}
	break;
}
}

Date::Date(Date& A) {
	this->day = A.day;
	this->month = A.month;
	this->year = A.year;
}
Date::Date(int day, int month, int year) {
	if (check(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
}
int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}
Date Date::sub(Date A) {
	int day = this->day - A.getDay();
	int month = this->month - A.getMonth();
	int year = this->year - A.getYear();
	cab_sub(day, month, year);
	Date temp(day, month, year);
	return temp;
}
void Date::input() {
lable:	int Date[3];
	string name[3] = { "Ngay: ","Thang: ","Nam: " };
	cout << "\nNhap: \n";
	for (int i = 0; i < 3; i++) {
		cout << "\t" << name[i];
		cin >> Date[i];
		if (Date[i] < 0) {
			cout << "Vui long nhap so lon hon khong!";
			i--;
		}
	}
	if (check(Date[0], Date[1], Date[2])) {
		this->day = Date[0];
		this->month = Date[1];
		this->year = Date[2];
	}
	else {
		cout << "Ngay khong hop le. Nhap lai.";
		goto lable;
	}
	cin.ignore();
}
void Date::output() {
	cout << "\nDate: " << day << "/" << month << "/" << year;
}