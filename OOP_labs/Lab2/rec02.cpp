//
// Created by Satyen Singh on 2/7/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// initialize a struct Hydrocarbons to store the different properties
struct Hydrocarbons {
    vector <string> formulas;
    int carb;
    int hydrogen;
};


void openFile(ifstream& nameOfFileStream, string fileName);
void displayHC(const Hydrocarbons& aHC);
void displayHCs(const vector<Hydrocarbons>& hydrocarbons);
void sortHCVector( vector<Hydrocarbons>& hydrocarbons);

// function to fill the vector from ifstream
void fillVectorFromStream(ifstream& HydroCarbonStream, vector<Hydrocarbons>& hydrocarbons) {

    string name;
    char CarHyd;
    int c, h;

    // if CxHy are same for more than one type of hydrocarbon, group it together,
    // if not then add it in as a new struct
    while (HydroCarbonStream >> name >> CarHyd >> c >> CarHyd >> h) {
        int Present = 0;
        int index = 0;
        if (hydrocarbons.size() == 0) {
            Hydrocarbons aHC{ {name}, c, h };
            hydrocarbons.push_back(aHC);
        }
        else {

            for (size_t i = 0; i < hydrocarbons.size(); ++i) {
                if (c == hydrocarbons[i].carb && h == hydrocarbons[i].hydrogen) {
                    Present = 1;
                    index = i;
        }

            }

            if (Present == 1) {
                hydrocarbons[index].formulas.push_back(name);
            }
            else {
                Hydrocarbons aHC{ {name}, c, h };
                hydrocarbons.push_back(aHC);
            }

        }

    }
}

// create variable for ifstream and vector
// call functions to open file, fill vector from stream, sort the vector in order, and then display
int main() {

    ifstream HydroCarbonStream;
    string fileName;
    vector<Hydrocarbons> info;
    openFile(HydroCarbonStream, fileName);
    fillVectorFromStream(HydroCarbonStream, info);
    sortHCVector(info);
    displayHCs(info);

}

// function to open file
// keep asking user for filename till provided with the correct name
void openFile( ifstream& nameOfFileStream, string fileName) {
    do {
        cout << "What is the name of the file?:" << endl;
        cin >> fileName;
        nameOfFileStream.open(fileName);
        fileName.clear();
    } while (!nameOfFileStream);

}

// sort the vector using bubble sort
// sort first by carbons, if carbons are same, then look at hydrogen amounts
void sortHCVector( vector<Hydrocarbons>& hydrocarbons) {
    Hydrocarbons swap;
    for (size_t i = 0; i < hydrocarbons.size(); ++i) {
        for (size_t j = 0; j < hydrocarbons.size() - 1; ++j) {
            if (hydrocarbons[j].carb > hydrocarbons[j+1].carb) {
                swap = hydrocarbons[j];
                hydrocarbons[j] = hydrocarbons[j+1];
                hydrocarbons[j+1] = swap;

            }
            else if (hydrocarbons[j].carb == hydrocarbons[j+1].carb) {

                if (hydrocarbons[j].hydrogen > hydrocarbons[j+1].hydrogen) {
                    swap = hydrocarbons[j];
                    hydrocarbons[j] = hydrocarbons[j+1];
                    hydrocarbons[j+1] = swap;
                }
            }
        }
    }

}

void displayHC(const Hydrocarbons& aHC) {
    cout << 'C' << aHC.carb << 'H' << aHC.hydrogen << ' ';
    for (size_t i = 0; i < aHC.formulas.size(); ++i) {
        cout << aHC.formulas[i] << ' ';
    }
    cout << endl;
}

// ^^^^^^^^^^^
//// functions to display the vector
// vvvvvvvvvvv
void displayHCs(const vector<Hydrocarbons>& hydrocarbons) {
    for (const Hydrocarbons& aHC : hydrocarbons){
        displayHC(aHC);
    }

}