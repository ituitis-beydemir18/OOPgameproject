#ifndef _ORCS_H
#define _ORCS_H

#include <iostream>
#include <string>
#include "Faction.h"

using namespace std;

class Orcs: public Faction{
public:
    Orcs();
    Orcs(string name,int numOfUnits,int ap,int hp,int regenNum);
    void PerformAttack();
    void ReceiveAttack(string name,int attackingPoints);
    int PurchaseWeapons(int weaponPoint);
    int PurchaseArmors(int armorPoint);
    void Print();
    int getAttackPoint();
    void setAttackPoint(); 
};

#endif 