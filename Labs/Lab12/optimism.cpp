/**********
Assignment: Lab12-B

Write a program named optimism.cpp and implement the
function vector<int> goodVibes(const vector<int>& v);
- given a vector of integers
- returns a vector with only the positive integers
  in the same order
**********/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v) {
    vector<int> result;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 0) { //if positive integer
            result.push_back(v[i]);
        }
    }

    return result;
}

int main() {
    vector<int> a = {1,2,-1,3,4,-1,6};
    cout << "Vector A (original):\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    vector<int> a_goodV = goodVibes(a);
    cout << "\n\nVector A (goodVibes):\n";
    for (int i = 0; i < a_goodV.size(); i++) {
        cout << a_goodV[i] << " ";
    }
    cout << endl;
}