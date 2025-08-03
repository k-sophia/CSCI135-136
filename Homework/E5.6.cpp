/**********
Write a function, string middle(string str), that
returns a strong continaing
-   the middle character if the length is odd
-   the two middle characters if the length is even
**********/

#include <iostream>
#include <string>
using namespace std;

string middle(string str) {
    string mid = "";

    if (str.length()%2 != 0){
        mid += str[str.length()/2];
    }
    else {
        mid += str[str.length()/2 -1];
        mid += str[str.length()/2];
    }

    return mid;
}

int main() {
    string str;
    cout << "Enter String: ";
    cin >> str;
    cout << "\nMiddle string is " << middle(str) << endl;
}