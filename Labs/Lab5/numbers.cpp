/**********
Assignment: Lab5

Write a program, numbers.cpp, that defines these functions:
-   bool isDivisibleBy(int n, int d);
-   bool isPrime(int n);
-   int nextPrime(int n);
-   int countPrimes(int a, int b);
-   bool isTwinPrime(int n);
-   int nextTwinPrime(int n);
-   int largestTwinPrime(int a, int b);

Have a main function that tests your code.
**********/

#include <iostream>
using namespace std;

/*
    Checks if one integer is divisible by another
    @return:    true if n is divisible by d,
                false otherwise
*/
bool isDivisibleBy(int n, int d) {
    if (d == 0 or n%d != 0) { //if not divisible or zero
        return false;
    }
    return true; //else is divisble
}

/*
    Determines if an integer is a prime number
    @return:    true if n is a prime,
                false otherwise
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
    Finds the smallest prime number greater than a given integer
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
    Counts how many prime numbers are in the range (a ≤ x ≤ b)
    @return:    the number of prime numbers between a and b
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
    Checks if a number is a twin prime
    @return:    true if n is a twin prime,
                false otherwise
*/
bool isTwinPrime(int n) {
	if (isPrime(n)) { //if prime
	    if (isPrime(n - 2) or isPrime(n + 2)) { //if a twin prime
		    return true;
	    }
	}
	return false; //not a prime or twin prime
}

/*
    Finds the smallest twin prime greater than a given number
    @return:    the smallest twin prime greater than n
*/
int nextTwinPrime(int n) {
    if (n <= 2) {
        return 3;
    }

	int next = n;
	do {
        next = nextPrime(next);
    } while (!isTwinPrime(next)); //redo if false

    return next;
}
/*
    Finds the largest twin prime within a given range (a ≤ N ≤ b)
    @return:    the largest twin prime between a and b if found
                -1 if none found
*/
int largestTwinPrime(int a, int b) {
    for (int i = b; i >= a; i--) {
        if (isTwinPrime(i)) {
            return i;
        }
	}
	return -1;
}

int main() {
    //Test largestTwinPrime
    int lowerNum2, upperNum2;
    cout << "Enter Lower Interval: ";
    cin >> lowerNum2;
    cout << "Enter Upper Interval: ";
	cin >> upperNum2;
    cout << "\nLargest twin prime within interval: " << largestTwinPrime(lowerNum2, upperNum2) << endl;

    /*
    //Test nextTwinPrime
    int num4; //create vars
    cout << "Enter Number: ";
    cin >> num4; //get number
    cout << "\nNext twin prime is " << nextTwinPrime(num4) << endl;
    */

    /*
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
    */

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