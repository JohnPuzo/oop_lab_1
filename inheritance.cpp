#include <string>
#include "inheritance.h"
#include <iostream>

Transformer::Transformer(int energon, int dmg) {
    energonLevel = energon; 
    damage = dmg;
}

void Transformer:: run() {
    if (energonLevel > 0) {
        energonLevel -= 10;
    } else {
        cout << "Недостаточно энергона для бега!" << endl;
    }
}

void Transformer:: attack() {
    if (energonLevel > 0) {
        cout << "Урон: " << damage << endl;
        energonLevel -= 20;
    } else {
        cout << "Недостаточно энергона для атаки!" << endl;
    }
}

void Transformer::recharge() {
        energonLevel += 30;
}
int Transformer::getlevel() const{
    return energonLevel;
};

int Transformer::getDamage() const{
    return damage;
};

FlyingTransformer::FlyingTransformer(int energon, int dmg, int height):Transformer::Transformer(energon, dmg)
{
    flightHeight = height;
};

void FlyingTransformer::fly() {
    if (energonLevel > 0) {
        cout << "Летающий трансформер летит на высоте: " << flightHeight << " метров." << endl;
        energonLevel -= 15;
    } else {
        cout << "Недостаточно энергона для полета!" << endl;
    }
}

int FlyingTransformer::getHeight() const{
    return flightHeight;
};