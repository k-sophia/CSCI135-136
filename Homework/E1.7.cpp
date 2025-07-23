/**********
Write a program that asks the user for three items
and print them on three separate lines.
**********/

#include <iostream>
using namespace std;

int main ()
{
    cout << "Type a color: ";
    string a;
    cin >> a;

    cout << "Type a second color: ";
    string b;
    cin >> b;

    cout << "Type a third color: ";
    string c;
    cin >> c;

    cout << "Colors Given: " << endl;
    cout << a << endl << b << endl << c << endl;
}