/**********
Assignment: Lab4-A

Write a program named box.cpp that asks the user to 
input width and height and prints a solid rectangular 
box of the requested size using asterisks.

Print a line 'Shape:' between user input and the 
printed shape to separate input from output.
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
	for (int row = 0; row < height; row++) { // for hieght
		for (int col = 0; col < width; col++) { // for width
			cout << "*";
		}
		cout << endl;
	}
}