/**********
Assignment: Lab1-A

Write a program named smaller.cpp that asks the
user to input two integer numbers and prints out
the smaller of the two.
**********/

#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;

	cout << endl << "The smaller of the two is ";
	if (num1 > num2) {
		cout << num2 << endl; //prints second number if smaller
	}
	else {
		cout << num1 << endl; //prints first number if smaller
	}
}