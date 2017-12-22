#ifndef MOB_H
#define MOB_H
#include <iostream>
#include <string>


class Mob
{
    public:
        Mob(std::string, int, int, int); // name , hp, dmg

        void setMobName(std::string);
        void setMobHp(int);
        void setMobDmg(int);
        void setMobDifficulty(int);

        std::string getMobName();
        int getMobHp();
        int getMobDmg();
        int getMobDifficulty();
    private:
        int hp;
        int dmg;
        int difficulty;
        std::string name;
};

#endif // MOB_H
