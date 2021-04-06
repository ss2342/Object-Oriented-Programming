
////
//// Satyen Singh
//// CS 2124
////

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// declaration of Noble so can use as friend
class Noble;
class Warrior;


// Warrior Class
class Warrior {

    friend ostream&operator<<(ostream& os, const Warrior& aWarrior);


public:
    // methods to get warrior names and strengths, check status of employment as well as
    // change employment status and strengths
    const string getWarriorName() const {
        return WarriorName;
    }
    const bool checkEmploymentStatus() const {
        return employmentStatus;
    }
    void changeEmploymentStatus(bool newStatus) {
        employmentStatus = newStatus;
    }
    int getWarriorStrength() const {
        return WarriorStrength;
    }
    void changeWarriorStrength(double changeByFactorOf) {
        WarriorStrength *= changeByFactorOf;
    }

    // initialization list
    Warrior(const string &nameOfWarrior, int strengthOfWarrior) :
            WarriorName(nameOfWarrior), WarriorStrength(strengthOfWarrior), employmentStatus(false) {}
private:
    int WarriorStrength;
    string WarriorName;
    bool employmentStatus;

};


// Noble Class
class Noble{
public:

    const string getNobleName() const {
        return nobleName;
    }


    friend ostream&operator<<(ostream& os, const Noble& noble) {
        os << noble.nobleName << " has an army of " << noble.armyofWarriors.size() << endl;
        for (size_t i = 0; i < noble.armyofWarriors.size(); ++i) {
            os << noble.armyofWarriors[i] -> getWarriorName() << ": " << noble.armyofWarriors[i] -> getWarriorStrength() << endl;
        }

        return os;
    }

    Noble(const string& nameOfNoble) :
        nobleName(nameOfNoble) {}

    void battle(Noble& opponentNoble) {


        cout << nobleName << " battles " << opponentNoble.nobleName << endl;
        // if first warrior stronger than second
        if (armyStrength > opponentNoble.armyStrength) {

            // if second warrior is already dead
            if (opponentNoble.armyStrength == 0) {
                cout << "He's dead, " <<    nobleName << endl;

            }
            else {

                for(size_t i = 0; i < armyofWarriors.size(); ++i) {
                    armyofWarriors[i]->changeWarriorStrength(armyStrength - opponentNoble.armyStrength);
                    armyofWarriors[i]->changeWarriorStrength(1.00/armyStrength);
                }
                for (size_t i = 0; i < opponentNoble.armyofWarriors.size(); ++i) {
                    opponentNoble.armyofWarriors[i]->changeWarriorStrength(0);
                }
                opponentNoble.armyStrength = 0;
                opponentNoble.dead = true;
                cout << nobleName << " beats " << opponentNoble.nobleName << endl;
            }

        }

            // if first warrior is weaker than the second warrior
        else if (armyStrength < opponentNoble.armyStrength) {

            // if first warrior is already dead
            if (armyStrength == 0) {
                cout << "You're already dead, " << nobleName << endl;
            }
            else {
                for(size_t i = 0; i < opponentNoble.armyofWarriors.size(); ++i) {
                    opponentNoble.armyofWarriors[i]-> changeWarriorStrength(opponentNoble.armyStrength - armyStrength);
                    opponentNoble.armyofWarriors[i]->changeWarriorStrength(1.00/opponentNoble.armyStrength);
                }
                for (size_t i = 0; i < armyofWarriors.size(); ++i) {
                    armyofWarriors[i]->changeWarriorStrength(0);
                }
                armyStrength = 0;
                dead = true;
                cout << nobleName << " loses to " << opponentNoble.nobleName << endl;
            }

        }

            // if first warrior and second warrior have equal strength
        else {

            // if both warriors are already dead
            if (armyStrength == 0 && opponentNoble.armyStrength == 0) {
                cout << "Oh, NO! They're both dead! Yuck! " << endl;
            }
            else {
                for (size_t i = 0; i < opponentNoble.armyofWarriors.size(); ++i) {
                    opponentNoble.armyofWarriors[i]->changeWarriorStrength(0);
                }
                for (size_t i = 0; i < armyofWarriors.size(); ++i) {
                    armyofWarriors[i]->changeWarriorStrength(0);
                }
                cout << "Mutual Annihilation: " << nobleName << " and " << opponentNoble.nobleName << " die at each other's hands" << endl;
                armyStrength = 0;
                opponentNoble.armyStrength = 0;
            }

        }
    }



