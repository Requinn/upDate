#include "stdafx.h"
#include "upDate.h"

int _tmain(int argc, _TCHAR* argv[])
{
	upDate D1(10, 27, 2010); // constructor 
	upDate D2(D1); // copy constructor

	upDate D3 = D2 + 5;  // add 5 days to D2

	upDate D4 = 5 + D2; // add 5 days to D2

	upDate D5 = D2 - 4;

	int x = D5 - D4; // how many days between D5 and D4. Can be negative or positive
	cout << D1 <<endl<< D2 <<endl<< D3 <<endl<< D4 <<endl<< D5 << endl;
	cout << "UpDate Testing - if no error message is displayed, The test is passed" << endl;

	if (D1 == D2) {}
	else cout << "***** operator== may not working correctly" << endl;

	if (D1 < D3) {}
	else cout << "***** operator< may not working correctly" << endl;

	if (D4>D5) {}
	else cout << "***** operator> may not working correctly" << endl;


	cout << upDate::GetDateCount() << endl; // a static method that returns the number of myDate objects that currently exist

	if (upDate::GetDateCount() != 5) cout << "***** GetDateCount function failed!" << endl;

	if (x != -9) cout << "***** - or + may not working correctly" << endl;


	cout << endl << "Display D1 for ++ testing: both dates must be the same" << endl;

	cout << ++D1 << endl; // also increment D1 by one day
	cout << D1++ << endl;	// increment D1 by one day

	cout << endl << "Display D1 for -- testing, both dates must be the same" << endl;

	cout << --D1 << endl; // decrement D1 by one day
	cout << D1-- << endl; // decrement D1 by one day

	if (D1 == D2) {}
	else cout << "***** increment and decrement operators may not working correctly" << endl;

	cout << endl << "For this test, Julian date should be 2455497: " << D1.julian() << endl; //print the Julian integer represented by D1

	int d1Int = D1.julian(), d3Int = D3.julian();
	if ((d3Int - d1Int) != (D3 - D1)) cout << "***** julien() may not working correctly" << endl;

	int numObj = upDate::GetDateCount();
	{
		upDate D6(5, 14, 2015), D7(5, 14, 2016);
		D6 += 366;
		if (D6 == D7) {}
		else cout << "***** += operator may not working correctly" << endl;

	}

	cout << endl << "Press Any Key to Exit";
	char c; cin >> c;
	return 0;
}