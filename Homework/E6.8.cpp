/**********
Write a function: bool equals(int a[], int a_size, int b[], int b_size)
that checks whether two arrays have the same
elements in the same order.
**********/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size) {
    if (a_size != b_size) {
        return false;
    }

    bool equal = true;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return equal;
}
