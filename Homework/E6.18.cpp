/**********
Write a function that appends one vector after another
-   vector<int> append(vector<int> a, vector<int> b)

For example: if a is 1 4 9 16 and b is 9 7 4 9 11
then append returns the vector 1 4 9 16 9 7 9 11
**********/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    vector<int> result = a;
    for (int i = 0; i < b.size(); i ++) {
        result.push_back(b[i]);
    }

    return result;
}

int main() {
    vector<int> a = {1, 4, 9, 16};
    vector<int> b = {9, 7, 4, 9, 11};

    cout << "Vector A:\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    cout << "\n\nVector B:\n";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }

    vector<int> c = append(a, b);
    cout << "\n\nVector C (Append):\n";
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}