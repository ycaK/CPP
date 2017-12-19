#ifndef MOB_H
#define MOB_H
#include <iostream>
#include <string>


class Mob
{
    public:
        Mob(std::string, int, int); // name , hp, dmg

        void setMobName(std::string);
        void setMobHp(int);
        void setMobDmg(int);

        std::string getMobName();
        int getMobHp();
        int getMobDmg();
    private:
        int hp;
        int dmg;
        std::string name;
};

#endif // MOB_H
