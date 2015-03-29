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
		if (M > 12 || D > 31){
			upDate();
		}
		else{
			s = new int[3];
			s[0] = D;
			s[1] = M;
			s[2] = Y;
		}
		dateCount++;
	}
	upDate::upDate(const upDate& D){ //copy Constructor
		s = new int[3];
		for (int i = 0; i < 3; i++){
			s[i] = D.s[i];
		}
		juliand = D.julian();
		dateCount++;
	}
	upDate::~upDate(){
		delete[] s;
		dateCount--;
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
		int juliandate = s[0] - 32075 + 1461 * (s[2] + 4800 + (s[1] - 14) / 12) / 4 + 367 * (s[1] - 2 - (s[1] - 14) / 12 * 12) / 12 - 3 * ((s[2] + 4900 + (s[1] - 14) / 12) / 100) / 4;
		return juliandate;
	}
	upDate upDate::gregorian(int JD){
		int L, N, K, J, I;
		L = JD + 68569;
		N = 4 * L / 146097;
		L = L - (146097 * N + 3) / 4;
		I = 4000 * (L + 1) / 1461001;
		L = L - 1461 * I / 4 + 31;
		J = 80 * L / 2447;
		K = L - 2447 * J / 80;
		L = J / 11;
		J = J + 2 - 12 * L;
		I = 100 * (N - 49) + I + L;
		upDate D(J, K, I);
		return D;
		//s[0] = K;
		//s[1] = J;
		//s[2] = I;
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
		upDate D(lhs.s[1], newDay, lhs.s[2]);
		return D;
	}
	upDate operator++(const upDate &lhs, const int test){
		int current = lhs.s[0];
		int newDay = current++;
		upDate D(lhs.s[1], newDay, lhs.s[2]);
		return D;
	}
	upDate operator--(const upDate &lhs, const int test){
		int current = lhs.s[0];
		int	newDay = current--;
		upDate D(lhs.s[1], newDay, lhs.s[2]);
		return D;
	}
	upDate operator+=(const upDate &lhs, const int &rhs){
		int temp = lhs.julian();
		temp += rhs;
		upDate D;
		return D.gregorian(temp);
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



