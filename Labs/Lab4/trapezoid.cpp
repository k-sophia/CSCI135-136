/**********
Assignment: Lab4-F

Write a program named trapezoid.cpp that prints an
upside-down trapezoid of given width and height.

If the input height is impossibly large for the
given width, then print "Impossible shape!"
**********/

#include <iostream>
using namespace std;

int main()
{
	int width, height;
	cout << "Input width: ";
	cin >> width;
    cout << "Input height: ";
    cin >> height;

	bool evenHeightCheck = height%2 == 0 and height > width/2;
	bool oddHeightCheck = height%2 != 0 and height > (width+1)/2;
	if (evenHeightCheck or oddHeightCheck) {
		cout << "\nImpossible Shape!\n";
	}
	else {
		cout << "\nShape (Method 1):\n";
		for (int row = 0; row < height; row++) { //for height
			for (int col = 0; col < width; col++) { //for width
				int back = width - row; //index for back slash

				if(row <= col and back > col) { //within front and back slash
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}

		cout << "\nShape (Method 2):\n";
		int spaces = 0;
		int stars = width;
		for (int row = 0; row < height; row++) { //for height
			string test = "";
			test.insert(0, stars, '*');
			test.insert(0, spaces, ' ');
			spaces += 1;
			stars -= 2;
			cout << test << endl;
		}
	}
}