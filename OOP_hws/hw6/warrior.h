//
// Satyen Singh
// CS 2124

#ifndef HOMEWORKSANDLABSCS2124_WARRIOR_H
#define HOMEWORKSANDLABSCS2124_WARRIOR_H

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
    class Noble;
// Warrior Class
    class Warrior {

        //friend ostream&operator<<(ostream& os, const Warrior& aWarrior);


    public:
        // methods to get warrior names and strengths, check status of employment as well as
        // change employment status and strengths
        const std::string getWarriorName() const;
        const bool checkEmploymentStatus() const;
        void changeEmploymentStatus(bool newStatus);
        int getWarriorStrength() const;
        void changeWarriorStrength(double changeByFactorOf);
        void assignNoble(Noble* aNoble);
        // initialization list
        Warrior(const std::string& nameOfWarrior, int strengthOfWarrior);
        void runaway();
    private:
        Noble* noble;
        int WarriorStrength;
        std::string WarriorName;
        bool employmentStatus;

    };

}
#endif //HOMEWORKSANDLABSCS2124_WARRIOR_H
