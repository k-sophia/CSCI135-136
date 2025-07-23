/**********
Assignment: Lab7-A

Write a program called unindent.cpp, that reads
input from cin and prints out each input line with
leading spaces removed.

Make use of the function isspace defined in <cctype>
to check if a character is a whitespace.
**********/

#include <iostream>
#include <cctype>
using namespace std;

/*
    @line:      single line of code
    @return:    same line with leading spaces removed
*/
string removeLeadingSpaces(string line) {
    int len = line.length(); //get length
    string fix = line;
    int i;

    for (i = 0; i < len; i++) {
        if(!(isspace(fix[i]))) { //loop till get non space
            break;
        }
    }

    return fix.substr(i, len); //return first non space character onward
}

int main() {
    cout << "Unindented file:\n";
    string code;
    while(getline(cin, code)) {
        cout << removeLeadingSpaces(code) << endl;
    }
}