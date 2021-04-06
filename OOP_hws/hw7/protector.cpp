//
// Satyen Singh
//

#include "protector.h"
#include "noble.h"

using namespace std;

namespace WarriorCraft {

    ostream&operator<<(std::ostream& os, const Protector& protector) {
        os << protector.getProtectorName() << ": " << protector.getProtectorStrength() << endl;
        return os;
    }

    Protector::Protector(const string& nameOfProtector, int strength) :
               protectorName(nameOfProtector), strength(strength), lord(nullptr), dead(false)
               ,employmentStatus(false) {}

    Wizard::Wizard(const string& nameOfWizard, int strength) :
            Protector(nameOfWizard, strength) {}

    Archer::Archer(const string& nameOfArcher, int strength) :
            Protector(nameOfArcher, strength) {}

    Swordsman::Swordsman(const string& nameOfSwordsman, int strength) :
            Protector(nameOfSwordsman, strength) {}

    const string Protector::getProtectorName() const {
        return protectorName;
    }
    const bool Protector::checkEmploymentStatus() const {
        return employmentStatus;
    }

    void Protector::changeDeath(bool newDead) {
        dead = newDead;
    }

    const bool Protector::checkDeath() const {
        return dead;
    }
    void Protector::changeEmploymentStatus(bool newStatus) {
        employmentStatus = newStatus;
    }
    int Protector::getProtectorStrength() const {
        return strength;
    }
    void Protector::changeProtectorStrength(double changeByFactorOf) {
        strength *= changeByFactorOf;
    }
//
    void Protector::assignLord(Lord* aLord) {
        this->lord = aLord;
    }

    void Protector::runaway() {
        size_t warriorIndex = lord->find(this);
        lord->remove(warriorIndex);
        cout << this->getProtectorName() << " flees in terror, abandoning his lord, " << lord->getNobleName() << '.'
             << endl;
        lord = nullptr;
    }

    void Protector::battlecry() const {
        cout << getProtectorName() << " says, Take that in the name of my lord, " << lord->getNobleName() << endl;
    }

    void Wizard::battlecry() const {
        cout << "POOF!  ";
        Protector::battlecry();
    }

    void Archer::battlecry() const {
        cout << "TWANG!  ";
        Protector::battlecry();
    }

    void Swordsman::battlecry() const {
        cout << "CLANG!  ";
        Protector::battlecry();
    }


}

