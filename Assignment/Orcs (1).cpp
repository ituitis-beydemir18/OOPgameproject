#include <iostream>
#include <string>
#include "Orcs.h"

using namespace std;

Orcs::Orcs(string name,int numOfUnits,int ap,int hp,int regenNum)
    :Faction(name,numOfUnits,ap,hp,regenNum){
    isAlive=true;
    totalhp=numOfUnits*healthPoint;
}

void Orcs::PerformAttack(){ 
    int attackToElve=numOfUnits*0.7;
    int attackToDwarve=numOfUnits-attackToElve;
    if(firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack("Orcs",numOfUnits*attackPoint);
    }
    else if(!firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        secondEnemy->ReceiveAttack("Orcs",numOfUnits*attackPoint);
    }
    else if(firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        if(firstEnemy->getName()=="Elves"){
            firstEnemy->ReceiveAttack("Orcs",attackPoint*attackToElve);
            secondEnemy->ReceiveAttack("Orcs",attackPoint*attackToDwarve);
        }
        else if(secondEnemy->getName()=="Elves"){
            firstEnemy->ReceiveAttack("Orcs",attackPoint*attackToDwarve);
            secondEnemy->ReceiveAttack("Orcs",attackPoint*attackToElve);
        }
    }  
}

void Orcs::ReceiveAttack(string name,int attackingPoints){
    if(name=="Elves"){
        attackPoint=attackPoint*0.75;
        numOfUnits=numOfUnits-(attackPoint/healthPoint);        
    }
    if(name=="Dwarves"){
        attackPoint=attackPoint*0.8;
        numOfUnits=numOfUnits-(attackPoint/healthPoint);        
    }
}

int Orcs::PurchaseWeapons(int weaponPoint){
    attackPoint=attackPoint+(weaponPoint*2);
    return weaponPoint*20;
}

int Orcs::PurchaseArmors(int armorPoint){
    healthPoint=healthPoint+(armorPoint*3);
    return armorPoint;
}

void Orcs::Print(){
    Faction::Print();
} 

