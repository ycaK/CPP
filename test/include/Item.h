#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item
{
    public:
        Item(std::string ,std::string, std::string, int, int); //name, type, effect, how strong is effect, quantity

        void setPotionName(std::string);
        void setPotionType(std::string);
        void setPotionEffect(std::string);
        void setPotionPower(int);
        void setPotionQuantity(int);
        void setPotionCostToBuy(int);
        void setPotionCostToUpgrade(int);

        std::string getPotionName();
        std::string getPotionType();
        std::string getPotionEffect();
        int getPotionPower();
        int getPotionQuantity();
        int getPotionCostToBuy();
        int getPotionCostToUpgrade();

    private:
        std::string name;
        std::string type;
        std::string effect;
        int power;
        int quantity;
        int costtb;
        int costtu;
};

#endif // ITEM_H
