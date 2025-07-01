// smaller.cpp

#include <iostream>
using namespace std;

int main()
{
	int one, two; //create variables

	cout << "Enter the first number: "; //ask for first number
	cin >> one; //enter first number
	
	cout << "Enter the second number: "; //ask for second number
	cin >> two; //enter second number

	cout << "The smaller of the two is "; //statement of smaller number

	if (one > two) {
		cout << two; //prints second number if smaller
	}
	else
		cout << one; //prints first number if smaller
}