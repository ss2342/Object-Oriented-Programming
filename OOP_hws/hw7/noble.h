////
//// Satyen Singh
//// CS 2124
//
#ifndef HOMEWORKSANDLABSCS2124_NOBLE_H
#define HOMEWORKSANDLABSCS2124_NOBLE_H

#include <iostream>
#include <string>
#include <vector>


namespace WarriorCraft {
    class Protector;

// Noble Class
    class Noble{
    public:

        const std::string& getNobleName() const;


        friend std::ostream&operator<<(std::ostream& os, const Noble& noble);

        Noble(const std::string& nameOfNoble, int strength = 0);

        void battle(Noble& opponentNoble);

        int getNobleStrength() const;

        // change in battle
        void setNobleStrength(double changeByFactorOf);

        // change while hiring and firing
        void changeNobleStrength(double addOrSubtract);

        bool checkDeath() const;

        void changeDeath(bool newDeath);

        virtual void decreaseStrength(Noble& opponentNoble) = 0;

        virtual void suicide() = 0;

        virtual void battlecry() = 0;



        // method to hire new warrior
        // check if unemployed and isn't dead




    private:
        const std::string nobleName;
        int nobleStrength;
        bool dead;


    };

    class PersonWithStrengthToFight : public Noble {
    public:

        friend std::ostream&operator<<(std::ostream& os, const PersonWithStrengthToFight& noble);

        PersonWithStrengthToFight(const std::string& nameOfNoble, int strength = 0);

        void suicide();

        void battlecry();


        void decreaseStrength(Noble& noble);

    private:

    };

    class Lord : public Noble {
    public:
        friend std::ostream&operator<<(std::ostream& os, const Lord& noble);


        Lord(const std::string& nameOfNoble, int strength = 0);



        void hires(Protector& aProtector);
        // method to fire warrior
        void fires(Protector& aProtector);

        void battlecry();



        // find index of specific warrior
        int find(Protector* aProtector);

        // remove warrior at index
        void remove(size_t index);

        void suicide();

        void decreaseStrength(Noble& noble);



    private:
        std::vector<Protector*> armyOfProtectors;
        int armyStrength = 0;

    };
}

#endif //HOMEWORKSANDLABSCS2124_NOBLE_H
