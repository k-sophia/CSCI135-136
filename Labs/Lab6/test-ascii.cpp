/**********
Assignment: Lab6-A

Write a program named test-ascii.cpp that asks the
user to input a line of text (which may possibly
include spaces).

The program should report all characters from the
input line together with their ASCII codes.

Print exactly one space between the character and it’s code.
**********/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Input: ";
    getline(cin, s); //extracts all characters until an end-of-line is reached

    cout << "\nOutput:\n";
    for(int i = 0; i < s.length(); i++) {
        cout << s[i] << " "; //print char
        cout << (int)s[i] << endl; //print ASCII
    }
}