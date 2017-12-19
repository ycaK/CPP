#include <iostream>
#include <time.h>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include "Player.h"
#include "Mob.h"
#include "Item.h" // Testing
//#include "stdafx.h"

//TODO: Item makeIt <- Delete input and make better way of adding/changing potions!

Player battle(Player accout);
Player expCalc(Player account);

Item potion1("Heal Potion", "defense", "heal", 1, 1);
Item makeIt(Item potion1);

int main(){
    Player account("Kacy", 1, 1);
    account.setDamage(75);
    account.setPlayerHp(550);
    while(true)
   {
       account = battle(account);
   }
}

Item makeIt(Item potion1)
{
    std::string option;
    std::cin >> option;
    if(option == "dmg-boost"){
        potion1.setPotionName("DMG Boost");
        potion1.setPotionType("defense");
        potion1.setPotionEffect("dmg_boost");
        potion1.setPotionPower(1);
        potion1.setPotionQuantity(1);
        system("cls");
        return potion1;
    }
    else{
        system("cls");
        return potion1;
    }

}

Player expCalc(Player account, Mob Karthus)
{
    account.setPlayerExp(account.getPlayerExp() + Karthus.getMobDifficulty() * 10);
    std::cout << "Player gained: " << Karthus.getMobDifficulty() * 10 << " experience!" << std::endl;
    std::cout << "You have now: " << account.getPlayerExp() << " experience!" << std::endl;
    system("pause");
    system("cls");
    return account;
}

Player battle(Player accout)
{
    std::string option;
    srand(time(NULL));
    int mGroup = (rand() % 2);
    int mClass = (rand() % 3);
    int diff = (rand() & 20);
    std::string mobs[2][3] = {{"Dragon", "Baby Dragon", "Elder Dragon"}, {"Akali", "Garen", "Wukong"}};
    Mob Karthus(mobs[mGroup][mClass], 25 * diff, 5 * diff, diff);
    do
    {
        std::cout << "A for attack, R for retreat, I to use item, S for player's stats, C for monster's stats: ";
        std::cin >> option;
        Sleep(250);
        system("cls");
        if(option == "R" || option == "r")
        {
            system("cls");
            std::cout << "You have successfully escaped!" << std::endl;
            Sleep(1500);
            system("cls");
            return accout;
        }
        else
        {
            if(option == "A" || option == "a")
            {
                system("cls");
                accout.setPlayerHp(accout.getPlayerHp() - Karthus.getMobDmg());
                Karthus.setMobHp(Karthus.getMobHp() - accout.getDamage());
                std::cout << "You have attacked " << Karthus.getMobName() << " for " << accout.getDamage() << " damage!" << std::endl;
                std::cout << Karthus.getMobName() << " attacked you for " << Karthus.getMobDmg() << " damage!" << std::endl;
                std::cout << "You have now " << accout.getPlayerHp() << " health points" << std::endl;
                std::cout << Karthus.getMobName() << " have now " << Karthus.getMobHp() << " health points" << std::endl;
                system("pause");
                system("cls");
            }
            else
            {
                if(option == "I" || option == "i")
                    {
                        std::string selectPot;
                        system("cls");
                        potion1 = makeIt(potion1);
                        std::cout << "Items: " << std::endl;
                        std::cout << " [0] " << potion1.getPotionName() << " x " << potion1.getPotionQuantity() << std::endl;
                        std::cout << std::endl << std::endl << " Select Number: ";
                        std::cin >> selectPot;
                        if(selectPot == "0"){
                            if(potion1.getPotionQuantity() > 0)
                                {
                                if(potion1.getPotionType() == "defense"){
                                    if(potion1.getPotionEffect() == "heal"){
                                        accout.setPlayerHp(accout.getPlayerHp() + 100 * potion1.getPotionPower());
                                        potion1.setPotionQuantity(potion1.getPotionQuantity() - 1);
                                        std::cout << " + " << 100 * potion1.getPotionPower() << " HP" << std::endl;
                                        std::cout << "You are know " << accout.getPlayerHp() << " HP" << std::endl;
                                    }else
                                        {
                                            if(potion1.getPotionEffect() == "dmg_boost")
                                            {
                                                accout.setDamage(accout.getDamage() + 10 * potion1.getPotionPower());
                                                potion1.setPotionQuantity(potion1.getPotionQuantity() - 1);
                                                std::cout << " + " << 10 * potion1.getPotionPower() << " DMG" << std::endl;
                                                std::cout << "You have know " << accout.getDamage() << " DMG" << std::endl;
                                            }else
                                            {
                                                std::cout << "#@# POT ERROR #@#!" << std::endl;
                                            }
                                        }
                                }else
                                    {
                                        if(potion1.getPotionType() == "attack")
                                        {
                                            std::cout << "No Potion Programed for attack!" << std::endl;
                                        }else{
                                            std::cout << "#@# POT ERROR #@#" << std::endl;
                                        }
                                    }
                                }else
                                    {
                                        std::cout << "Not enough potions!" << std::endl;
                                    }
                            }else
                                {
                                    std::cout << "#@# EROOR #@#" << std::endl;
                                }

                        Sleep(2500);
                        system("cls");
                    }else
                    {
                        if(option == "S" || option == "s")
                        {
                            std::cout << " -- Player's stats -- " << std::endl;
                            std::cout << " - Name: " << accout.getPlayerName() << std::endl;
                            std::cout << " - HP: " << accout.getPlayerHp() << std::endl;
                            std::cout << " - DMG: " << accout.getDamage() << std::endl;
                            std::cout << " - LVL: " << accout.getPlayerLvl() << std::endl;
                            std::cout << " - EXP: " << accout.getPlayerExp() << std::endl;
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            if(option == "C" || option == "c")
                            {
                                std::cout << " -- Monsters's stats -- " << std::endl;
                                std::cout << " - Type: " << Karthus.getMobName() << std::endl;
                                std::cout << " - HP: " << Karthus.getMobHp() << std::endl;
                                std::cout << " - DMG: " << Karthus.getMobDmg() << std::endl;
                                std::cout << " - Difficulty: " << Karthus.getMobDifficulty() << std::endl;
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                std::cout << "#@#ERROR#@# Wrong option #@#ERROR#@#" << std::endl;
                                Sleep(1000);
                                system("cls");
                            }
                        }
                    }
            }
        }


    } while(accout.getPlayerHp() > 0 && Karthus.getMobHp() > 0);
    if(accout.getPlayerHp() <= 0){
        system("cls");
        std::cout << "# GAMEOVER #" << std::endl;
        system("cls");
        return accout;
    }
    else
    {
        system("cls");
        std::cout << "# You have won #" << std::endl;
        accout = expCalc(accout, Karthus);
        return accout;
    }
}
