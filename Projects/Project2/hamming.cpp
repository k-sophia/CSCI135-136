#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

string dictionary_read(ifstream &dict, string strand) {
    string codon, amino_acid, out;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the AUG MET
    while (dict >> codon >> amino_acid) {
        if (codon == strand) {
            out = amino_acid;
        }
    }

    return out;
}

char DNAbase_to_mRNAbase(char dna) { //convert bases dna to rna
    char DNA = toupper(dna); //make upper case
    char rna;

    if (DNA == 'A') { //find compliment 
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
    int strand = DNA.length(); //lenght of each strand

    for (int i = 0; i < strand; i++) { //loop for each char in strand
        RNA += DNAbase_to_mRNAbase(dna[i]);
    }
    
    return RNA; //return RNA string
}

string amino_acid(ifstream &dict ,string DNA) {
    string amino, result;
    int len = DNA.length();
    bool start = false;

    for (int i = 0; i < len; i = i +3) { //3 at time
        amino = dictionary_read(dict, DNA.substr(i,3));

        if(!start and amino == "Met") {
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

int Hamming(string strand_1, string strand_2) {
    int count = 0;
    int len = strand_1.length();

    for (int i = 0; i < len; i ++) {
        if(strand_1[i] != strand_2[i]) {
            count++;
        }
    }

    return count;
}

int main() {

    ifstream fin("mutations.txt");
    ifstream dict("codons.tsv");
    if (fin.fail() or dict.fail()) { //if either fail
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

    string strand;
    string before, b_amino, after, a_amino;

    while(getline(fin, strand)) { //goes to each strand

        before = strand;
        b_amino = amino_acid(dict, DNA_to_mRNA(before));

        while(getline(fin, strand)) { //get next
            after = strand;
            a_amino = amino_acid(dict, DNA_to_mRNA(after));

            cout << Hamming(before, after);

            if(b_amino != a_amino) {
                cout << " yes";
            }
            else if (b_amino == a_amino) {
                cout << " no";
            }
        }


    }

    fin.close();
    dict.close();

}