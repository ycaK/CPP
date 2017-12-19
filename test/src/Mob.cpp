#include "Mob.h"
#include <iostream>
#include <string>

Mob::Mob(std::string name, int hp, int dmg){Mob::setMobName(name); Mob::setMobHp(hp); Mob::setMobDmg(dmg);}

void Mob::setMobName(std::string mName){Mob::name = mName;}
void Mob::setMobHp(int health){Mob::hp = health;}
void Mob::setMobDmg(int damage){Mob::dmg = damage;}

std::string Mob::getMobName(){return Mob::name;}
int Mob::getMobHp(){return Mob::hp;}
int Mob::getMobDmg(){return Mob::dmg;}
