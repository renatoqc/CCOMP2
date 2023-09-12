#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date {

private:
	int month;
	int day;
	int year;

public:

	Date(int month_, int day_, int year_) {
		month = month_;
		day = day_;
		year = year_;

		if (month < 1 || month > 12) {
			month = 1;
		}


	}

	void setMo(int month_) {
		month = month_;
	}
	void setDay(int day_) {
		day = day_;
	}
	void setYear(int year_) {
		year = year_;
	}

	int getMo() {
		return month;
	}
	int getDay() {
		return day;
	}
	int getYear() {
		return year;
	}

	void getdisplayDate() {

		cout << getMo() << " / " << getDay() << " / " << getYear();

	}
};
