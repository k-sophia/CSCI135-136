/**********
Assignment: Lab1-D

Write a program named month.cpp that asks the user
to input the year and the month (1-12) and prints
the number of days in that month (taking into
account leap years).

May not use switch case or arrays.
**********/

#include <iostream>
using namespace std;

int main()
{
	int month, year;
	cout << "Enter year: ";
	cin >> year;
    cout << "Enter month: ";
	cin >> month;

    cout << "\nThere are ";
	if (month==1) {
	    cout << "31 Days\n";
	}
    else if (month==2) { //if february
        if (year%4 != 0) { //if its a common year
			cout << "28 Days\n";
		}
		else if (year%100 != 0) { //if its a leap year
			cout << "29 Days\n";
		}
		else if (year %400 != 0) { //if its a common year
			cout << "28 Days\n";
		}
		else { //if its a leap year
			cout << "29 Days\n";
        }
    }
    else if (month==3) {
        cout << "31 Days\n";
    }
    else if (month==4) {
        cout << "30 Days\n";
    }
    else if (month==5) {
        cout << "31 Days\n";
    }
    else if (month==6) {
        cout << "30 Days\n";
    }
    else if (month==7) {
        cout << "31 Days\n";
    }
    else if (month==8) {
        cout << "31 Days\n";
    }
    else if (month==9) {
        cout << "30 Days\n";
    }
    else if (month==10) {
        cout << "31 Days\n";
    }
    else if (month==11) {
        cout << "30 Days\n";
    }
    else if (month==12) {
        cout << "31 Days\n";
    }
}