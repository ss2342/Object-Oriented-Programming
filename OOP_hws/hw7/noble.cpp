////
//// Satyen Singh
//// CS 2124
//
#include "protector.h"
#include "noble.h"

using namespace std;

namespace WarriorCraft {
    const string& Noble::getNobleName() const {
        return nobleName;
    }

    int Noble::getNobleStrength() const {
        return nobleStrength;
    }

    void Noble::setNobleStrength(double changeByFactorOf) {
        nobleStrength *= changeByFactorOf;
    }

    void Noble::changeNobleStrength(double addOrSubtract) {
        nobleStrength += addOrSubtract;
    }

    ostream&operator<<(ostream& os, const Lord& lord) {
        os << lord.getNobleName() << " has an army of " << lord.armyOfProtectors.size() << endl;
        for (size_t i = 0; i < lord.armyOfProtectors.size(); ++i) {
            os <<"       " << lord.armyOfProtectors[i] -> getProtectorName() <<
            ": " << lord.armyOfProtectors[i] -> getProtectorStrength() << endl;
        }
        return os;
    }

    ostream&operator<<(std::ostream& os, const PersonWithStrengthToFight& noble) {
        os << noble.getNobleName() << ": " << noble.getNobleStrength() << endl;
        return os;
    }

    Noble::Noble(const string& nameOfNoble, int strength) :
            nobleName(nameOfNoble), nobleStrength(strength), dead(false) {}

    PersonWithStrengthToFight::PersonWithStrengthToFight(const string& nameOfPWSTF, int strength) :
                               Noble(nameOfPWSTF, strength) {}

    Lord::Lord(const string& nameOfFLord, int strength) :
            Noble(nameOfFLord, strength) {}


    void Noble::battle(Noble& opponentNoble) {


        cout << nobleName << " battles " << opponentNoble.nobleName << endl;

        if (dead && opponentNoble.dead) {
            cout << "Oh, NO! They're both dead! Yuck! " << endl;
        }

        else if (opponentNoble.dead) {
            battlecry();
            opponentNoble.battlecry();
            cout << "He's dead, " << nobleName << endl;

        }

        else if (dead) {
            cout << "He's dead, " << opponentNoble.nobleName << endl;
        }

        // if first warrior stronger than second
        else if (getNobleStrength() > opponentNoble.getNobleStrength()) {
            battlecry();
            opponentNoble.battlecry();
            decreaseStrength(opponentNoble);
            opponentNoble.suicide();
            cout << "Ugh!" << endl;
            cout << nobleName << " beats " << opponentNoble.nobleName << endl;

        }

            // if first warrior is weaker than the second warrior
        else if (getNobleStrength() < opponentNoble.getNobleStrength()) {
            battlecry();
            opponentNoble.battlecry();
            opponentNoble.decreaseStrength(*this);
            this->suicide();
            cout << "Ugh!" << endl;
            cout << opponentNoble.getNobleName() << " defeats " << nobleName << endl;

        }

            // if first warrior and second warrior have equal strength
        else {
            suicide();
            opponentNoble.suicide();
            cout << "Mutual Annihilation: " << nobleName << " and " << opponentNoble.nobleName
            << " die at each other's hands" << endl;
            }
        }



    void Lord::battlecry() {
        for (size_t i = 0; i < armyOfProtectors.size(); ++i) {
            armyOfProtectors[i]->battlecry();
        }
    }

    void PersonWithStrengthToFight::battlecry() {
    }

    bool Noble::checkDeath() const {
        return dead;
    }

    void Noble::changeDeath(bool newDeath) {
        dead = newDeath;
    }



// method to hire new warrior
// check if unemployed and isn't dead
    void Lord::hires(Protector& aProtector) {
        if (!aProtector.checkEmploymentStatus() && aProtector.checkDeath() != 1 && this->checkDeath() != 1) {
            armyOfProtectors.push_back(&aProtector);
            armyStrength += aProtector.getProtectorStrength();
            changeNobleStrength(aProtector.getProtectorStrength());
            aProtector.changeEmploymentStatus(true);
            aProtector.assignLord(this);
        }
        else {
            cout << "cannot hire!" << endl;
        }
    }
// method to fire warrior
// check employment status and whether dead or alive
    void Lord::fires(Protector& aProtector) {
        int warriorIndex = find(&aProtector);
        if (aProtector.checkEmploymentStatus() && aProtector.checkDeath() != 1 && this->checkDeath() != 1) {
            cout <<"You don't work for me anymore "<< aProtector.getProtectorName() << "! -- " << getNobleName() << '.' << endl;
            aProtector.changeEmploymentStatus(false);
            for (size_t i = warriorIndex + 1; i < armyOfProtectors.size(); ++i) {
                armyOfProtectors[i] = armyOfProtectors[i-1];
            }
            armyOfProtectors.pop_back();
            armyStrength -= aProtector.getProtectorStrength();
            changeNobleStrength(-armyStrength);

        }
        else {
            cout << "cannot fire!" << endl;
        }
    }



// find index of specific warrior
    int Lord::find(Protector* aProtector) {
        size_t index;
        for (size_t i = 0; i < armyOfProtectors.size(); ++i) {
            if (armyOfProtectors[i] == aProtector) {
                index = i;
            }
        }
        return index;
    }

    void Lord::remove(size_t index) {

        for (size_t i = index; i < armyOfProtectors.size(); ++i) {
            armyOfProtectors[i] = armyOfProtectors[armyOfProtectors.size()-1];
        }
        armyStrength -= armyOfProtectors[armyOfProtectors.size()-1]->getProtectorStrength();
        armyOfProtectors.pop_back();
    }

    void Lord::suicide() {
        for (size_t i = 0; i < armyOfProtectors.size(); ++i) {
            armyOfProtectors[i]->changeProtectorStrength(0);
            armyOfProtectors[i]->changeDeath(true);
        }
        armyStrength = 0;
        changeDeath(true);
    }

    void PersonWithStrengthToFight::suicide() {
        setNobleStrength(0);
        changeDeath(true);
    }

    void Lord::decreaseStrength(Noble &opponentNoble) {
        for (size_t i = 0; i < armyOfProtectors.size(); ++i) {
            armyOfProtectors[i]->changeProtectorStrength(armyStrength - opponentNoble.getNobleStrength());
            armyOfProtectors[i]->changeProtectorStrength(1.00/armyStrength);
        }
    }

    void PersonWithStrengthToFight::decreaseStrength(Noble &opponentNoble) {
        setNobleStrength(getNobleStrength() - opponentNoble.getNobleStrength());
        setNobleStrength(1/getNobleStrength());
    }

}
