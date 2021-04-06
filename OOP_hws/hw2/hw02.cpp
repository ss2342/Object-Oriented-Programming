////
//// Created by Satyen Singh on 2/9/20.
////
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// create a struct Warriors with attributes name and strength
struct Warriors {
    string name;
    int strength;
};

// prototypes of functions
void statusOFWarriors(vector<Warriors>& warriors);
void createWarrior(ifstream& Warriorstream, vector<Warriors>& warriors);
void battleWarriors(ifstream& Warriorstream, vector<Warriors>& warriors);

// open warriors.txt and read in the commands - Warrior, Status, or Battle
int main() {
    ifstream nameStream;
    nameStream.open("warriors.txt");
    vector<Warriors> warriors;
    string command;
    vector<int> strengths;
    while (nameStream >> command) {

        // if command = Warrior, create a new struct with name and strength and add to warriors vector
        if (command == "Warrior") {
            createWarrior(nameStream, warriors);
        }

        // if command = Status, display number of warriors, names, and current strengths
        if (command == "Status") {
            statusOFWarriors(warriors);
        }

        // if command = Battle, initiate a battle between the two specified warriors
        if (command == "Battle") {
            battleWarriors(nameStream, warriors);
        }

    }

}

// function to create a warrior struct and add it to the warriors vector
void createWarrior(ifstream& Warriorstream, vector<Warriors>& warriors) {
    string name;
    int strength;
    Warriorstream >> name >> strength;
    Warriors aWarrior {name, strength};
    warriors.push_back(aWarrior);

}

// function to display the names and current strengths of the warriors, as well as the number of warriors
void statusOFWarriors(vector<Warriors>& warriors) {
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (size_t i = 0; i < warriors.size(); ++i) {
        cout << "Warrior: " << warriors[i].name << ", Strength: " << warriors[i].strength << endl;
    }
}
 // function to start a battle between two specified warriors
void battleWarriors(ifstream& Warriorstream, vector<Warriors>& warriors) {
    string warrior1;
    string warrior2;
    int index1;
    int index2;
    Warriorstream >> warrior1 >> warrior2;

    for (size_t i = 0; i < warriors.size(); ++i) {

        // find position of 2 warriors in battle
        if (warriors[i].name == warrior1)
            index1 = i;
        if (warriors[i].name == warrior2) {
            index2 = i;
        }

    }

    // show number of warriors
    cout << warriors[index1].name << " battles " << warriors[index2].name << endl;

     // if first warrior is stronger than second warrior
    if (warriors[index1].strength > warriors[index2].strength) {

        // if second warrior is already dead
        if (warriors[index2].strength == 0) {
            cout << "He's dead, " << warriors[index1].name << endl;
        }
        else {
            warriors[index1].strength -= (warriors[index2].strength);
            warriors[index2].strength = 0;
            cout << warriors[index1].name << " beats " << warriors[index1].name << endl;
        }

    }

    // if first warrior is weaker than the second warrior
    else if (warriors[index1].strength < warriors[index2].strength) {

        // if first warrior is already dead
        if (warriors[index1].strength == 0) {
            cout << "You're already dead, " << warriors[index1].name << endl;
        }
        else {
            warriors[index2].strength -= (warriors[index1].strength);
            warriors[index1].strength = 0;
            cout << warriors[index1].name << " loses to " << warriors[index2].name << endl;
        }

    }

    // if first warrior and second warrior have equal strength
    else {

        // if both warriors are already dead
        if (warriors[index1].strength == 0 && warriors[index2].strength == 0) {
            cout << "Oh, NO! They're both dead! Yuck! " << endl;
        }
        else {
            warriors[index1].strength = 0;
            warriors[index2].strength = 0;
            cout << "Mutual Annihilation: " << warriors[index1].name << " and " << warriors[index2].name << " die at each other's hands" << endl;
        }

    }
}