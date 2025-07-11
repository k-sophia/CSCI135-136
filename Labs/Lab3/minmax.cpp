/**********
Assignment: Lab3-B

Write a program named minmax.cpp that finds the 
minimum and maximum storage in East basin in 2018.
**********/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
	string date;
    double min = 1000, max = 0;
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

        if (eastSt > max){ //if bigger storage
            max = eastSt;
        }
        
        if (eastSt < min) {//if smaller storage
            min = eastSt;
        } 
	}
    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;
	
    fin.close();
}