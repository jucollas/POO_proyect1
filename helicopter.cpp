#include "helicopter.h"

Helicopter::Helicopter(Aircraft* aircraft, int nRotors, int liftingCapacity, string& specificUse) : Aircraft(*aircraft), nRotors(nRotors), liftingCapacity(liftingCapacity), specificUse(specificUse) {}

int Helicopter::getNRotors(){
    return nRotors;
}

int Helicopter::getLiftingCapacity(){
    return liftingCapacity;
}

string Helicopter::getSpecificUse(){
    return specificUse;
}

void Helicopter::setNRotors(int nRotors){
    this->nRotors = nRotors;
}

void Helicopter::setLiftingCapacity(int liftingCapacity){
    this->liftingCapacity = liftingCapacity;
}

void Helicopter::setSpecificUse(string& specificUse){
    this->specificUse = specificUse;
}

void Helicopter::printInfo(){
    cout << "----- HELICOPTER -----" << endl;
    Aircraft::printInfo();
    cout << "N Rotors: " << getNRotors() << endl;
    cout << "Lifting Capacity: " << getLiftingCapacity() << endl;
    cout << "Specific Use: " << getSpecificUse() << endl;
}