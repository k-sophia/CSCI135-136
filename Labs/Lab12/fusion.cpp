/**********
Assignment: Lab12-C

Write a program named fusion.cpp that implements a
function that appends elements of the second vector
into the first and empties the second vector.
-   void gogeta(vector<int> &goku, vector<int> &vegeta);
**********/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta) {
    for (int i = 0; i < vegeta.size(); i++) {
        goku.push_back(vegeta[i]); //gets added to first vector
    }

    vegeta.clear(); //empty
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5};

    cout << "Before fusion:\n";
    cout << "V1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\nV2: ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }

    gogeta(v1, v2);

    cout << "\n\nAfter fusion (gogeta):\n";
    cout << "V1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\nV2: ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
}