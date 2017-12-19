#include "Player.h"
#include <string>

Player::Player(std::string name, int lvl, int exp){Player::setPlayerName(name); Player::setPlayerLvl(lvl); Player::setPlayerExp(exp);}

void Player::setDamage(int damage){Player::dmg = damage;}
void Player::setPlayerHp(int health){Player::hp = health;}
void Player::setPlayerExp(int experience){Player::exp = experience;}
void Player::setPlayerLvl(int level){Player::lvl = level;}
void Player::setPlayerName(std::string pName){Player::name = pName;}

int Player::getDamage(){return Player::dmg;}
int Player::getPlayerHp(){return Player::hp;}
int Player::getPlayerExp(){return Player::exp;}
int Player::getPlayerLvl(){return Player::lvl;}
std::string Player::getPlayerName(){return Player::name;}
