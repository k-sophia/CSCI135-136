/**********
Write a function named sort3(int& a, int& b, int& c), 
that swaps its three arguments to arrange them in 
sorted order
**********/

#include <iostream>
using namespace std;

void sort2(int& a, int& b){
    if (a > b) {
        swap(a, b);
    }
}

void sort3(int& a, int& b, int& c){
    sort2(a,b);
    sort2(a,c);
    sort2(b,c);
}

int main() {
    int x, y, z;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "Enter third number: ";
    cin >> z;

    sort3(x, y, z);
    cout << "\nSorted numbers: " << x << " " << y << " " << z << endl;
}