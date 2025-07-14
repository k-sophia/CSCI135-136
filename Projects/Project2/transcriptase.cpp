/**********
Assignment: Project2-A
**********/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

char DNAbase_to_mRNAbase(char dna) { //convert bases dna to rna
    char DNA = toupper(dna); //make upper case
    char rna;

    //find compliment
    if (DNA == 'A') {
        rna = 'U';
    }
    else if (DNA == 'T') {
        rna = 'A';
    }
    else if (DNA == 'C') {
        rna = 'G';
    }
    else if (DNA == 'G') {
        rna = 'C';
    }

    return rna; //return rna base char

}

string DNA_to_mRNA(string DNA) {
    string RNA = "";
    string dna = DNA;
    int strand = DNA.length(); //length of each strand

    for (int i = 0; i < strand; i++) { //loop for each char in strand
        RNA += DNAbase_to_mRNAbase(dna[i]);
    }
    
    return RNA; //return RNA string
}

int main() {
    ifstream fin("dna.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

    string strand;

    while(getline(fin, strand)) { //goes to each strand
        cout << DNA_to_mRNA(strand) << endl;
    }
    fin.close();
}