/**********
Assignment: Lab1B

Write a program named smaller3.cpp that asks the 
user to input three integer numbers, and prints 
out the smallest of the three.
**********/

#include <iostream>
using namespace std;

int main()
{
	int one, two, three; //create variables

	cout << "Enter the first number: "; //ask for first number
	cin >> one; //enter first number
	
	cout << "Enter the second number: "; //ask for second number
	cin >> two; //enter second number

	cout << "Enter the third number: "; //ask for third number
	cin >> three; //enter third number

	cout << endl << "The smaller of the three is "; //statement of smaller number

	if (one < two and one < three) {
		cout << one; //prints first number if smaller
	}
	else if (two < one and two < three) {
		cout << two; //prints second number if smaller
	}
	else
		cout << three; //print third number	
	
	cout << endl;
}