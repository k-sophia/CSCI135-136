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
    vector<int> goku = {1, 2, 3};
    vector<int> vegeta = {4, 5};

    cout << "Before fusion:\n";
    cout << "Goku: ";
    for (int i = 0; i < goku.size(); i++) {
        cout << goku[i] << " ";
    }
    cout << "\nVegeta: ";
    for (int i = 0; i < vegeta.size(); i++) {
        cout << vegeta[i] << " ";
    }

    gogeta(goku, vegeta);

    cout << "\n\nAfter fusion (gogeta):\n";
    cout << "Goku: ";
    for (int i = 0; i < goku.size(); i++) {
        cout << goku[i] << " ";
    }
    cout << "\nVegeta: ";
    for (int i = 0; i < vegeta.size(); i++) {
        cout << vegeta[i] << " ";
    }
    cout << endl;
}