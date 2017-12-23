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
Player moneyCalc(Player account, Mob Karthus);
Player upgrade(Player account);

Item potion1("Heal Potion", "defense", "heal", 1, 1);
Item potion2("Damage Potion", "defense", "dmg_boost", 1, 1);
Item makeIt(Item potion1);

std::string locations[5] = {"Castle", "Tower", "Tunnel", "Forest", "Old House"};

int main(){
    std::cout << "Version 2.0" << std::endl; // 23.12.2017
    Sleep(1500);
    srand(time(NULL));
    std::string name;
    int way;
    int startLoc = (rand() % 5);
    std::cout << "Enter name: ";
    std::cin >> name;
    Player account(name, 0, 0, 0, 0, 50); // Name | LvL | Exp | Bonus to HP | Bonus to DMG | Money
    account.setDamage(75);
    account.setPlayerMaxHp(550);
    account.setPlayerHp(account.getPlayerMaxHp());
    account.setPlayerExpMax(100);
    std::cout << "You have spawned in: " << locations[startLoc] << std::endl;
    Sleep(1500);
    system("cls");
    while(true)
    {
        srand(time(NULL));
        int loc = (rand() % 5);
        std::string statLoc = locations[loc];
        std::cout << "Where do you want to go (left - 0, right - 1, forward - 2): ";
        std::cin >> way;
        if(way == 0 || way == 1 || way == 2)
        {
            account.setPlayerLocation(locations[loc]);
            std::cout << std::endl << "You are now in: " << locations[loc] << std::endl;
            Sleep(2500);
            system("cls");
            account = battle(account);
        }
        else
        {
            std::cout << "Wrong way!" << std::endl;
        }
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

Player moneyCalc(Player account, Mob Karthus)
{
    account.setPlayerMoney(account.getPlayerMoney() + Karthus.getMobDifficulty() * 5 *(account.getPlayerLvl() + 1));
    std::cout << "[ Player gained: " << Karthus.getMobDifficulty() * 5 *(account.getPlayerLvl() + 1) << " $ ]" << std::endl;
    std::cout << "[ You have now: " << account.getPlayerMoney() << " $ ]" << std::endl << std::endl;
    system("pause");
    system("cls");
    return account;
}

Player upgrade(Player account)
{
    int option;
    potion1.setPotionCostToUpgrade(250 * potion1.getPotionPower());
    potion2.setPotionCostToUpgrade(275 * potion2.getPotionPower());
    std::cout << "[ UPGRADES ]" << std::endl << std::endl;
    std::cout << "[ Your balance: " << account.getPlayerMoney() << "$ ]" << std::endl << std::endl;
    std::cout << "[ Items to upgrade: ]" << std::endl;
    std::cout << "[1] " << potion1.getPotionName() << " | Power: " << potion1.getPotionPower() << " | Cost: " << potion1.getPotionCostToUpgrade() << "$ " << std::endl;
    std::cout << "[2] " << potion2.getPotionName() << " | Power: " << potion2.getPotionPower() << " | Cost: " << potion2.getPotionCostToUpgrade() << "$ " << std::endl << std::endl;
    std::cout << "[ Select item to upgrade (0 to exit)]: ";
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
            if(account.getPlayerMoney() >= potion1.getPotionCostToUpgrade())
            {
                std::cout << std::endl << "[ Upgrading Max Health Potion's ]" << std::endl;
                potion1.setPotionPower(potion1.getPotionPower() + 1);
                account.setPlayerMoney(account.getPlayerMoney() - potion1.getPotionCostToUpgrade());
                std::cout << "[ Max Health Potion's have now power: " << potion1.getPotionPower() << " ]" << std::endl << std::endl;
                system("pause");
                system("cls");
                return account;
            }
            else
            {
                std::cout << std::endl << "[ Not enough money to upgrade max health potion's! ]" << std::endl << std::endl;
                system("pause");
                system("cls");
                return account;
            }
        }
        else
        {
            if(option == 2)
            {
                if(account.getPlayerMoney() >= potion2.getPotionCostToUpgrade())
                {
                    std::cout << std::endl << "[ Upgrading Damage Potion's ]" << std::endl;
                    potion2.setPotionPower(potion2.getPotionPower() + 1);
                    account.setPlayerMoney(account.getPlayerMoney() - potion2.getPotionCostToUpgrade());
                    std::cout << "[ Damage Potion's have now power: " << potion2.getPotionPower() << " ]" << std::endl << std::endl;
                    system("pause");
                    system("cls");
                    return account;
                }
                else
                {
                    std::cout << std::endl << "[ Not enough money to upgrade damage potion's! ]" << std::endl << std::endl;
                    system("pause");
                    system("cls");
                    return account;
                }
            }
            else
            {
                std::cout << "[ Invalid option! ]" << std::endl;
                system("pause");
                system("cls");
                return account;
            }
        }
    }
}

