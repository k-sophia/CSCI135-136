/**********
Write a program that reads three numbers and prints
-   "increasing" if they are in increasing order,
    where each value is larger than its predecessor
-   "decreasing" if they are in decreasing order
-   "neither" otherwise
**********/

#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;

    cout << "\nOrder is ";
    if (num1 < num2 and num2 < num3) {
        cout << "Increasing" << endl;
    }
    else if (num1 > num2 and num2 > num3) {
        cout << "Decreasing" << endl;
    }
    else {
        cout << "Neither" << endl;
    }
}