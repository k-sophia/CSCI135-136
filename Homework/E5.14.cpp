/**********
Write a function named sort2(int& a, int& b) that
-   swaps the values of a and b if a is greater than b
-   otherwise leaves a and b unchanged
**********/

#include <iostream>
using namespace std;

void sort2(int& a, int& b){
    if (a > b) {
        swap(a, b);
    }
}

int main() {
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    sort2(x, y);
    cout << "\nSorted numbers: " << x << " " << y << endl;
}