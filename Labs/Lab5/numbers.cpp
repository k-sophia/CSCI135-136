/**********
Assignment: Lab5-A

Write a program, numbers.cpp, that defines a function:
-   bool isDivisibleBy(int n, int d);

If n is divisible by d, the function should return 
true, otherwise return false.
**********/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d) {
    if (d == 0 or n%d != 0) { //if not divisible or zero
        return false;
    }
    else if (n%d == 0){ //if divisible
        return true;
    }
}

int main() {
    int n, d; //create vars
    cout << "Enter Numerator: ";
    cin >> n;
    cout << "Enter Denominator: ";
    cin >> d;

    cout << "\nIs " << n << " divisible by " << d << ": ";
    if (isDivisibleBy(n,d)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}