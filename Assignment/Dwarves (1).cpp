#include <iostream>
#include <string>
#include "Dwarves.h"

using namespace std;

Dwarves::Dwarves(string name,int numOfUnits,int ap,int hp,int regenNum)
    :Faction(name, numOfUnits, ap, hp, regenNum){
        isAlive=true;
        totalhp=numOfUnits*healthPoint;
}

void Dwarves::PerformAttack(){
    int attackToOrcs=numOfUnits*0.5;
    int attackToElves=numOfUnits-attackToOrcs;
    if(firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack("Dwarves",attackPoint*numOfUnits);
    }
    else if(!firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        secondEnemy->ReceiveAttack("Dwarves",attackPoint*numOfUnits);
    }
    else if(firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        if(firstEnemy->getName()=="Elves"){
            firstEnemy->ReceiveAttack("Dwarves",attackPoint*attackToElves);
            secondEnemy->ReceiveAttack("Dwarves",attackPoint*attackToOrcs);
        }
        else if(secondEnemy->getName()=="Elves"){
            firstEnemy->ReceiveAttack("Dwarves",attackPoint*attackToOrcs);
            secondEnemy->ReceiveAttack("Dwarves",attackPoint*attackToElves);
        }
    }  
}

void Dwarves::ReceiveAttack(string name,int attackingPoint){
    numOfUnits=numOfUnits-(attackPoint/healthPoint); 
}

int Dwarves::PurchaseWeapons(int weaponPoint){
    attackPoint=attackPoint+weaponPoint;
    return 10*weaponPoint;
}


int Dwarves::PurchaseArmors(int armorPoint){
    healthPoint=healthPoint+(armorPoint*2);
    return 3*armorPoint;
}

void Dwarves::Print(){
    cout<<"Taste the power of our axes!"<<endl;
    Faction::Print();
}