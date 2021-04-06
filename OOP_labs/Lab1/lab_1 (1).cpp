//
// Created by Satyen Singh on 1/31/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Question 13, 14, 15 (declare function)
void display(const vector<int>& nameOfVector);
void doubleValues(const vector<int>& nameOfVector);
void doubleValuesRangedFor(const vector<int>& nameOfVector);


int main() {

// Question 1
// create hello world function without using namespace
// needed to include iostream for cout
// returning 0 since it is main
    std::cout << "Hello World!" << endl;

// Question 2
// create hello world function without using namespace
// simplify code by writing "using namespace std;"
// no need to type std:: in code
    cout << "Hello World!" << endl;

// Question 3
// define int variable x without initializing it
// after running, x = 1
    int x;
    cout << "x: " << x << endl;

// Question 4
// define int variable y and initialize it to 17
    int y = 17;
    cout << "y: " << y << endl;

// define int variable z and initialize it to 2000000017
    int z = 2000000017;
    cout << "z: " << z << endl;

// define double pie and initialize it to 3.14159
    double pie = 3.14159;
    cout << "pie: " << pie << endl;

// display sizes of each variable
    cout << "size of x is: " << sizeof(x) << endl;
    cout << "size of y is: " << sizeof(y) << endl;
    cout << "size of z is: " << sizeof(z) << endl;
    cout << "size of pie is: " << sizeof(pie) << endl;

// pie took up the most space, 8 , on memory, all variables that were ints took a space of 4

// Question 5
// if string "felix" is set to variable x, I predict it will be a compilation error as the type of x is set to int
// program will therefore refuse to even compile
//    int x = "felix";
//    cout << "x is: " << x << endl;

// after trying to run it, figured it is an compilation error, as the program simply failed to compile, not crash unlike a runtime error

// Question 6
// test whether y is between 10 and 20
    if (y > 10 && y < 20) {
        cout << "y is between 10 and 20" << endl;
    } else {
        cout << "y is not between 10 and 20" << endl;
    }

// Question 7
// print a line with the values from 10 to 20, inclusive - for loop
    for (int i = 10; i < 21; ++i) {
        cout << i << ' ';
    }

    cout << endl;
// print a line with the values from 10 to 20, inclusive - while loop
    int number = 10;
    while (number <  21) {
        cout << number << ' ';
        ++number;
    }

    cout << endl;
// print a line with the values from 10 to 20, inclusive - do-while loop
    int digit = 10;
    do {
        cout << digit << ' ';
        ++digit;
    } while (digit < 21);

    cout << endl;

// Question 8
// use loop to repeatedly ask for file name
// best choice would be do- while loop as you would like to ask user at least once for the filename
    ifstream nameStream;
    string fileName;

    do {
        cout << "What is the name of the file?:" << endl;
        cin >> fileName;
        nameStream.open(fileName);
    } while (!nameStream);

    string word;

// Question 9
// loop through the file and get each word
    while (nameStream >> word) {
        cout << word << endl;
    }

// close file
    nameStream.close();

    cout << endl;

// Question 10
// create a vector
    vector<int> vectorOfInts;

// fill vector with even values from 10 to 100, inclusive
    for (int integer = 10;integer < 101; integer+= 2) {
        vectorOfInts.push_back(integer);
    }

// Question 11
// loop through vector using indices
    cout << "For Loop Using Indices" << endl;
    for (size_t i = 0; i < vectorOfInts.size(); ++i) {
        cout << vectorOfInts[i] << endl;
    }
    cout << endl;

    cout << "Ranged For Loop" << endl;
// loop through vector using ranged for
    for (int integer : vectorOfInts) {
        cout << integer << endl;
    }

    cout << endl;

// loop through vector in reverse
    cout << "Loop Through in Reverse" << endl;
    int index = vectorOfInts.size() - 1;
    while (index > -1) {
        cout << vectorOfInts[index] << endl;
        index -= 1;
    }

// Question 12
// vector with prime numbers less than 20
    vector<int> primesVector{2, 3, 5, 7, 11, 13, 17, 19};

// Question 13 (test)
    display(vectorOfInts);
    cout << endl;

// Question 14 (test)
    doubleValues(vectorOfInts);
    cout << endl;

// Question 15 (test)
    doubleValuesRangedFor(vectorOfInts);
    cout << endl;

}

// Question 13
void display(const vector<int>& nameOfVector) {
    for (size_t i = 0; i < nameOfVector.size(); ++i) {
        cout << nameOfVector[i] << ' ';
    }
}

// Question 14
void doubleValues(const vector<int>& nameOfVector) {
    for (size_t i = 0; i < nameOfVector.size(); ++i) {
        cout << nameOfVector[i]*2 << ' ';
    }
}

// Question 15
void doubleValuesRangedFor(const vector<int>& nameOfVector) {
    for (const int& integer : nameOfVector) {
        cout << integer*2 << ' ';
    }
}
