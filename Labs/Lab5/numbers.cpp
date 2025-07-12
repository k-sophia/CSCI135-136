/**********
Assignment: Lab5

Write a program, numbers.cpp, that defines these functions:
-   bool isDivisibleBy(int n, int d);
-   bool isPrime(int n);

Have a main function that tests your code.
**********/

#include <iostream>
using namespace std;

/*
    @return:    'true' if n is divisible by d 
                'false' otherwise

*/
bool isDivisibleBy(int n, int d) {
    if (d == 0 or n%d != 0) { //if not divisible or zero
        return false;
    }
    return true; //else is divisble
}

/*
    @return:    'true' if n is a prime
                'false' otherwise
*/
bool isPrime(int n) {    
    if (n <= 1) {
        return false;
    }
    
    for (int i = 2; i < n; i++) { //check 2 to n-1
        if (n%i == 0) { //if divisible evenly
            return false; //not prime
        }
    }
    return true;
}

int main() {
    //Test isPrime
    int x;
    cout << "Enter Number: ";
    cin >> x;
    
    cout << "\nIs " << x << " a prime number: ";
    if (isPrime(x)) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }

    /*****
    //Test isDivisibleBy
    int numerator, denominator;
    cout << "Enter Numerator: ";
    cin >> numerator;
    cout << "Enter Denominator: ";
    cin >> denominator;

    cout << "\nIs " << numerator << " divisible by " << denominator << ": ";
    if (isDivisibleBy(numerator,denominator)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    *****/
}