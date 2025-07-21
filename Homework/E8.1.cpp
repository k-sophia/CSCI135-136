/**********
Write a program that carries out the following tasks:
1. Open a file with the name hello.txt
2. Store the message "Hello, World!" in the file
3. Close the file
4. Open the same file again
5. Read the message into a string variable and print it
**********/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fin; // output file stream
    fin.open("hello.txt"); // Open a file named hello.txt
	if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
	}

    fin << "Hello, World!"; //store message in file
    fin.close(); //close file

    ifstream fin_again; //input file stream
    fin_again.open("hello.txt");//open file again
    if (fin_again.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
	}

	string hello;
	getline(fin_again, hello); // read one line from the file
    cout << hello << endl;

    fin_again.close(); //close file
}