/**********
Assignment: Lab1-B

Write a program named smaller3.cpp that asks the
user to input three integer numbers, and prints
out the smallest of the three.
**********/

#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	cout << "Enter the third number: ";
	cin >> num3;

	cout << endl << "The smaller number is ";
	if (num1 < num2 and num1 < num3) {
		cout << num1; //prints first number if smaller
	}
	else if (num2 < num1 and num2 < num3) {
		cout << num2; //prints second number if smaller
	}
	else {
		cout << num3; //print third number
	}
	cout << endl;
}