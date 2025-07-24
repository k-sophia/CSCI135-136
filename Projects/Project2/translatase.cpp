/**********
Assignment: Project2-B

Write a program called translatase.cpp that given
strands of DNA (taken from dna2b.txt), outputs to
the console the corresponding amino-acid chain.

Dictionary file: codons.tsv
- Contains 64 lines, each with two columns
- In the first column are the codons
- In the second are the corresponding amino acid

Formatting rules:
- Use the three-letter abreviation from the dictionary for each amino acid
- Insert a hyphen after each amino acid except for the last
- The first amino acid should always be “Met”
- “Stop” codons should not be inserted (e. g. tacaacact would produce Met-Leu)
**********/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

/*
    read from a file that has two fields per line
    where the delimiter is a space

    @param &dict:   ifstream reference
    @return:        reset the file pointer to the beginning for each look up
*/
string dictionary_read(ifstream &dict, string strand) {
    string codon, amino_acid, out;
    dict.clear(); //reset error state
    dict.seekg(0); //return file pointer to the beginning
    while (dict >> codon >> amino_acid) {
        if (codon == strand) {
            return amino_acid;
        }
    }

    return out;
}

/*
    @return:    the mRNA base complement of a DNA base
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
    @return:    the mRNA strand compliment of a DNA strand
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

/*
    @return:    corresponding amino-acid chain of DNA strand
*/
string amino_acid(ifstream &dict, string DNA) {
    string amino, result;
    int len = DNA.length();
    bool start = false;

    for (int i = 0; i < len; i = i +3) { //3 at time
        amino = dictionary_read(dict, DNA.substr(i,3));

        if(!start and amino == "Met") { //start translation at the first AUG
            start = true;
            result += amino;
            continue;
        }

        if (start) {
            if (amino == "Stop") { //end when Stop codon found
                break;
            }
            result += "-" + amino;
        }
    }

    return result;
}

int main() {
    ifstream fin("dna2b.txt");
    ifstream dict("codons.tsv"); //open codons.tsv once with one ifstream object
    if (fin.fail() or dict.fail()) { //if either fail
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

    cout << "Corresponding amino-acid chains: ";
    string strand, rna;
    while(getline(fin, strand)) { //goes to each strand
        rna = DNA_to_mRNA(strand);
        cout << endl << amino_acid(dict, rna);
    }

    fin.close();
    dict.close();
}