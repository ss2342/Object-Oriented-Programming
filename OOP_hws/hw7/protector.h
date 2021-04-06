//
// Satyen Singh
//

#ifndef HOMEWORKSANDLABSCS2124_PROTECTOR_H
#define HOMEWORKSANDLABSCS2124_PROTECTOR_H



#include <iostream>
#include <string>
#include <vector>


namespace WarriorCraft {

    class Noble;
    class Lord;

    class Protector {
    public:
        friend std::ostream&operator<<(std::ostream& os, const Protector& protector);
        Protector(const std::string& nameOfProtector, int strength);
        virtual void battlecry() const = 0;
        const std::string getProtectorName() const;
        const bool checkEmploymentStatus() const;
        void changeEmploymentStatus(bool newStatus);
        const bool checkDeath() const;
        void changeDeath(bool newDead);
        int getProtectorStrength() const;
        void changeProtectorStrength(double changeByFactorOf);
        void assignLord(Lord* aLord);
        void runaway();
    private:
        std::string protectorName;
        int strength;
        Lord* lord;
        bool dead;
        bool employmentStatus;
    };

    class Wizard : public Protector {
    public:

        Wizard(const std::string& nameOfWizard, int strength);
        void battlecry() const;

    private:

    };

    class Archer : public Protector {
    public:

        Archer(const std::string& nameOfArcher, int strength);
        void battlecry() const;

    private:
    };

    class Swordsman : public Protector {
    public:

        Swordsman(const std::string& nameOfSwordsman, int strength);
        void battlecry() const;
    private:

    };
}


#endif //HOMEWORKSANDLABSCS2124_PROTECTOR_H
