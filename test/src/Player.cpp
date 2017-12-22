#include "Player.h"
#include <string>

Player::Player(std::string name, int lvl, int exp, int lvHp, int lvDmg, int monP){Player::setPlayerName(name); Player::setPlayerLvl(lvl); Player::setPlayerExp(exp); Player::setPlayerLvlHp(lvHp); Player::setPlayerLvlDmg(lvDmg); Player::setPlayerMoney(monP);}

void Player::setDamage(int damage){Player::dmg = damage;}
void Player::setPlayerHp(int health){Player::hp = health;}
void Player::setPlayerExp(int experience){Player::exp = experience;}
void Player::setPlayerLvl(int level){Player::lvl = level;}
void Player::setPlayerName(std::string pName){Player::name = pName;}
void Player::setPlayerExpMax(int lvlMax){Player::expToLvlUp = lvlMax;}
void Player::setPlayerLvlHp(int lvlHp){Player::lvlHp = lvlHp;}
void Player::setPlayerLvlDmg(int lvlDmg){Player::lvlDmg = lvlDmg;}
void Player::setPlayerMaxHp(int maxHp){Player::maxHp = maxHp;}
void Player::setPlayerMoney(int monP){Player::money = monP;}

int Player::getDamage(){return Player::dmg;}
int Player::getPlayerHp(){return Player::hp;}
int Player::getPlayerExp(){return Player::exp;}
int Player::getPlayerLvl(){return Player::lvl;}
int Player::getPlayerExpMax(){return Player::expToLvlUp;}
int Player::getPlayerLvlHp(){return Player::lvlHp;}
int Player::getPlayerLvlDmg(){return Player::lvlDmg;}
int Player::getPlayerMaxHp(){return Player::maxHp;}
int Player::getPlayerMoney(){return Player::money;}
std::string Player::getPlayerName(){return Player::name;}
