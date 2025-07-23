/**********
Assignment: Lab3-C

Write a program named compare.cpp that asks the user
to input two dates (the beginning and the end of
the interval).

The program should check each day in the interval
and report which basin had higher elevation on that
day by printing “East” or “West”, or print “Equal”
if both basins are at the same level.
**********/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
	string date, start_date, end_date;
    cout << "Enter starting date: ";
    cin >> start_date;
    cout << "Enter ending date: ";
    cin >> end_date;
    cout << endl;

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

        if (date >= start_date and date <= end_date){ //compare within date range
            if (eastEl > westEl) { // if east bigger
                cout << date << " East" << endl;
            }
            else if (eastEl < westEl) { //if west bigger
                cout << date << " West" << endl;
            }
            else {
                cout << date << " Equal" << endl; // if equal
            }
        }
	}
    fin.close();
}