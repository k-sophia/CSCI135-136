/**********
Assignment: Project1-B

Write a program named calc.cpp that reads from the
cin a file that has a sequence of one or more non-
negative integers written to be added or subtracted.

Space characters can be anywhere in the input.

After the input ends (end-of-file is reached), the
program should compute and print the result of the
input summation.
**********/

#include <iostream>
using namespace std;

int main()
{
    int numbers; //create variable for set of numbers
    char op; //operation (plus or minus)
    int sum = 0; //set sum to 0

    cin >> numbers;
    sum = numbers; //gets first number in sequence

    while(cin >> op >> numbers) { //get next operator and number in sequence
        if (op == '+') {
          sum += numbers;
        }
        else if (op == '-') {
            sum -= numbers;
        }
    }
    cout << sum << endl;
}