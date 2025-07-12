/**********
Assignment: Lab5

Write a program, numbers.cpp, that defines these functions:
-   bool isDivisibleBy(int n, int d);
-   bool isPrime(int n);
-   int nextPrime(int n);
-   int countPrimes(int a, int b);
-   bool isTwinPrime(int n);

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

/*
    @return:    the smallest prime greater than n
*/
int nextPrime(int n) {
    if (n <= 1) {
         return 2;
    }
    
    int next = n;
    do {
        next = next+1;
        isPrime(next); //use if prime function
    } while (!isPrime(next)); //redo if not a prime number

    return next;
}

/*
    @return:    the number of prime numbers in the interval a ≤ x ≤ b
*/
int countPrimes(int a, int b) {
	int counter = 0;

	for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            counter++;
        }
	}
	return counter;
}
/*
    @return:    'true' if n is a twin prime
                'false' otherwise
*/
bool isTwinPrime(int n) {
	if (isPrime(n)) { //if prime
	    if (isPrime(n - 2) or isPrime(n + 2)) { //if a twin prime
		    return true;
	    }
	}
	return false; //not a prime or twin prime
}

int main() {
    //Test isTwinPrime
    int num3;
    cout << "Enter Number: ";
    cin >> num3;

    cout << "\nIs " << num3 << " a twin prime: ";
    if(isTwinPrime(num3)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }

    /* 
    //Test countPrimes
    int lowerNum, upperNum;
    cout << "Enter Lower Interval: ";
    cin >> lowerNum;
    cout << "Enter Upper Interval: ";
	cin >> upperNum;
    cout << "\n# of prime numbers within interval: " << countPrimes(lowerNum, upperNum) << endl;
    */

    /* 
    //Test nextPrime
    int num2;
    cout << "Enter Number: ";
    cin >> num2;
    cout << "\nNext prime number is " << nextPrime(num2) << endl; 
    */
    
    /* 
    //Test isPrime
    int num;
    cout << "Enter Number: ";
    cin >> num;
    
    cout << "\nIs " << num << " a prime number: ";
    if (isPrime(num)) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }
    */

    /* 
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
    */
}