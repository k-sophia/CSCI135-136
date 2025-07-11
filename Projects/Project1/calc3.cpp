/**********
Assignment: Project1-D

Write an even better calculator program, calc3.cpp, 
that can understand squared numbers

Use a simplified notation X^ to mean X2.
**********/

#include <iostream>
using namespace std;

int main()
{
    int numbers;// create variable for set of numbers
    int sum = 0; //set sum to 0
    char op;// right operation
    char pre_op = '+'; //left operation

    cin >> numbers; //get first number of first expression
    while(cin >> op) {
        if (op =='^') { //if square
            numbers = numbers*numbers;
            cin >> op; //get next operation
        }
        
        if (pre_op == '+') { // if +
            sum += numbers;
        }
        else if (pre_op == '-') { //if -
            sum -= numbers;
        }
        
        pre_op = op; //get next operation
        cin >> numbers; //get next number
        if (op == ';') { //if end of expression
            cout << sum << endl; //print sum
            sum = 0; //restart
            pre_op = '+';
        }
    }
}