    // method to hire new warrior
    // check if unemployed and isn't dead
    void hire(Warrior& aWarrior) {
        if (!aWarrior.checkEmploymentStatus() && dead != 1) {
            armyofWarriors.push_back(&aWarrior);
            armyStrength += aWarrior.getWarriorStrength();
            aWarrior.changeEmploymentStatus(true);
        }
        else {
            cout << "cannot hire!" << endl;
        }
    }
    // method to fire warrior
    // check employment status and whether dead or alive
    void fire(Warrior& aWarrior) {
        int warriorIndex = find(&aWarrior, armyofWarriors);
        if (aWarrior.checkEmploymentStatus() && dead != 1) {
            cout <<"You don't work for me anymore "<< aWarrior.getWarriorName() << "! -- " << nobleName << '.' << endl;
            aWarrior.changeEmploymentStatus(false);
            for (size_t i = warriorIndex + 1; i < armyofWarriors.size(); ++i) {
                armyofWarriors[i] = armyofWarriors[i-1];
            }
            armyofWarriors.pop_back();
            armyStrength -= aWarrior.getWarriorStrength();

        }
        else {
            cout << "cannot fire!" << endl;
        }
    }
    // find index of specific warrior
    int find(Warrior* aWarrior, vector<Warrior*> warriors) {
        for (size_t i = 0; i < warriors.size(); ++i) {
            if (warriors[i] == aWarrior) {
                return i;
            }
        }
    }


private:
    const string nobleName;
    int armyStrength = 0;
    bool dead = false;
    vector<Warrior*> armyofWarriors;

};

// output operator for warrior
ostream& operator << (ostream& os, const Warrior& aWarrior) {
    os << "Warrior: " << aWarrior.WarriorName << ' ' << aWarrior.WarriorStrength;
    return os;
}

// declaration of classes
void hireWarrior(ifstream& noblesWarriorStream, vector<Noble*> noblePointers, vector<Warrior*> warriorPointers);
void fireWarrior(ifstream& noblesWarriorStream, vector<Noble*> noblePointers, vector<Warrior*> warriorPointers);
void status(vector<Noble*> noblePointers, vector<Warrior*> warriorPointers);
void battleWarriors(ifstream& nobleWarriorStream, vector<Noble*>& noblePointers);

int main() {

    // read files into a vector of pointers to nobles, pointers to warriors
    ifstream nobleWarriorsStream;
    nobleWarriorsStream.open("nobleWarriors.txt");
    string command;
    string nobleName;
    string warriorName;
    int warriorStrength;

    vector<Warrior*> pointerToWarriors;
    vector<Noble*> pointerToNobles;
    while (nobleWarriorsStream >> command) {
        bool nobleExists = false;
        if (command == "Noble") {
            nobleWarriorsStream >> nobleName;
            for (size_t i = 0; i < pointerToNobles.size(); ++i) {
                // cannot add noble that already exists in vector
                if (pointerToNobles[i]->getNobleName() == nobleName) {
                    nobleExists = true;
                    cout << nobleName << " exists, cannot add again." << endl;
                }
            }

            // put noble object on heap
            if (!nobleExists) {
                Noble* noblePtr = new Noble(nobleName);
                pointerToNobles.push_back(noblePtr);

            }

        }

        else if (command == "Warrior") {
            bool warriorExists = false;
            nobleWarriorsStream >> warriorName >> warriorStrength;
            for (size_t i = 0; i < pointerToWarriors.size(); ++i) {
                if (pointerToWarriors[i]->getWarriorName() == warriorName) {
                    // cannot add warrior that already exists
                    warriorExists = true;
                    cout << warriorName << "exists, cannot add again." << endl;
                }
            }
            if (!warriorExists) {
                // put warrior on heap
                Warrior *warriorPtr = new Warrior(warriorName, warriorStrength);
                pointerToWarriors.push_back(warriorPtr);
            }

        }
            // if command = Hire, hire warrior
        else if (command == "Hire") {
            hireWarrior(nobleWarriorsStream, pointerToNobles, pointerToWarriors);
        }

            // if command = Status, display number of warriors, names, and current strengths
        else if (command == "Status") {
            status(pointerToNobles, pointerToWarriors);
        }
            // if command = Fire, fire warrior
        else if (command == "Fire") {
            fireWarrior(nobleWarriorsStream, pointerToNobles, pointerToWarriors);

        }

            // if command = Battle, initiate a battle between the two specified warriors
        else if (command == "Battle") {
            battleWarriors(nobleWarriorsStream, pointerToNobles);
        }
            // if command = Clear, delete nobles and warriors off of heap and clear vectors
        else if (command == "Clear") {
            for (size_t i = 0; i < pointerToNobles.size(); ++i) {
                delete pointerToNobles[i];
            }
            pointerToNobles.clear();

            for (size_t i = 0; i < pointerToWarriors.size(); ++i) {
                delete pointerToWarriors[i];
            }
            pointerToWarriors.clear();
        }
    }
    nobleWarriorsStream.close();
}

