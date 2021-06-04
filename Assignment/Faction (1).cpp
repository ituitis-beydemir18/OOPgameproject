#include <iostream>
#include <string>
#include "Faction.h"

Faction::Faction(string name,int numOfUnits,int ap,int hp,int regenNum){
    this->name=name;
    this->numOfUnits=numOfUnits;
    attackPoint=ap;
    healthPoint=hp;
    unitRegen=regenNum;
    isAlive=true;
    totalhp=numOfUnits*healthPoint;
}

void Faction::AssignEnemies(Faction* enemy1,Faction* enemy2){
    firstEnemy=enemy1;
    secondEnemy=enemy2;
}

void Faction::EndTurn(){
    if(numOfUnits<0){
        numOfUnits=0;
    }
    if(numOfUnits==0){
        isAlive=false;
    }
    numOfUnits=numOfUnits+unitRegen;
}

bool Faction::IsAlive(){
    if(isAlive) return true;
    else return false; 
}

void Faction::Print(){
    cout<<"Faction Name:         "<<name<<endl;
    if(isAlive){
        cout<<"Status:               Alive"<<endl;
    }else{
        cout<<"Status:               Defeated"<<endl;
    }
    cout<<"Number of Units:      "<<numOfUnits<<endl;
    cout<<"Attack Point:         "<<attackPoint<<endl;
    cout<<"Health Point:         "<<healthPoint<<endl;
    cout<<"Unit Regen Number:    "<<unitRegen<<endl;
    cout<<"Total Faction Health: "<<totalhp<<endl;
}



