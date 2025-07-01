// leap.cpp

#include <iostream>
using namespace std;

int main()
{
	int year; //create variable
	
	cout << "Enter year: "; //ask year number
	cin >> year; //get year

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
}