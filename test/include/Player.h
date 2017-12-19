#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>


class Player
{
    public:
        Player(std::string, int, int); // name, lvl, exp
        void setPlayerName(std::string);
        void setPlayerLvl(int);
        void setPlayerExp(int);
        void setPlayerHp(int);
        void setDamage(int);
        std::string getPlayerName();
        int getPlayerLvl();
        int getPlayerExp();
        int getPlayerHp();
        int getDamage();

    private:
        int hp;
        int dmg;
        int lvl;
        std::string name;
        int exp;
};

#endif // PLAYER_H