Player shop(Player account)
{
    int option;
    potion1.setPotionCostToBuy(75);
    potion2.setPotionCostToBuy(115);
    std::cout << "[ SHOP ]" << std::endl << std::endl;
    std::cout << "[ Your balance: " << account.getPlayerMoney() << "$ ]" << std::endl << std::endl;
    std::cout << "[ Items for sale: ]" << std::endl;
    std::cout << "[ [1] 1 x Max Health Potion ]   - [ " << potion1.getPotionCostToBuy() << "$ ]" << std::endl;
    std::cout << "[ [2] 2 x Damage Potion's ] - [ " << potion2.getPotionCostToBuy() << "$ ]" << std::endl << std::endl;
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
            if(account.getPlayerMoney() >= potion1.getPotionCostToBuy())
            {
                std::cout << "[ Buying 1 x Max Health Potion ]" << std::endl;
                potion1.setPotionQuantity(potion1.getPotionQuantity() + 1);
                account.setPlayerMoney(account.getPlayerMoney() - potion1.getPotionCostToBuy());
                system("pause");
                system("cls");
                return account;
            }
            else
            {
                std::cout << std::endl << "[ Not enough money to buy heal potion's! ]" << std::endl << std::endl;
                system("pause");
                system("cls");
                return account;
            }
        }
        else
        {
            if(option == 2)
            {
                if(account.getPlayerMoney() >= potion2.getPotionCostToBuy())
                {
                    std::cout << "[ Buying 2 x Damage Potion's ]" << std::endl;
                    potion2.setPotionQuantity(potion2.getPotionQuantity() + 2);
                    account.setPlayerMoney(account.getPlayerMoney() - potion2.getPotionCostToBuy());
                    system("pause");
                    system("cls");
                    return account;
                }
                else
                {
                    std::cout << std::endl << "[ Not enough money to buy damage potion's! ]" << std::endl << std::endl;
                    system("pause");
                    system("cls");
                    return account;
                }
            }
            else
            {
                std::cout << "[ Invalid option! ]" << std::endl;
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
        std::cout << "[ A for attack ] " << "[ E to escape ] " << "[ I to use item ] " << "[ S for player's stats] " << "[ C for monster's stats ] " << "[ B to buy items ] " << "[ U to upgrade items ]" << " : ";
        std::cin >> option;
        Sleep(250);
        system("cls");
        if(option == "E" || option == "e")
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
                        std::cout << " [0] " << potion1.getPotionName() << " x " << potion1.getPotionQuantity() << " | Power: " << potion1.getPotionPower() << std::endl;
                        std::cout << " [1] " << potion2.getPotionName() << " x " << potion2.getPotionQuantity() << " | Power: " << potion2.getPotionPower() << std::endl;
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
                                    if(selectPot == "1")
                                    {
                                        if(potion2.getPotionQuantity() > 0)
                                        {
                                            if(potion2.getPotionType() == "defense")
                                                {
                                                    if(potion2.getPotionEffect() == "heal")
                                                        {
                                                            accout.setPlayerMaxHp(accout.getPlayerMaxHp() + 100 * potion2.getPotionPower());
                                                            accout.setPlayerHp(accout.getPlayerHp() + 100 * potion2.getPotionPower());
                                                            potion2.setPotionQuantity(potion2.getPotionQuantity() - 1);
                                                            std::cout << " + " << 100 * potion2.getPotionPower() << " HP" << std::endl;
                                                            std::cout << "You are know " << accout.getPlayerHp() << " HP" << std::endl;
                                                        }
                                                    else
                                                        {
                                                            if(potion2.getPotionEffect() == "dmg_boost")
                                                            {
                                                                accout.setDamage(accout.getDamage() + 10 * potion2.getPotionPower());
                                                                potion2.setPotionQuantity(potion2.getPotionQuantity() - 1);
                                                                std::cout << " + " << 10 * potion2.getPotionPower() << " DMG" << std::endl;
                                                                std::cout << "You have know " << accout.getDamage() << " DMG" << std::endl;
                                                            }
                                                            else
                                                            {
                                                                std::cout << "#@# POT ERROR #@#!" << std::endl;
                                                            }
                                                        }
                                                }
                                                else
                                                    {
                                                        if(potion2.getPotionType() == "attack")
                                                            {
                                                                std::cout << "No Potion Programed for attack!" << std::endl;
                                                            }
                                                        else
                                                            {
                                                                std::cout << "#@# POT ERROR #@#" << std::endl;
                                                            }
                                                    }
                                            }
                                            else
                                                {
                                                    std::cout << "Not enough potions!" << std::endl;
                                                }
                                        }
                                    }

                        system("pause");
                        system("cls");
                    }else
                    {
                        if(option == "S" || option == "s")
                        {
                            std::cout << " -- Player's stats -- " << std::endl;
                            std::cout << " - Name: " << accout.getPlayerName() << std::endl;
                            std::cout << " - HP: " << accout.getPlayerHp() << " / " << accout.getPlayerMaxHp() << "  + (" << accout.getPlayerLvlHp() << ")" << std::endl;
                            std::cout << " - DMG: " << accout.getDamage() << "  + (" << accout.getPlayerLvlDmg() << ")" << std::endl;
                            std::cout << " - Money: " << accout.getPlayerMoney() << " $" << std::endl;
                            std::cout << " - LVL: " << accout.getPlayerLvl() << std::endl;
                            std::cout << " - EXP: " << accout.getPlayerExp() << " / " << accout.getPlayerExpMax() << std::endl;
                            std::cout << " - Location: " << accout.getPlayerLocation() << std::endl << std::endl;
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
                                    if(option == "U" || option == "u")
                                    {
                                        accout = upgrade(accout);
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
        accout = moneyCalc(accout, Karthus);
        return accout;
    }
}
