/**********
Assignment: Lab2C

Write a program edit-array.cpp that creates an array 
of 10 integers, and provides the user with an 
interface to edit any of its elements. 

Should work as follows:
1. Create an array myData of 10 integers
2. Fill all its cells with value 1 (using a for loop)
3. Print all elements of the array on the screen
4. Ask the user to input the cell index i, and its new value v
5.1 If the index i is within the array range (0 ≤ i < 10)
    update the asked cell, myData[i] = v, and go back to the step 3
5.2 Otherwise, if index i is out of range
    the program exits
**********/

#include <iostream>
using namespace std;

int main()
{
	int myData[10];// create array
	int i, v; //create variables 

	for (int n = 0; n < 10; n++) {
		myData[n] = 1;// change values to 1
		cout << myData[n] << " "; //print values
	}
	    
	cout << "\n\nInput index: "; //ask for index
    cin >> i;// get index

    cout << "Input value: "; //ask for value
    cin >> v;//get value

	while (0<= i && i< 10) { //while within array range
	    myData[i] = v; //update the asked cell
	    
        cout << endl;
	    for (int n = 0; n < 10; n++) { //print array elements
		    cout << myData[n] << " ";
	    }
	    
	    cout << "\n\nInput index: ";
        cin >> i;

        cout << "Input value: ";
        cin >> v;
	}
	
	cout << "\nIndex out of range. Exit.\n";
}