void hireWarrior(ifstream& noblesWarriorStream, vector<Noble*> noblePointers, vector<Warrior*> warriorPointers) {
    // loop through noble and warrior pointer vectors and find index of noble and warrior
    // use method in noble class, hire, aNoble.hire(aWarrior)
    string nobleName;
    string warriorName;
    int index1;
    int index2;
    noblesWarriorStream >> nobleName >> warriorName;
    for (size_t i = 0; i < warriorPointers.size(); ++i) {
        if (warriorPointers[i] -> getWarriorName() == warriorName) {
            index1 = i;
        }
    }


    for(size_t i = 0; i < noblePointers.size(); ++i) {
        if (noblePointers[i]->getNobleName() == nobleName) {
            index2 = i;
        }
    }

    (*noblePointers[index2]).hire(*warriorPointers[index1]);

}

void fireWarrior(ifstream& noblesWarriorStream, vector<Noble*> noblePointers, vector<Warrior*> warriorPointers) {
    // loop through noble and warrior pointer vectors and find index of noble and warrior
    // use method in noble class, hire, aNoble.fire(aWarrior)
    string nobleName;
    string warriorName;
    int index1;
    int index2;
    noblesWarriorStream >> nobleName >> warriorName;
    for (size_t i = 0; i < warriorPointers.size(); ++i) {
        if (warriorPointers[i] -> getWarriorName() == warriorName) {
            index1 = i;
        }
    }


    for(size_t i = 0; i < noblePointers.size(); ++i) {
        if (noblePointers[i]->getNobleName() == nobleName) {
            index2 = i;
        }
    }

    (*noblePointers[index2]).fire(*warriorPointers[index1]);

}

void status(vector<Noble*> noblePointers, vector<Warrior*> warriorPointers) {
    // display status of all nobles, as well as show unemployed warriors, if any
    int unemployed_count = 0;
    cout << "Status" << endl << "======" << endl;
    cout << "Nobles: " << endl;
    if (noblePointers.size() > 0) {
        for (size_t i = 0; i < noblePointers.size(); ++i) {
            cout << *noblePointers[i] << endl;
        }
    }
    else {
        cout << "NONE" << endl;
    }

    cout << "Unemployed Warriors: " << endl;
    for (size_t i = 0; i < warriorPointers.size(); ++i) {
        if (!warriorPointers[i]->checkEmploymentStatus()) {
            unemployed_count += 1;
            cout << warriorPointers[i]->getWarriorName() << ' ' << warriorPointers[i]->getWarriorStrength()<< endl;
        }
    }

    if (unemployed_count == 0) {
        cout << "NONE" << endl;
    }

}

void battleWarriors(ifstream& nobleWarriorStream, vector<Noble*>& noblePointers) {
    // loop through noble and warrior pointer vectors and find index of two nobles that are going to battle
    // use method in noble class, hire, aNoble.battle(opponentNoble)
    string noble1;
    string noble2;
    int index1;
    int index2;
    nobleWarriorStream >> noble1 >> noble2;

    for (size_t i = 0; i < noblePointers.size(); ++i) {

        // find position of 2 warriors in battle
        if (noblePointers[i]->getNobleName() == noble1)
            index1 = i;
        if (noblePointers[i]->getNobleName() == noble2) {
            index2 = i;
        }
    }
    (*noblePointers[index1]).battle(*noblePointers[index2]);

}













