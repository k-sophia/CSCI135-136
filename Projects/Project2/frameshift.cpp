/**********
Assignment: Project2-D

Write a program called frameshift.cpp that compares 
the results of Task B with the mutated strands.

File: frameshift_mutations.txt 
- Contains the same DNA sequences of Task B on the even lines 
- Contains frameshift mutations on the odd lines (0-indexed)
- Each mutation has at most one insertion or one deletion 


You will need to parse the strands one nucleotide at 
a time as the “Start” codon is not a guaranteed 
multiple of 3 from the begining.

Your output should be the original protein on the 
even lines, and the mutated protein on the odd lines.
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

    @&dict      ifstream reference 
    @return     reset the file pointer to the beginning for each look up
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
string amino_acid(ifstream &dict ,string DNA) {
    string amino, result;
    int len = DNA.length();
    int start_index = 0;

    for (; start_index < len; start_index++) { //loop to find Start codon
        amino = dictionary_read(dict, DNA.substr(start_index,3));

        if(amino == "Met") { //if Start codon is found
            result += amino; //start translation at the first AUG
            start_index += 3;
            break;
        }
    }

    //get rest of amino-acid chain
    for (; start_index < len; start_index = start_index +3) { //3 at time
        amino = dictionary_read(dict, DNA.substr(start_index,3));

        if (amino == "Stop") { //end when Stop codon found
            break;
        }
        else if (amino.length() == 3) {
          result += "-" + amino;
        }
    }

    return result;
}

int main() {
    ifstream fin("frameshift_mutations.txt");
    ifstream dict("codons.tsv");
    if (fin.fail() or dict.fail()) { //if either fail
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

    string strand;
    while(getline(fin, strand)) { //goes to each strand
        cout << amino_acid(dict, DNA_to_mRNA(strand)) << endl;
    }

    fin.close();
    dict.close();
}

