/**********
Assignment: Lab2-A

Write a program named valid.cpp, which asks the
user to input an integer in the range 0 < n < 100.

If the number is out of range, the program should
keep asking to re-enter until a valid number is
input.

After a valid value is obtained, print this number
n squared.
**********/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Please enter an integer: ";
	cin >> n;

	while(n <= 0 or n >= 100) { //if less than 0 or greater than 100
		cout << "Please re-enter: "; //ask for int again
		cin >> n; //get int again
	}

	cout << "\nNumber squared is ";
	cout << pow(n, 2) << endl; //print int squared
}