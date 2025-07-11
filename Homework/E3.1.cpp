/**********
Write a program that reads an integer and prints
whether it is negative, zero, or positive.
**********/

#include <iostream>
using namespace std;

int main()
{
	int num;
    cout << "Enter Number: ";
    cin >> num;

    cout << "\nNumber is ";
    if (num < 0) {
        cout << "Negative" << endl;
    }
    else if (num == 0) {
        cout << "Zero" << endl;
    }
    else if (num > 0) {
        cout << "Positive" << endl;
    }
}