/**********
Write a program that reads a word and prints each
character of the word on a separate line.
**********/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;

    cout << "Enter Word: ";
    cin >> word;

    for(int i = 0; i < word.length(); i++) {
        cout << word[i] << endl;
    }
}