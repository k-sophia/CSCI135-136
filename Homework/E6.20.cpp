/**********
Write a function that merges two sorted vectors,
producing a new sorted vector
- vector<int> merge_sorted(vector<int> a, vector<int> b)

Keep an index into each vector, indicating how much
of it has been processed already.

Each time, append the smallest unprocessed element
from either vector, then advance the index.

For example: if a is 1 4 9 16 and b is 4 7 9 9 11
then merge_sorted returns the vector 1 4 4 7 9 9 9 11 16
**********/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    vector<int> result = a;
    for (int i = 0; i < b.size(); i ++) {
        result.push_back(b[i]);
    }

    sort(result.begin(), result.end());
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

    vector<int> c = merge_sorted(a, b);
    cout << "\n\nVector C (Merge Sorted):\n";
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}