////
//// Created by Satyen Singh on 2/4/20.
////
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decrypt(char givenChar, int rotation);
void display(const string& givenString, int rotate);

int main() {
    // open file
    ifstream nameStream;
    vector<string> StringVector;
    string fileName = "encrypted.txt";
    nameStream.open(fileName);

    // read in first line that holds the number of rotations
    int numberOfRotations;
    nameStream >> numberOfRotations;

    // read in rest of the lines using while loop and push it into a vector
    string line;
    while (getline(nameStream, line)) {
        StringVector.push_back(line);
    }

    // loop through vector in reverse and display the decrypted message
    for (size_t i = StringVector.size(); i > 0; --i) {
        display(StringVector[i - 1], numberOfRotations);
        cout << endl;
    }

}

// function to decrypt a character
char decrypt(char givenChar, int rotation) {

    // only decrypt lower case letters
    if (givenChar >= 'a' && givenChar <= 'z') {

        givenChar -= rotation;

        // if value of char goes less than a, less than 97 on ascii, wrap around to make sure it stays within a through z
        if (givenChar < 'a') {
            givenChar += 26;

        }
    }
    return givenChar;

}

// function to output the decrypted string
void display(const string& givenString, int rotate) {

    // loop through a string and decrypt it, character by character
    for (size_t i = 0; i < givenString.size(); ++i) {
        cout << decrypt(givenString[i], rotate);
    }
}



