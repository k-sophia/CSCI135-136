/**********
Assignment: Lab6-B

Write a program named caesar.cpp with functions 
implementing Caesar cipher encryption:
-   char shiftChar(char c, int rshift);
-   string encryptCaesar(string plaintext, int rshift);

Functions should preserve case, and any non-alphabetic 
characters should be left unchanged.

The main function should 
1. ask the user to input a plaintext sentence, 
2. ask the user to input the right shift 
3. report the ciphertext computed
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

    if (isalpha(old_char) && (old_char >= 65 && old_char <= 90)) { //uppercase
        if ((int)old_char+move > 90) { //loop after Z
            move = (int)old_char+move - 91;
            old_char = 'A';
        }
        new_char = (int)old_char + move; //shift
    }
    else if (isalpha(old_char) && (old_char >= 97 && old_char <= 122)) { //lowercase
        if ((int)old_char+move > 122) { //loop after z
            move = (int)old_char+move - 123;
            old_char = 'a';
        }
        new_char = (int)old_char + move; //shift
    }
    else { //space
        return old_char;
    }

    return new_char;
}

/*
    Caesar cipher encryption
    @rshift:    the magnitude of the right shift
                assumed range: 0 ≤ rshift ≤ 25
*/
string encryptCaesar(string plaintext, int rshift){
    string new_text;
    string old_text = plaintext;
    int move = rshift;

    for(int i = 0; i < old_text.length(); i++) { //loop per char
        new_text += shiftChar(old_text[i], move); //add ciphered char
    }

    return new_text;
}

int main() {
    string s;
    cout << "Enter plaintext: ";
    getline(cin, s);

    int shift;
    cout << "Enter shift    : ";
    cin >> shift;

    cout << "Ciphertext     : " << encryptCaesar(s, shift) << endl;
}