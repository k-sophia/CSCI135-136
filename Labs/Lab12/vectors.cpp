/**********
Assignment: Lab12-A

Write a program named vectors.cpp and implement the
function vector<int> makeVector(int n).

Your function must be implemented outside the main
function and must return a vector.
**********/

#include <iostream>
#include <vector>
using namespace std;

/*
    @return:    a vector of n integers that range from 0 to n-1
*/
vector<int> makeVector(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }

    return v;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin>> num;

    cout << "\n\nVector:\n";
    vector<int> numbers = makeVector(num);
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}