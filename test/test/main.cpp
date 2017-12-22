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
//TODO: Make buffs from lvlups!


Player battle(Player accout);
Player expCalc(Player account, Mob Karthus);
Player lvlUp(Player account);
Player shop(Player account);

Item potion1("Heal Potion", "defense", "heal", 1, 1);
Item makeIt(Item potion1);

int main(){
    Player account("Kacy", 0, 0, 0, 0); // Name | LvL | Exp | Bonus to HP | Bonus to DMG |
    account.setDamage(75);
    account.setPlayerMaxHp(550);
    account.setPlayerHp(account.getPlayerMaxHp());
    account.setPlayerExpMax(100);
    while(true)
   {
       account = battle(account);
   }
}

Item makeIt(Item potion, std::string name, std::string type, std::string effect, int power, int quantity)
{
    potion.setPotionName("DMG Boost");
    potion.setPotionType("defense");
    potion.setPotionEffect("dmg_boost");
    potion.setPotionPower(1);
    potion.setPotionQuantity(1);
    system("cls");
    return potion;
}

Player lvlUp(Player account)
{
    if(account.getPlayerExp() >= account.getPlayerExpMax())
    {
        account.setPlayerLvl(account.getPlayerLvl() + 1);
        account.setPlayerExpMax(account.getPlayerExpMax() + 100);
        account.setPlayerExp(account.getPlayerExp() - 100 * account.getPlayerLvl());
        account.setPlayerLvlHp(150 * account.getPlayerLvl());
        account.setPlayerMaxHp(550 + account.getPlayerLvlHp());
        account.setPlayerLvlDmg(25 * account.getPlayerLvl());
        account.setDamage(75 + account.getPlayerLvlDmg());
        account.setPlayerHp(account.getPlayerMaxHp());
        std::cout << "[ You have leveled up! ]" << std::endl;
        std::cout << std::endl << "[ You are now lvl: " << account.getPlayerLvl() << " ]" << std::endl << std::endl;
        std::cout << "[ Your HP has been restored! ]" << std::endl;
        std::cout << "[ You have now: " << account.getPlayerLvlHp() << "+ HP and " << account.getPlayerLvlDmg() << "+ DMG ]" << std::endl << std::endl;
        system("pause");
        system("cls");
        return account;
    }
    return account;

}

Player expCalc(Player account, Mob Karthus)
{
    account.setPlayerExp(account.getPlayerExp() + Karthus.getMobDifficulty() * 10 * (account.getPlayerLvl() + 1));
    std::cout << "[ Player gained: " << Karthus.getMobDifficulty() * 10 * (account.getPlayerLvl() + 1) << " experience! ]" << std::endl;
    std::cout << "[ You have now: " << account.getPlayerExp() << " experience! ]" << std::endl << std::endl;
    system("pause");
    system("cls");
    return lvlUp(account);
}

Player shop(Player account)
{
    int option;
    std::cout << "[ SHOP ]" << std::endl << std::endl;
    std::cout << "[ Your balance: " << account.getPlayerMoney() << "$ ]" << std::endl << std::endl;
    std::cout << "[ Items for sale: ]" << std::endl;
    std::cout << "[ [1] 5 x Heal Potion's ]   - [ 25$ ]" << std::endl;
    std::cout << "[ [2] 5 x Damage Potion's ] - [ 40$ ]" << std::endl << std::endl;
    std::cout << "[ Enter number to buy item (0 to exit)]: ";
    std::cin >> option;
    if(option == 0)
    {
        system("cls");
        return account;
    }
    else
    {
        if(option == 1)
        {
            std::cout << "Buying Heal Potion's" << std::endl;
            system("pause");
            system("cls");
            return account;
        }
        else
        {
            if(option == 2)
            {
                std::cout << "Buying Damage Potion's" << std::endl;
                system("pause");
                system("cls");
                return account;
            }
            else
            {
                std::cout << "Invalid option!" << std::endl;
                system("pause");
                system("cls");
                return account;
            }
        }
    }
}

Player battle(Player accout)
{
    std::string option;
    srand(time(NULL));
    int mGroup = (rand() % 2);
    int mClass = (rand() % 3);
    int diff = (rand() % 20);
    std::string mobs[2][3] = {{"Dragon", "Baby Dragon", "Elder Dragon"}, {"Akali", "Garen", "Wukong"}};
    Mob Karthus(mobs[mGroup][mClass], 25 * diff * (accout.getPlayerLvl() + 1), 5 * diff * (accout.getPlayerLvl() +1), diff);
    do
    {
        std::cout << "[ A for attack ] " << "[ R for retreat ] " << "[ I to use item ] " << "[ S for player's stats] " << "[ C for monster's stats ] " << "[ B to buy items ] " << ": ";
        std::cin >> option;
        Sleep(250);
        system("cls");
        if(option == "R" || option == "r")
        {
            system("cls");
            std::cout << "[ You have successfully escaped! ]" << std::endl;
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
                std::cout << "[ You have attacked " << Karthus.getMobName() << " for " << accout.getDamage() << " damage! ]" << std::endl;
                std::cout << "[ " << Karthus.getMobName() << " attacked you for " << Karthus.getMobDmg() << " damage! ]" << std::endl << std::endl;
                std::cout << "[ You have now " << accout.getPlayerHp() << " health points ]" << std::endl;
                std::cout << "[ " << Karthus.getMobName() << " have now " << Karthus.getMobHp() << " health points ]" << std::endl << std::endl;
                system("pause");
                system("cls");
            }
            else
            {
                if(option == "I" || option == "i") // TODO //
                    {
                        std::string selectPot;
                        system("cls");
                        std::cout << "Items: " << std::endl;
                        std::cout << " [0] " << potion1.getPotionName() << " x " << potion1.getPotionQuantity() << std::endl;
                        std::cout << std::endl << std::endl << " Select Number: ";
                        std::cin >> selectPot;
                        if(selectPot == "0"){
                            if(potion1.getPotionQuantity() > 0)
                                {
                                if(potion1.getPotionType() == "defense"){
                                    if(potion1.getPotionEffect() == "heal"){
                                        accout.setPlayerMaxHp(accout.getPlayerMaxHp() + 100 * potion1.getPotionPower());
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
                            std::cout << " - HP: " << accout.getPlayerHp() << " / " << accout.getPlayerMaxHp() << "  + (" << accout.getPlayerLvlHp() << ")" << std::endl;
                            std::cout << " - DMG: " << accout.getDamage() << "  + (" << accout.getPlayerLvlDmg() << ")" << std::endl;
                            std::cout << " - LVL: " << accout.getPlayerLvl() << std::endl;
                            std::cout << " - EXP: " << accout.getPlayerExp() << " / " << accout.getPlayerExpMax() << std::endl << std::endl;
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
                                std::cout << " - Difficulty: " << Karthus.getMobDifficulty() << std::endl << std::endl;
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                if(option == "B" || option == "b")
                                {
                                    accout = shop(accout);
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
        }


    } while(accout.getPlayerHp() > 0 && Karthus.getMobHp() > 0);
    if(accout.getPlayerHp() <= 0){
        system("cls");
        std::cout << "# GAMEOVER #" << std::endl;
        system("pause");
        system("cls");
        return accout;
    }
    else
    {
        system("cls");
        std::cout << "   [ Victory ]   " << std::endl << std::endl;
        accout = expCalc(accout, Karthus);
        return accout;
    }
}
