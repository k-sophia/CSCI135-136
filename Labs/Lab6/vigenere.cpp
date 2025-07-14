/**********
Assignment: Lab6-C

Write a program named vigenere.cpp that contain a 
function encryptVigenere implementing this cipher:
-   string encryptVigenere(string plaintext, string keyword);

The main function should
1. the user enters the plaintext 
2. the user enters the keyword
3. reports the ciphertext
**********/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
    A helper function to shift one character by rshift
    @rshift:    the magnitude of the right shift
                assumed range: 0 ≤ rshift ≤ 25
*/
char shiftChar(char c, int rshift) {
    char new_char;
    char old_char = c;
    int move = rshift;

    if (isalpha(old_char) && (old_char >= 'A' && old_char <= 'Z')) { //uppercase
        int shifted_char_upper = (int)old_char+move;
        if (shifted_char_upper > 'Z') { //loop after Z
            move = shifted_char_upper - 'Z';
            old_char = 'A';
        }
        new_char = (int)old_char + move; //shift
    }
    else if (isalpha(old_char) && (old_char >= 'a' && old_char <= 'z')) { //lowercase
        int shifted_char_lower = (int)old_char+move;
        if (shifted_char_lower > 'z') { //loop after z
            move = shifted_char_lower - 'z';
            old_char = 'a';
        }
        new_char = (int)old_char + move; //shift
    }
    else { //non alpha char
        return old_char;
    }

    return new_char;
}

/*
    Vigenere cipher encryption
    @keyword:   contains only lowercase alphabetic characters (a-z)
*/
string encryptVigenere(string plaintext, string keyword) { //loop per char
    string new_text;
    string old_text = plaintext;
    string word = keyword;
 
    for (int i = 0, j = 0; i < old_text.length(); ++i) {
        if (j >= word.length()) {
            j = 0;
        }

        if (isalpha(old_text[i])) {
            int move = word[j] - 'a';
            new_text += shiftChar(old_text[i], move); //add ciphered char
            j++;
        }
        else {
            new_text += old_text[i]; //add non alpha char
        }
    }

    return new_text;
}

int main() {
    string s;
    cout << "Enter plaintext: "; //ask
    getline(cin, s); //get line

    string keyword;
    cout << "Enter keyword  : ";
    cin >> keyword; //get keyword

    cout << "Ciphertext     : " << encryptVigenere(s, keyword) << endl; //print new text

}
