/**********
Write a program that asked the user to input
- the number of gallons of gas in the tank
- the fuel efficiency in miles per gallon
- the price of gas per gallon

Then print
- the cost per 100 miles
- how far the car can go with the gas in the tank
**********/

#include <iostream>
using namespace std;

int main()
{
	double gallons_of_gas, fuel_efficiency, price_of_gas;

	cout << "The number of gallons of gas in the tank:";
	cin >> gallons_of_gas;

	cout << "The fuel efficiency of miles per gallon:";
	cin >> fuel_efficiency;

	cout << "The price of gas per gallon:";
	cin >> price_of_gas;

	cout << endl << "The cost per 100 miles is ";
	cout << price_of_gas*(100/fuel_efficiency);

	cout << endl << "The car can still go ";
	cout << gallons_of_gas*fuel_efficiency << " miles" << endl;
}