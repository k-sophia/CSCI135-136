/**********
Assignment: Lab12-D

Write a program called pairwise.cpp that implements
a function that returns a vector of integers whose
elements are the pairwise sum of the elements from
the two vectors passed as arguments.
-   vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2)

If a vector has a smaller size than the other,
consider extra entries from the shorter vectors as 0.
**********/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    vector<int> one = v1;
    vector<int> two = v2;

    // Resize to equal length, padding with 0s
    if (one.size() < two.size()) {
        one.resize(two.size(), 0);
    } else if (two.size() < one.size()) {
        two.resize(one.size(), 0);
    }

    vector<int> sum;
    for (int i = 0; i < one.size(); i++) {
        sum.push_back(one[i] + two[i]);
    }

    return sum;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5};

    cout << "V1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\nV2: ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }

    vector<int> v3 = sumPairWise(v1, v2);
    cout << "\n\nV3 (sumPairWise): ";
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;
}