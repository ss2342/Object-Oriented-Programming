//
// Satyen Singh
// CS 2124

#include "warrior.h"
#include "noble.h"

using namespace std;

namespace WarriorCraft {
    const string Warrior::getWarriorName() const {
        return WarriorName;
    }
    const bool Warrior::checkEmploymentStatus() const {
        return employmentStatus;
    }
    void Warrior::changeEmploymentStatus(bool newStatus) {
        employmentStatus = newStatus;
    }
    int Warrior::getWarriorStrength() const {
        return WarriorStrength;
    }
    void Warrior::changeWarriorStrength(double changeByFactorOf) {
        WarriorStrength *= changeByFactorOf;
    }

    void Warrior::assignNoble(Noble* aNoble) {
        this->noble = aNoble;
    }

// initialization list
    Warrior::Warrior(const string& nameOfWarrior, int strengthOfWarrior) :
            WarriorName(nameOfWarrior), WarriorStrength(strengthOfWarrior), employmentStatus(false), noble(nullptr) {}

    void Warrior::runaway() {
        size_t warriorIndex = noble->find(this);
        noble->remove(warriorIndex);
        cout << this->getWarriorName() << " flees in terror, abandoning his lord, " << noble->getNobleName() << '.' << endl;
        noble = nullptr;
    }
}
