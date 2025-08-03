/**********
Write function, void sort2(double* p, double* q), that
- receives two pointers
- sorts the value sto which they point

If you call sort2(&x, &y) then x <= y after the call.
**********/

#include <iostream>
using namespace std;

void sort2(double* p, double* q) {
    if (*p > *q) {
        swap(*p, *q);
    }
}

int main() {
    double x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    sort2(&x, &y);

    cout << "\nSorted numbers:\n";
    cout << x << endl;
    cout << y << endl;
}