////
//// Created by Satyen Singh on 2/9/20.
////
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// warrior class containing the following attributes
// warrior name
// weapon class containing...
    // weapon name
    // weapon strength
class Warrior {

    // output operator overloading
    friend ostream&operator<<(ostream& os, const Warrior& aWarrior);
public:

    // initialization list
    Warrior(const string &nameOfWarrior, const string &nameOfWeapon, int strengthOfWeapon) :
            WarriorName(nameOfWarrior), weaponInfo(nameOfWeapon, strengthOfWeapon) {}

    // getter for warrior's name
    const string& getWarriorName() const {
        return WarriorName;
    }

    // battle method
    void battle(Warrior& opponent) {
        // if first warrior is stronger than second warrior
        if (weaponInfo.strengthOfWeapon() > opponent.weaponInfo.strengthOfWeapon()) {

            // if second warrior is already dead
            if (opponent.weaponInfo.strengthOfWeapon() == 0) {
                cout << "He's dead, " << WarriorName << endl;
            }
            else {
                weaponInfo.decreaseStrength(opponent.weaponInfo.strengthOfWeapon());
                opponent.weaponInfo.decreaseStrength(opponent.weaponInfo.strengthOfWeapon());
                cout << WarriorName << " beats " << opponent.WarriorName << endl;
            }

        }

            // if first warrior is weaker than the second warrior
        else if (weaponInfo.strengthOfWeapon() < opponent.weaponInfo.strengthOfWeapon()) {

            // if first warrior is already dead
            if (weaponInfo.strengthOfWeapon() == 0) {
                cout << "You're already dead, " << WarriorName << endl;
            }
            else {
                opponent.weaponInfo.decreaseStrength(weaponInfo.strengthOfWeapon());
                weaponInfo.decreaseStrength(weaponInfo.strengthOfWeapon());
                cout << WarriorName << " loses to " << opponent.WarriorName << endl;
            }

        }

            // if first warrior and second warrior have equal strength
        else {

            // if both warriors are already dead
            if (weaponInfo.strengthOfWeapon() == 0 && opponent.weaponInfo.strengthOfWeapon() == 0) {
                cout << "Oh, NO! They're both dead! Yuck! " << endl;
            }
            else {
                weaponInfo.decreaseStrength(weaponInfo.strengthOfWeapon());
                opponent.weaponInfo.decreaseStrength(opponent.weaponInfo.strengthOfWeapon());
                cout << "Mutual Annihilation: " << WarriorName << " and " << opponent.WarriorName << " die at each other's hands" << endl;
            }

        }

    }

private:

    // weapon class
    class Weapon {
        friend ostream&operator<<(ostream& os, const Weapon& aWeapon) {
            os << ", weapon: " << aWeapon.weaponName << ", " << aWeapon.weaponStrength;
            return os;
        }
    public:
        Weapon(const string& weapon, int strength):
            weaponName(weapon), weaponStrength(strength) {}

         // getter for weapon name
        const string nameOfWeapon() const {
            return weaponName;
        }

        // getter for weapon strength
        int strengthOfWeapon() const{
            return weaponStrength;

        }

        // method for decreasing strength after a battle
        void decreaseStrength(int opponentStrength) {
            weaponStrength -= opponentStrength;
        }
    private:
        string weaponName;
        int weaponStrength;
    };
    Weapon weaponInfo;
    string WarriorName;


};

ostream& operator << (ostream& os, const Warrior& aWarrior) {
    os << "Warrior: " << aWarrior.WarriorName << aWarrior.weaponInfo;
    return os;
}



// prototypes of functions
void statusOFWarriors(vector<Warrior>& warriors);
void createWarrior(ifstream& Warriorstream, vector<Warrior>& warriors);
void battleWarriors(ifstream& Warriorstream, vector<Warrior>& warriors);

// open warriorsAndWeapons.txt and read in the commands - Warrior, Status, or Battle
int main() {
    ifstream nameStream;
    nameStream.open("warriorsAndWeapons.txt");
    vector<Warrior> warriors;
    string command;
    vector<int> strengths;
    while (nameStream >> command) {

        // if command = Warrior, create a new struct with name and strength and add to warriors vector
        if (command == "Warrior") {
            createWarrior(nameStream, warriors);

        }

        // if command = Status, display number of warriors, names, and current strengths
        else if (command == "Status") {
            statusOFWarriors(warriors);
        }

        // if command = Battle, initiate a battle between the two specified warriors
        else if (command == "Battle") {
            battleWarriors(nameStream, warriors);
        }

    }

}

// function to create a warrior struct and add it to the warriors vector
void createWarrior(ifstream& Warriorstream, vector<Warrior>& warriors) {
    string WarriorName;
    string WeaponName;
    int WeaponStrength;
    Warriorstream >> WarriorName >> WeaponName >> WeaponStrength;
    warriors.emplace_back(WarriorName, WeaponName, WeaponStrength);
}

// function to display the names and current strengths of the warriors, as well as the number of warriors
void statusOFWarriors(vector<Warrior>& warriors) {
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (size_t i = 0; i < warriors.size(); ++i) {
        cout << warriors[i] << endl;
    }
}
// function to start a battle between two specified warriors
void battleWarriors(ifstream& Warriorstream, vector<Warrior>& warriors) {
    string warrior1;
    string warrior2;
    int index1;
    int index2;
    Warriorstream >> warrior1 >> warrior2;

    for (size_t i = 0; i < warriors.size(); ++i) {

        // find position of 2 warriors in battle
        if (warriors[i].getWarriorName() == warrior1)
            index1 = i;
        if (warriors[i].getWarriorName() == warrior2) {
            index2 = i;
        }

    }
    warriors[index1].battle(warriors[index2]);

    // show number of warriors
    cout << warriors[index1].getWarriorName() << " battles " << warriors[index2].getWarriorName() << endl;


}
