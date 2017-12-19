#include "Item.h"
#include <iostream>
#include <string>

Item::Item(std::string name, std::string type, std::string effect, int power, int quantity){Item::setPotionName(name); Item::setPotionType(type); Item::setPotionEffect(effect); Item::setPotionPower(power); Item::setPotionQuantity(quantity);}

void Item::setPotionName(std::string potName){Item::name = potName;}
void Item::setPotionType(std::string potType){Item::type = potType;}
void Item::setPotionEffect(std::string potEffect){Item::effect = potEffect;}
void Item::setPotionPower(int potPower){Item::power = potPower;}
void Item::setPotionQuantity(int potQuantity){Item::quantity = potQuantity;}

std::string Item::getPotionName(){return Item::name;}
std::string Item::getPotionType(){return Item::type;}
std::string Item::getPotionEffect(){return Item::effect;}
int Item::getPotionPower(){return Item::power;}
int Item::getPotionQuantity(){return Item::quantity;}
