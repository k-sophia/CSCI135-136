/**********
Assignment: Lab7-B

Write a new program, indent.cpp, that can fix
indentation in C/C++ source code files.

Write a function:
-   int countChar(string line, char c);

As it reads the input line by line, it should also
- count the number of open and closed { } in it
- keep track of how many blocks is currently open at
    the beginning of each line

Shortcomings of our program:
- No support for loops and if statements that don’t have curly braces
- Symbols {, } inside string and char literals are misinterpreted as blocks
**********/

#include <iostream>
#include <cctype>
using namespace std;

/*
    @line:      single line of code
    @return:    same line with leading spaces removed
*/
string removeLeadingSpaces(string line) {
    int len = line.length();
    string fix = line;
    int i;

    for (i = 0; i < len; i++) {
        if(!(isspace(fix[i]))) { //loop till get non space
            break;
        }
    }

    return fix.substr(i, len); //return first non space character onward
}

/*
    @line:      single line of code
    @return:    the number of times character c appears in the line
*/
int countChar(string line, char c) {
    int len = line.length();
    string fix = line;
    int count = 0;

    for (int i = 0; i < len; i++) {
        if(fix[i] == c) {
            count++;
        }
    }

    return count;
}

int main() {
    string code;
    int indent = 0;

    while(getline(cin, code)) { //go to each line
        code = removeLeadingSpaces(code); //get code with leading spaces removed

        indent -= countChar(code, '}'); //remove indent
        for (int i = 0; i < indent; i++) { //print tabs
            cout << "\t";
        }

        cout << code << endl; //print fix code
        indent += countChar(code, '{'); //add indent
    }
}