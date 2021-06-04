#ifndef _FACTION_H
#define _FACTION_H

#include <iostream>
#include <string>

using namespace std;

class Faction{
protected:
    string name;
    Faction* firstEnemy;
    Faction* secondEnemy;
    int numOfUnits;
    int attackPoint;
    int healthPoint;
    int unitRegen;
    int totalhp;
    bool isAlive;
public:
    Faction();
    Faction(string name,int numOfUnits,int ap,int hp,int regenNum);
    void AssignEnemies(Faction* enemy1,Faction* enemy2);
    virtual void PerformAttack()=0;
    virtual void ReceiveAttack(string name,int attackingUnits)=0;
    virtual int PurchaseWeapons(int weaponPoint)=0;
    virtual int PurchaseArmors(int armorPoint)=0;
    virtual void Print();
    void EndTurn();
    bool IsAlive();
    string getName() const {
        return name;
    }
    void setName(string name){
        this->name=name;
    }
};

#endif