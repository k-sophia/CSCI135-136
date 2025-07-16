#include <iostream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line) {
    int len = line.length(); //get length
    string fix = line;
    int i;// new var

    for (i = 0; i < len; i++) {
        if(!(isspace(fix[i]))) { //loop till get non space
            break;
        }
    }

    return fix.substr(i, len); //return first onpsace onward
}

int countChar(string line, char c) {
    int len = line.length(); //get length
    string fix = line;
    int space = 0;

    for (int i = 0; i < len; i++) {
        if(fix[i] == c) { //loop till get non space
            space++;
        }
    }

    return space;
}

int main() {
    string code; //make var
    int indent = 0;
    
    while(getline(cin, code)) { //go to each line
        code = removeLeadingSpaces(code); //get code no pre space

        if(code[0] == '}') { //minus if end
            indent--; //decrease
        }

        for (int i = 0; i < indent; i++) { //tabs
            cout << "\t";
        }

        cout << code << endl; //print fix code

        indent += countChar(code, '{') - countChar(code, '}');

        if(code[0] == '}') { //minus if end
            indent++; //decrease
        }
        
    }   
}