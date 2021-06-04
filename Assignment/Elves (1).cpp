#include <iostream>
#include <string>
#include "Elves.h"

using namespace std;

Elves::Elves(string name,int numOfUnits,int ap,int hp,int regenNum)
    :Faction(name,numOfUnits,ap,hp,regenNum){
    isAlive=true;
    totalhp=numOfUnits*healthPoint;
}

void Elves::PerformAttack(){
    int attacktoOrcs=numOfUnits*0.6;
    int attackToDwarves=numOfUnits-attacktoOrcs;
    if(firstEnemy->IsAlive() && firstEnemy->getName()=="Dwarves" && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack("Elves",attackPoint*numOfUnits);
    }
    else if(!firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        secondEnemy->ReceiveAttack("Elves",attackPoint*numOfUnits);
    }
    else if(firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        if(firstEnemy->getName()=="Orcs"){
            firstEnemy->ReceiveAttack("Elves",attackPoint*attacktoOrcs);
            secondEnemy->ReceiveAttack("Elves",attackPoint*attackToDwarves*1.5);
        }
        else if(secondEnemy->getName()=="Orcs"){
            firstEnemy->ReceiveAttack("Elves",attackPoint*attackToDwarves*1.5);
            secondEnemy->ReceiveAttack("Elves",attackPoint*attacktoOrcs);
        }
    }  
}

void Elves::ReceiveAttack(string name,int attackingPoints){
    if(name=="Orcs"){
        attackPoint=attackPoint*1.25;
        numOfUnits=numOfUnits-(attackPoint/healthPoint);        
    }
    if(name=="Dwarves"){
        attackPoint=attackPoint*0.75;
        numOfUnits=numOfUnits-(attackPoint/healthPoint);        
    }
}

int Elves::PurchaseWeapons(int weaponPoint){ 
    attackPoint=attackPoint+(weaponPoint*2);
    return 15*weaponPoint;
}


int Elves::PurchaseArmors(int armorPoint){
    healthPoint=healthPoint+(armorPoint*4);
    return 5*armorPoint;
}

void Elves::Print(){
    cout<<"You cannot reach our elegance"<<endl;
    Faction::Print();
}

