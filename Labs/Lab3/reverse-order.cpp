/**********
Assignment: Lab3-D

Write a program named reverse-order.cpp which asks 
the user to input two dates:
- earlier date 
- later date

Report the West basin elevation for all days in the 
interval in the reverse chronological order (from 
the later date to the earlier).
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
    cout << "Enter earlier date: ";
    cin >> start_date;
    cout << "Enter later date: ";
    cin >> end_date;
    cout << endl;

	int index = 0;
	string Wdate[500];
	double elevations[500];
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

        if (date >= start_date and date <= end_date) { //start compare
            Wdate[index] = date; //get date
            elevations[index] = westEl; //get elevations
            index++; //next index
        }
	}

	for(int i = index-1; i >= 0; i--) {

		cout << Wdate[i] << "  " << elevations[i] << " ft\n";
	}
    fin.close();
}