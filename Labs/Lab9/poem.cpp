/**********
Assignment: Lab9-D

Given program, poem.cpp, the memory is allocated
dynamically, but it crashes your computer, because
it runs out of memory really quickly.

Fix this program. It should still keep creating
poems, but all dynamically allocated memory should
get deleted when it is not needed.

The program can be stopped with Ctrl+C.
**********/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;
    }
}