/**********
Assignment: Lab4-C

Write a program named cross.cpp that asks the user 
to input the shape size, and prints a diagonal cross 
of that dimension.
**********/

#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "Input size: ";
	cin >> size;

	cout << "\nShape:\n";
	for (int row = 0; row < size; row++) { // for height
		for (int col = 0; col < size; col++) { // for width
            int back = size - row; //index for back slash

			if(row == col) {//first slash
				cout << "*";
			}
			else if (back == col +1) { //back slash
				cout << "*";
			}
			else {
				cout << " "; //nothing
			}
		}
		cout << endl;
	}
}