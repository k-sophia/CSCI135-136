/**********
Assignment: Lab3-A

Write a program named east-storage.cpp that asks
the user to input a string representing the date
(in MM/DD/YYYY format), and prints out the East
basin storage on that day.
**********/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
	string date, date_check;
	cout << "Enter date: ";
	cin >> date_check;

	double eastSt, eastEl, westSt, westEl;

	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) { // exit if failed to open the file
   		cerr << "File cannot be opened for reading." << endl;
   		exit(1);
	}

	string junk;        // new string variable
	getline(fin, junk); // read one line from the file

	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    	// this loop reads the file line-by-line
    	// extracting 5 values on each iteration

    	fin.ignore(INT_MAX, '\n');	//skips to the end of line,
                          			//ignorring the remaining columns

        if (date == date_check) {
         	cout << "East basin storage: " << eastSt << " billion gallons\n";
        }
	}

	fin.close();
}