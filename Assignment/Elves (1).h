#ifndef _ELVES_H
#define _ELVES_H

#include <iostream>
#include <string>
#include "Faction.h"

using namespace std;

class Elves: public Faction{
public:
    Elves();
    Elves(string name,int numOfUnits,int ap,int hp,int regenNum);
    void PerformAttack();
    void ReceiveAttack(string name,int attackingPoints);
    int PurchaseWeapons(int weaponPoint);
    int PurchaseArmors(int armorPoint);
    void Print();
    int getAttackPoint();
    void setAttackPoint();
};

#endif