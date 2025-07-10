/**********
Assignment: Lab1A

Write a program named smaller.cpp that asks the 
user to input two integer numbers and prints out 
the smaller of the two.
**********/

#include <iostream>
using namespace std;

int main()
{
	int one, two; //create variables

	cout << "Enter the first number: "; //ask for first number
	cin >> one; //enter first number
	
	cout << "Enter the second number: "; //ask for second number
	cin >> two; //enter second number

	cout << endl << "The smaller of the two is "; //statement of smaller number

	if (one > two) {
		cout << two << endl; //prints second number if smaller
	}
	else
		cout << one << endl; //prints first number if smaller
}