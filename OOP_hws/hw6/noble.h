//
// Satyen Singh
// CS 2124

#ifndef HOMEWORKSANDLABSCS2124_NOBLE_H
#define HOMEWORKSANDLABSCS2124_NOBLE_H

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
    class Warrior;

// Noble Class
    class Noble{
    public:

        const std::string getNobleName() const;


        friend std::ostream&operator<<(std::ostream& os, const Noble& noble);

        Noble(const std::string& nameOfNoble);

        void battle(Noble& opponentNoble);



        // method to hire new warrior
        // check if unemployed and isn't dead
        void hire(Warrior& aWarrior);
        // method to fire warrior
        void fire(Warrior& aWarrior);



        // find index of specific warrior
        int find(Warrior* aWarrior);

        // remove warrior at index
        void remove(size_t index);



    private:
        const std::string nobleName;
        int armyStrength;
        bool dead;
        std::vector<Warrior*> armyofWarriors;

    };
}

#endif //HOMEWORKSANDLABSCS2124_NOBLE_H
