//Spearman to Halbard
#include "I- Open Close Principle - Militia.cpp"

class Pikemen : public SpearMan {
public:
    Pikemen(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone)
        : SpearMan(hp, meleeArmor, pierceArmor, damage, wood, food, gold, stone) {}

    void Attack(IUnit& target) const override {
        std::cout << "Piquero ataca a una unidad.\n";
        target.receiveMeleeAttack(*this); 
    }
};

class Halbard : public SpearMan {
public:
    Halbard(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone)
        : SpearMan(hp, meleeArmor, pierceArmor, damage, wood, food, gold, stone) {}

    void Attack(IUnit& target) const override {
        std::cout << "Halbardero ataca a una unidad.\n";
        target.receiveMeleeAttack(*this); 
    }
};

class Scout : public IUnit {
public:
    Scout(int hp, int meleeArmor, int pierceArmor, int damage, int wood, int food, int gold, int stone)
        : IUnit(hp, meleeArmor, pierceArmor, damage, wood, food, gold, stone) {}

    void Attack(IUnit& target) const override {
        std::cout << "Explorador ataca a una unidad.\n";
        target.receiveMeleeAttack(*this);
    }
};

int main(int argc, char const *argv[])
{
    SpearMan spear(30, 1, 1, 3, 0, 35, 20, 0);
    Pikemen pikemen(45, 1, 1, 4, 0, 35, 20, 0);
    Halbard halbard(55, 1, 1, 5, 0, 35, 20, 0);
    Scout scout(80, 0, 2, 5, 0, 80, 0, 0);

    
    IUnit* units[] = { &spear, &pikemen, &halbard};

    for (IUnit* unit : units) {
        // Usamos dynamic_cast para verificar si es de tipo SpearMan y aplicamos el bono de +12 de daño contra unidades de caballería
        if (dynamic_cast<SpearMan*>(unit)) {
            scout.receiveMeleeAttack(*unit, 12); // Aplica el bono de +12 de daño
        } else {
            scout.receiveMeleeAttack(*unit); // Ataque normal sin bono
        }
    }

    return 0;
}

