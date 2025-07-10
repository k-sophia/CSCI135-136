/**********
Assignment: Lab2-D

Write a program named fibonacci.cpp, which uses an 
array of ints to compute and print all Fibonacci 
numbers from F(0) to F(59).
**********/

#include <iostream>
using namespace std;

int main()
{
	int fib[60]; //make array
	
	fib[0] = 0; //set first index to 0
	cout << fib[0] << endl; //print first number
	
	fib[1] = 1; //set second index to 1
	cout << fib [1] << endl; //print second number
	
	for(int i = 2; i < 60; i++) { //from F(0) to F(59)
		fib[i] = fib[i-1] + fib[i-2]; //compute sum of two previous numbers
		cout << fib[i] << endl; //print numbers
	}
}