#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>


class Player
{
    public:
        Player(std::string, int, int, int, int); // name, lvl, exp
        void setPlayerName(std::string);
        void setPlayerLvl(int);
        void setPlayerExp(int);
        void setPlayerHp(int);
        void setDamage(int);
        void setPlayerExpMax(int);
        void setPlayerLvlHp(int);
        void setPlayerLvlDmg(int);
        void setPlayerMaxHp(int);
        void setPlayerMoney(int);

        std::string getPlayerName();
        int getPlayerLvl();
        int getPlayerExp();
        int getPlayerHp();
        int getDamage();
        int getPlayerExpMax();
        int getPlayerLvlHp();
        int getPlayerLvlDmg();
        int getPlayerMaxHp();
        int getPlayerMoney();

    private:
        int hp;
        int lvlHp;
        int maxHp;
        int dmg;
        int lvlDmg;
        int lvl;
        std::string name;
        int expToLvlUp;
        int exp;
        int money;
};

#endif // PLAYER_H
