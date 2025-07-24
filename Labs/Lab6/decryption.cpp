/**********
Assignment: Lab6-D

Implement two decryption functions corresponding to
the ciphers in Task B and C
-   decryptCaesar(ciphertext, rshift) == plaintext
-   decryptVigenere(ciphertext, keyword) == plaintext

When decrypting ciphertext, ensure that the produced
decrypted string is equal to the original plaintext
**********/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
    A helper function to shift one character by rshift
    @param rshift:  the magnitude of the right shift (0 ≤ rshift ≤ 25)
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
        else if (shifted_char_upper < 'A') { //loop before a
            move = shifted_char_upper - 'A';
            old_char = 'Z';
        }
        new_char = (int)old_char + move; //shift
    }
    else if (isalpha(old_char) && (old_char >= 'a' && old_char <= 'z')) { //lowercase
        int shifted_char_lower = (int)old_char+move;
        if (shifted_char_lower > 'z') { //loop after z
            move = shifted_char_lower - 'z';
            old_char = 'a';
        }
        else if (shifted_char_lower < 'a') { //loop before a
            move = shifted_char_lower - 'a';
            old_char = 'z';
        }
        new_char = (int)old_char + move; //shift
    }
    else { //non alpha char
        return old_char;
    }

    return new_char;
}

/*
    Caesar cipher encryption
    @param rshift:  the magnitude of the right shift (0 ≤ rshift ≤ 25)
*/
string encryptCaesar(string plaintext, int rshift){
    string new_text;
    string old = plaintext;
    int move = rshift;

    for(int i = 0; i < old.length(); i++) { //loop per char
        new_text += shiftChar(old[i], move); //add to new text
    }

    return new_text;
}

/*
    Caesar cipher decryption
    @param rshift:  the magnitude of the right shift (0 ≤ rshift ≤ 25)
*/
string decryptCaesar(string ciphertext, int rshift) {
    string new_text;
    string text = ciphertext;
    int move = -rshift;

    for(int i = 0; i < text.length(); i++) { //loop per char
        new_text += shiftChar(text[i], move); //add to new text
    }

    return new_text;
}

/*
    Vigenere cipher encryption
    @param keyword: string of lowercase alphabetic characters (a-z)
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

/*
    Vigenere cipher decryption
    @param keyword: string of lowercase alphabetic characters (a-z)
*/
string decryptVigenere(string ciphertext, string keyword) {
    string new_text;
    string old_text = ciphertext;
    string word = keyword;

    for (int i = 0, j = 0; i < old_text.length(); ++i) {
        if (j >= word.length()) {
            j = 0;
        }

        if (isalpha(old_text[i])) {
            int move = -(word[j] - 'a');
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
    cout << "Enter plaintext: ";
    getline(cin, s);

    cout << endl << "= Caesar =" << endl;
    int shift;
    cout << "Enter shift    : ";
    cin >> shift;

    cout << "Ciphertext     : " << encryptCaesar(s, shift) << endl;
    cout << "Decrypted      : " << decryptCaesar(encryptCaesar(s, shift), shift) << endl;

    cout << endl << "= Vigenere =" << endl;
    string keyword;
    cout << "Enter keyword  : ";
    cin >> keyword;

    cout << "Ciphertext     : " << encryptVigenere(s, keyword) << endl;
    cout << "Decrypted      : " << decryptVigenere(encryptVigenere(s, keyword), keyword) << endl;
}