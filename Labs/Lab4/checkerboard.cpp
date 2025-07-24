/**********
Assignment: Lab4-B

Write a program named checkerboard.cpp that asks
the user to input width and height and prints a
rectangular checkerboard of the requested size
using asterisks and spaces (alternating).
**********/

#include <iostream>
using namespace std;

int main()
{
	int width, height;
	cout << "Input Width: ";
	cin >> width;
	cout << "Input Height: ";
	cin >> height;

	cout << "\nShape:\n";
	for (int row = 0; row < height; row++) { // for height
		for (int col = 0; col < width; col++) { // for width

			if(row%2 != 0) { //odd row
				if(col%2 != 0) { //odd col
					cout << "*";
				}
				else { //even col
					cout << " ";
				}
			}
			else { //even row
				if(col%2 != 0) { //odd col
					cout << " ";
				}
				else { //even col
					cout << "*";
				}
			}
		}
		cout << endl;
	}
}