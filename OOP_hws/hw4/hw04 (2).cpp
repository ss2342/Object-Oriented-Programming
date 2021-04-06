//
// Satyen Singh
// CS 2124
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// declaration of Noble so can use as friend
class Noble;


// Warrior Class
class Warrior {

    friend class Noble;
    friend ostream&operator<<(ostream& os, const Warrior& aWarrior);

public:

    // initialization list
    Warrior(const string &nameOfWarrior, int strengthOfWarrior) :
            WarriorName(nameOfWarrior), WarriorStrength(strengthOfWarrior) {}


private:
    // noble initially points to null
    Noble* noble = nullptr;
    int WarriorStrength;
    string WarriorName;


};

// Noble Class
class Noble{
public:


    friend ostream&operator<<(ostream& os, const Noble& noble) {
        os << noble.nobleName << " has an army of " << noble.armyofWarriors.size() << endl;
        for (size_t i = 0; i < noble.armyofWarriors.size(); ++i) {
            os << noble.armyofWarriors[i] -> WarriorName << ": " << noble.armyofWarriors[i] -> WarriorStrength << endl;
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
                    armyofWarriors[i]->WarriorStrength *= (armyStrength - opponentNoble.armyStrength);
                    armyofWarriors[i]->WarriorStrength /= armyStrength;
                }
                for (size_t i = 0; i < opponentNoble.armyofWarriors.size(); ++i) {
                    opponentNoble.armyofWarriors[i]->WarriorStrength = 0;
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
                    opponentNoble.armyofWarriors[i]->WarriorStrength *= (opponentNoble.armyStrength - armyStrength);
                    opponentNoble.armyofWarriors[i]->WarriorStrength /= opponentNoble.armyStrength;
                }
                for (size_t i = 0; i < armyofWarriors.size(); ++i) {
                    armyofWarriors[i]->WarriorStrength = 0;
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
                    opponentNoble.armyofWarriors[i]->WarriorStrength = 0;
                }
                for (size_t i = 0; i < armyofWarriors.size(); ++i) {
                    armyofWarriors[i]->WarriorStrength = 0;
                }
                cout << "Mutual Annihilation: " << nobleName << " and " << opponentNoble.nobleName << " die at each other's hands" << endl;
                armyStrength = 0;
                opponentNoble.armyStrength = 0;
            }

        }
    }



    // method to hire new warrior
    // check i
    void hire(Warrior& aWarrior) {
        if (!aWarrior.noble && dead != 1) {
            armyofWarriors.push_back(&aWarrior);
            armyStrength += aWarrior.WarriorStrength;
        }
        else {
            cout << "cannot hire!" << endl;
        }
    }
    // method to fire warrior
    void fire(Warrior& aWarrior) {
        int warriorIndex = find(&aWarrior, armyofWarriors);
        if (!aWarrior.noble && dead != 1) {
            cout <<"You don't work for me anymore "<< aWarrior.WarriorName << "! -- " << nobleName << '.' << endl;
            aWarrior.noble = nullptr;
            for (size_t i = warriorIndex + 1; i < armyofWarriors.size(); ++i) {
                armyofWarriors[i] = armyofWarriors[i-1];
            }
            armyStrength -= aWarrior.WarriorStrength;
            armyofWarriors.pop_back();
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

ostream& operator << (ostream& os, const Warrior& aWarrior) {
    os << "Warrior: " << aWarrior.WarriorName << aWarrior.WarriorStrength;
    return os;
}

int main() {

    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    cout << "==========\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

    art.fire(cheetah);
    cout << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

}


