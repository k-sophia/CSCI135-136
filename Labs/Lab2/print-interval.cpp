/**********
Assignment: Lab2-B

Write a program named print-interval.cpp that asks 
the user to input two integers L and U, representing 
the lower and upper limits of the interval.

Print out all integers in the range L ≤ i < U 
separated by spaces.
- Include the lower limit
- Exclude the upper limit
**********/

#include <iostream>
using namespace std;

int main()
{
	int L, U, i; //create variables

	cout << "Please enter L: "; //ask for L, lower limit
	cin >> L; //get L

	cout << "Please enter U: "; //ask for U, upper limit
	cin >> U; //get U

    cout << endl;
	for (i = L; i < U; i++) { //if less than U
		cout << i << " "; //print between
	}
    cout << endl;
}