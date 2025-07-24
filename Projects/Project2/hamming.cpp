/**********
Assignment: Project2-C

Write a program called hamming.cpp that calculates
the Hamming distance between two strings.

Given two strings of equal length, the Hamming
distance is the number of positions at which the
two strings differ.
e.g.: Hamming("aactgc", "atcaga") would output 3

File: mutations.txt
- Contains an even number of lines (zero-indexed)
- The even-numbered lines contain the original DNA sequence
- The odd-numbered lines contain that same sequence with substitution mutations

For each pair in mutations.txt, output the Hamming
distance followed by “yes” or “no” whether the
substitution caused a change in structure.

Remember that translation to proteins
- Starts at and includes with the first "Start" codon
- Ends at and does not include the first "Stop" codon
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

/*
    @return:    the hamming distance of two DNA strand
*/
int Hamming(string strand_1, string strand_2) {
    int len = strand_1.length();
    int distance = 0;

    for (int i = 0; i < len; i ++) {
        if(strand_1[i] != strand_2[i]) {
            distance++;
        }
    }

    return distance;
}

int main() {
    ifstream fin("mutations.txt");
    ifstream dict("codons.tsv");
    if (fin.fail() or dict.fail()) { //if either fail
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

    string strand;
    while(getline(fin, strand)) { //gets even line of original DNA sequence
        string original_strand = strand;
        string original_amino = amino_acid(dict, DNA_to_mRNA(original_strand));

        cout << "Hamming distance:\n";
        while(getline(fin, strand)) { //gets odd line of same sequence with substitution mutations
            string mutation_strand = strand;
            string mutation_amino = amino_acid(dict, DNA_to_mRNA(mutation_strand));

            cout << Hamming(original_strand, mutation_strand); //get hamming distance

            //check change in structure
            if(original_amino != mutation_amino) {
                cout << " yes" << endl;
            }
            else if (original_amino == mutation_amino) {
                cout << " no" << endl;
            }
        }
    }

    fin.close();
    dict.close();
}