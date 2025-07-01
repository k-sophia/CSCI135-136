// month.cpp

#include <iostream>
using namespace std;

int main()
{
	int month, year; //create variables
	
	cout << "Enter year: "; //ask year number
	cin >> year; //get year

    cout << "Enter month: "; //ask for month number
	cin >> month; //get month
	
	if (month==1) {
	    cout << "31 Days";
	}
    else if (month==2) { //if february
        if (year%4 != 0) { //if not divisible by 4
			cout << "28 Days"; //prints common year
		}
		else if (year%100 != 0) { //if not divisible by 100
			cout << "29 Days"; //prints leap year
		}
		else if (year %400 != 0) { //if not divisible by 400
			cout << "28 Days"; //prints common year
		}
		else
			cout << "29 Days"; //prints common year
		
    }
    else if (month==3) {
        cout << "31 Days";
    }
    else if (month==4) {
        cout << "30 Days";
    }
    else if (month==5) {
        cout << "31 Days";
    }
    else if (month==6) {
        cout << "30 Days";
    }
    else if (month==7) {
        cout << "31 Days";
    }
    else if (month==8) {
        cout << "31 Days";
    }
    else if (month==9) {
        cout << "30 Days";
    }
    else if (month==10) {
        cout << "31 Days";
    }
    else if (month==11) {
        cout << "30 Days";
    }
    else if (month==12) {
        cout << "31 Days";
    }
}