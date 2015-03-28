// upDate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "upDate.h"

using namespace std;
static int dateCount; 

	upDate::upDate(){
		s = new int[3];
		s[0] = 11;
		s[1] = 5;
		s[2] = 1959;
		dateCount++;
	}
	upDate::upDate(int M, int D, int Y){
		s = new int[3];
		s[0] = D;
		s[1] = M;
		s[2] = Y;
		dateCount++;
	}
	upDate upDate::operator+(const upDate& D){ //copy Constructor
		D.s[0]= this->s[0] + D.s[0];
		D.s[1] = this->s[1] + D.s[1];
		D.s[2] = this->s[2] + D.s[2];
		dateCount++;
		return D;
	}
	upDate::~upDate(){
		delete[] s;
		dateCount--;
		cout << "Date deleted!" << endl;
	}
	void upDate::setDate(int M, int D, int Y){
		s[0] = D;
		s[1] = M;
		s[2] = Y;
	}
	int upDate::getMonth(){
		return s[1];
	}
	int upDate::getDay(){
		return s[0];
	}
	int upDate::getYear(){
		return s[2];
	}
	int upDate::julian() const{
		int juliandate = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
		return juliandate;
	}
	int upDate::GetDateCount(){
		return dateCount;
	}
	string upDate::getMonthName(){
		string monthname[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		return monthname[month];
	}
	ostream &operator<<(ostream &output, const upDate &D){
		output << D.s[1]<<"/"<<D.s[0]<<"/"<<D.s[2];
		return output;
	}
	upDate operator+(const int &lhs, const upDate &rhs){
		int newDay = lhs + rhs.s[0];
		upDate D(rhs.s[1], newDay, rhs.s[2]);
		return D;
	}
	upDate operator+(const upDate &lhs, const int &rhs){
		int newDay = lhs.s[0] + rhs;
		upDate D(lhs.s[1], newDay, lhs.s[2]);
		return D;
	}

	upDate operator-(const upDate &lhs, const int &rhs){
		int newDay = lhs.s[0] - rhs;
		upDate D(lhs.s[1], newDay, lhs.s[2]);
		return D;
	}
	int operator-(const upDate &lhs, const upDate &rhs){
		int daysBetween = lhs.julian() - rhs.julian();
		return daysBetween;
	}
	upDate operator++(const upDate &lhs){
		int current = lhs.s[0];
		int newDay = current++;
		upDate D(lhs.s[1], newDay, lhs.s[2]);
		return D;
	}
	upDate operator--(const upDate &lhs){
		int current = lhs.s[0];
		int	newDay = current--;
		upDate D(lhs.s[0], newDay, lhs.s[2]);
		return D;
	}
	upDate operator++(const upDate &lhs, const int test){
		int current = lhs.s[0];
		int newDay = current++;
		upDate D(lhs.s[0], newDay, lhs.s[2]);
		return D;
	}
	upDate operator--(const upDate &lhs, const int test){
		int current = lhs.s[0];
		int	newDay = current--;
		upDate D(lhs.s[0], newDay, lhs.s[2]);
		return D;
	}
	int operator+=(const upDate &lhs, const int &rhs){
		return lhs.julian() + rhs;
	}
	bool operator>(upDate &lhs, upDate &rhs){
		return lhs.julian() > rhs.julian();
	}
	bool operator<(upDate &lhs, upDate &rhs){
		return lhs.julian() < rhs.julian();
	}
	bool operator==(upDate &lhs, upDate &rhs){
		return lhs.julian() == rhs.julian();
	}



