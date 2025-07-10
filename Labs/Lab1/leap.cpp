/**********
Assignment: Lab1-C

Write a program named leap.cpp that asks the user 
to input an integer representing a year number 
(1999, 2016, etc.)

If the input year is a leap year according to the 
modern Gregorian calendar, it should print Leap 
year, otherwise, print Common year.
**********/

#include <iostream>
using namespace std;

int main()
{
	int year; //create variable
	
	cout << "Enter year: "; //ask year number
	cin >> year; //get year

	cout << endl;
	if (year%4 != 0) { //if not divisible by 4
		cout << "Common year"; //prints common year
	}
	else if (year%100 != 0) { //if not divisible by 100
		cout << "Leap year"; //prints leap year
	}
	else if (year %400 != 0) { //if not divisible by 400
		cout << "Common year"; //prints common year
	}
	else
		cout << "Leap year"; //prints common year
	
	cout << endl;
}