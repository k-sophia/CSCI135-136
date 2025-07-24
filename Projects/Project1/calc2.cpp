/**********
Assignment: Project1-C

Write a better version of the calculator, calc2.cpp,
that can evaluate multiple arithmetic expressions.

Use the semicolon symbol that must be used at the
end of each expression in the input.
**********/

#include <iostream>
using namespace std;

int main()
{
    int numbers; //create variable for set of numbers
    char op; //operation (plus or minus)
    int sum = 0; //set sum to 0

    cin >> numbers;
    sum = numbers; //get first number of first expression

    while(cin >> op >> numbers) { //get next operator and number in expression
        if (op == '+') {
          sum += numbers;
        }
        else if (op == '-') {
            sum -= numbers;
        }
        else if (op == ';') { //if end of expression
            cout << sum << endl;
            sum = 0 + numbers; //set sum to first number of next expression
        }
    }

    cout << sum << endl; //print sum of last expression
}