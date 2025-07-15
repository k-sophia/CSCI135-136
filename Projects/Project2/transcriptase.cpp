/**********
Assignment: Project2-A

Write a program called transcriptase.cpp that 
1. reads a text file called dna.txt that contains one DNA strand per line 
2. outputs to the console the corresponding mRNA strands 

Each output line must
- contain exactly one mRNA strand 
- be in capital letters
**********/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

/*
    @return:     the mRNA base complement of a DNA base
*/
char DNAbase_to_mRNAbase(char dna) {
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

/*
    @return:     the mRNA strand compliment of a DNA strand
*/
string DNA_to_mRNA(string DNA) {
    string RNA = "";
    string dna = DNA;
    int strand = DNA.length(); //length of each strand

    for (int i = 0; i < strand; i++) { //loop for each char in strand
        RNA += DNAbase_to_mRNAbase(dna[i]); //get rna char compliment of dna char
    }
    
    return RNA; //return RNA strand
}

int main() {
    ifstream fin("dna.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

    cout << "Corresponding mRNA strands: " << endl;
    string strand;
    while(getline(fin, strand)) { //goes to each strand
        cout << DNA_to_mRNA(strand) << endl;
    }
    fin.close();
}