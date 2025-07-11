/**********
Assignment: Lab4-D

Write a program named lower.cpp that prints the 
bottom-left half of a square, given the side length.
**********/

#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "Input size: ";
	cin >> size;

	cout << "\nShape:\n";
	for (int row = 0; row < size; row++) { //for height
		for (int col = 0; col < size; col++) { //for width
			if(row >= col) { //from front slash and down
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}