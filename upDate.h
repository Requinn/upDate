#ifndef upDate_H
#define upDate_H
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class upDate{
private:
	int day, month, year, juliand;
	int* s;
public:
	/*Default constructor*/
	upDate(); 
	/*overloaded consturctor*/
	upDate(int M, int D, int Y);
	/*copy constructor*/
	upDate(const upDate& D);
	/*deleter function*/
	~upDate();
	/*date setter*/
	void setDate(int M, int D, int Y);
	/*month getter*/
	int getMonth();
	/*day getter*/
	int getDay();
	/*year getter*/
	int getYear();
	/*converts date to julian int*/
	int julian() const;
	int julian(int M, int D, int Y) const;
	/*converts julian to gregorian*/
	upDate gregorian(int JD);
	/*returns the number of dates in the system*/
	static int GetDateCount();
	/*returns the name of the month*/
	string getMonthName();
	/*returns an object that is called after a << in the MM/DD/YYYY format*/
	friend ostream &operator<<(ostream &output, const upDate &D);
	/*overloads the + unary operation, allowing the addition of days*/
	friend upDate operator+(const upDate &lhs, const int &rhs);
	friend upDate operator+(const int &lhs, const upDate &rhs);
	/*overloads the - unary operation, allowing the subtraction of days*/
	friend upDate operator-(const upDate &lhs, const int &rhs);
	/*the same, except between two dates. essentially the days between*/
	friend int operator-(const upDate &lhs, const upDate &rhs);
	/*pre-increment overloader*/
	friend upDate operator++(const upDate &lhs);
	/*post-increment overloader*/
	friend upDate operator++(const upDate &lhs, const int test);
	/*pre-decrement overloader*/
	friend upDate operator--(const upDate &lhs);
	/*post-decrement overloader*/
	friend upDate operator--(const upDate &lhs, const int test);
	/*overloader for the += unary operation*/
	upDate& operator+=(int rhs);
	/*overloader for the greater than comparison*/
	friend bool operator>(upDate &lhs, upDate &rhs);
	/*overloader for the less than comparison*/
	friend bool operator<(upDate &lhs, upDate &rhs);
	/*overloader for the equals to comparison*/
	friend bool operator==(upDate &lhs, upDate &rhs);
};
#endif