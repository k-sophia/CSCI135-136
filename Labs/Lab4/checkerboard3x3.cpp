/**********
Assignment: Lab4-G

Write a program named checkerboard3x3.cpp that asks 
the user to input width and height and prints a 
checkerboard of 3-by-3 squares. 

It should work even if the input dimensions are not 
a multiple of three.
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

	cout << "\nShape:\n";
	for (int row = 0; row < height; row++) { // for height
		for (int col = 0; col < width; col++) { // for width
			if((row/3)%2 == 0) { //if even row of three
				if((col/3)%2 == 0) { //if even col of three
				    cout << "*";
			    }
			    else { //if odd col of three
				    cout << " ";
			    }
			}
			else { //if odd row of three
				if((col/3)%2 == 0) { //if even col of three
				    cout << " ";
			    }
			    else { //if odd col of three
				    cout << "*";
			    }
			}
		}
		cout << endl;
	}
}