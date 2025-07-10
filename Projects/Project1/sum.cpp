/**********
Assignment: Project 1A

Write a program named sum.cpp that reads a 
sequence of integers from cin, and reports 
their sum.
**********/

#include <iostream>
using namespace std;

int main()
{
    int numbers;// create variable for set of numbers
    int sum = 0; //set sum to 0

    while(cin >> numbers) { //use while to go over each number
        sum = sum + numbers; //add each number to sum
    }

    cout << sum << endl; //print total sum
}