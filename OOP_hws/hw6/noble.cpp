//
// Satyen Singh
// CS 2124

#include "warrior.h"
#include "noble.h"

using namespace std;

namespace WarriorCraft {
    const string Noble::getNobleName() const {
        return nobleName;
    }


    ostream&operator<<(ostream& os, const Noble& noble) {
        os << noble.nobleName << " has an army of " << noble.armyofWarriors.size() << endl;
        for (size_t i = 0; i < noble.armyofWarriors.size(); ++i) {
            os <<"       " << noble.armyofWarriors[i] -> getWarriorName() << ": " << noble.armyofWarriors[i] -> getWarriorStrength() << endl;
        }

        return os;
    }

    Noble::Noble(const string& nameOfNoble) :
            nobleName(nameOfNoble), armyStrength(0), dead(false) {}

    void Noble::battle(Noble& opponentNoble) {


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
    void Noble::hire(Warrior& aWarrior) {
        if (!aWarrior.checkEmploymentStatus() && dead != 1) {
            armyofWarriors.push_back(&aWarrior);
            armyStrength += aWarrior.getWarriorStrength();
            aWarrior.changeEmploymentStatus(true);
            aWarrior.assignNoble(this);

        }
        else {
            cout << "cannot hire!" << endl;
        }
    }
// method to fire warrior
// check employment status and whether dead or alive
    void Noble::fire(Warrior& aWarrior) {
        int warriorIndex = find(&aWarrior);
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
    int Noble::find(Warrior* aWarrior) {
        size_t index;
        for (size_t i = 0; i < armyofWarriors.size(); ++i) {
            if (armyofWarriors[i] == aWarrior) {
                index = i;
            }
        }
        return index;
    }

    void Noble::remove(size_t index) {

        for (size_t i = index; i < armyofWarriors.size(); ++i) {
            armyofWarriors[i] = armyofWarriors[armyofWarriors.size()-1];
        }
        armyStrength -= armyofWarriors[armyofWarriors.size()-1]->getWarriorStrength();
        armyofWarriors.pop_back();
    }
}
