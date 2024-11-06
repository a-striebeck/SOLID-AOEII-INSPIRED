#include <iostream>


class IProductionCost
{
private:
    int Wood;
    int Food;
    int Gold;
    int Stone;

public:
    IProductionCost(int wood, int food, int gold, int stone) 
        : Wood(wood), Food(food), Gold(gold), Stone(stone) {}
    virtual ~IProductionCost() = default;

};

class IUnit : public IProductionCost
{
protected:
    int HP;
    int MeleeArmor;
    int PierceArmor;
    int Damage;

public:
    IUnit(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone) 
        : HP(hp), MeleeArmor(meleeArmor), PierceArmor(pierceArmor), Damage(damage), IProductionCost(wood, food, gold, stone) {}

    virtual ~IUnit() = default;


    virtual int getDamage() const { return Damage; }

    void receiveMeleeAttack(const IUnit& attacker, int extraDamage = 0) {
    int totalDamage = attacker.getDamage() + extraDamage - MeleeArmor;
    if (totalDamage < 0) totalDamage = 1; 
    HP -= totalDamage;
}


    virtual void Attack(IUnit& target) const = 0;
};

/*
    La interfaz iUnit nos permite crear nuevos conjuntos de unidades.

    Diferenciar las unidades en tipos nos permite aplicar modificaciones a todo el conjunto. 

    Por ejemplo, en una version posterior se agregarian las civilizaciones 
    que pueden introducir modificaciones de vida, daño, etc, en las unidades
    

*/
class IMilitaryUnit : public IUnit // idealmente esta unidad deberia heredar tambien de una clase llamada Civilization
{
public:
    IMilitaryUnit(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone) 
        : IUnit(hp, meleeArmor, pierceArmor, damage, wood, food, gold, stone) {}

    virtual ~IMilitaryUnit() = default;
};


class IInfantry : public IMilitaryUnit
{
public:
    IInfantry(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone)
        : IMilitaryUnit(hp, meleeArmor, pierceArmor, damage, wood, food, gold, stone) {}

    virtual ~IInfantry() = default;
};


class SpearMan : public IInfantry
{
public:
    SpearMan(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone) 
        : IInfantry(hp, meleeArmor, pierceArmor, damage, wood, food, gold, stone) {}

    void Attack(IUnit& target) const override {
        std::cout << "Lanzero ataca a una unidad.\n";
        target.receiveMeleeAttack(*this); 
    }
};