#include <iostream>
#include <string>
#include "Merchant.h"

using namespace std;

Merchant::Merchant(int startingWeaponPoint,int startingArmorPoint){
    this->startingWeaponPoint=startingWeaponPoint;
    this->startingArmorPoint=startingArmorPoint;
    revenue=0;
    weaponPoint=startingWeaponPoint;
    armorPoint=startingArmorPoint;
}

void Merchant::AssignFactions(Faction* firstFaction,Faction* secondFaction,Faction* thirdFaction){
    this->firstFaction=firstFaction;
    this->secondFaction=secondFaction;
    this->thirdFaction=thirdFaction;
}

bool Merchant::SellWeapons(string name,int weaponPoint){
    if(firstFaction->getName()==name && weaponPoint<=this->weaponPoint){
        if(firstFaction->IsAlive()){
            revenue=revenue+firstFaction->PurchaseWeapons(weaponPoint);
            this->weaponPoint-=weaponPoint;
            cout<<"Weapons sold!"<<endl;
            return true;
        }else{
            cout<<"The faction you want to sell weapons is dead!"<<endl;
            return false;
        }
    }
    else if(firstFaction->getName()==name && weaponPoint>this->weaponPoint){
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        return false;
    }

    if(secondFaction->getName()==name && weaponPoint<=this->weaponPoint){
        if(secondFaction->IsAlive()){
            revenue=revenue+secondFaction->PurchaseWeapons(weaponPoint);
            this->weaponPoint-=weaponPoint;
            cout<<"Weapons sold!"<<endl;
            return true;
        }else{
            cout<<"The faction you want to sell weapons is dead!"<<endl;
            return false;
        }
    }
    else if(secondFaction->getName()==name && weaponPoint>this->weaponPoint){
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        return false;
    }

    if(thirdFaction->getName()==name && weaponPoint<=this->weaponPoint){
        if(thirdFaction->IsAlive()){
            revenue=revenue+thirdFaction->PurchaseWeapons(weaponPoint);
            this->weaponPoint-=weaponPoint;
            cout<<"Weapons sold!"<<endl;
            return true;
        }else{
            cout<<"The faction you want to sell weapons is dead!"<<endl;
            return false;
        }
    }
    else if(thirdFaction->getName()==name && weaponPoint>this->weaponPoint){
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        return false;
    }
    else{
        return false;
    }
}

bool Merchant::SellArmors(string name,int armorPoint){
    if(firstFaction->getName()==name && armorPoint<=this->armorPoint){
        if(firstFaction->IsAlive()){
            revenue=revenue+firstFaction->PurchaseArmors(armorPoint);
            this->armorPoint-=armorPoint;
            cout<<"Armors sold!"<<endl;
            return true;
        }else{
            cout<<"The faction you want to sell armors is dead!"<<endl;
            return false;
        }
    }
    else if(firstFaction->getName()==name && armorPoint>this->armorPoint){
        cout<<"You try to sell more armors than you have in possession."<<endl;
        return false;
    }

    if(secondFaction->getName()==name && armorPoint<=this->armorPoint){
        if(secondFaction->IsAlive()){
            revenue=revenue+secondFaction->PurchaseArmors(armorPoint);
            this->armorPoint-=armorPoint;
            cout<<"Armors sold!"<<endl;
            return true;
        }else{
            cout<<"The faction you want to sell armors is dead!"<<endl;
            return false;
        }
    }
    else if(secondFaction->getName()==name && armorPoint>this->armorPoint){
        cout<<"You try to sell more armors than you have in possession."<<endl;
        return false;
    }
    
    if(thirdFaction->getName()==name && armorPoint<=this->armorPoint){
        if(thirdFaction->IsAlive()){
            revenue=revenue+thirdFaction->PurchaseArmors(armorPoint);
            this->armorPoint-=armorPoint;
            cout<<"Armors sold!"<<endl;
            return true;
        }else{
            cout<<"The faction you want to sell armors is dead!"<<endl;
            return false;
        }
    }
    else if(thirdFaction->getName()==name && armorPoint>this->armorPoint){
        cout<<"You try to sell more armors than you have in possession."<<endl;
        return false;
    }
    else{
        return false;
    }
}

void Merchant::EndTurn(){
    weaponPoint=startingWeaponPoint;
    armorPoint=startingArmorPoint;
}

int Merchant::GetRevenue(){
    return revenue;
}

int Merchant::GetWeaponPoints(){
    return weaponPoint;
}

int Merchant::GetArmorPoints(){
    return armorPoint;
}