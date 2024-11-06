//Ejemplo Cuarteles Age of Empires II
#include "I- Open Close Principle - Militia.cpp"
class IBuilding : public IProductionCost
{
private:
    int HP;
    int MeleeArmor;
    int PierceArmor;
public:
    IBuilding(int hp, int meleeArmor, int pierceArmor, int wood, int food, int gold, int stone) : HP(hp), MeleeArmor(meleeArmor), PierceArmor(pierceArmor), IProductionCost(wood, food, gold, stone){}
    ~IBuilding(){}
};
class IMilitaryBuilding : public IBuilding
{
private:
    
public:
    IMilitaryBuilding(int hp, int meleeArmor, int pierceArmor, int wood, int food, int gold, int stone) : IBuilding (hp, meleeArmor, pierceArmor, wood, food, gold, stone){}
    ~IMilitaryBuilding(){}
};


class Barracks : public IMilitaryBuilding
{
private:
    /* data */
public:
    SpearMan createSpearmanLine(){
        //Creates a Spearman unit
    }

};


