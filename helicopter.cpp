#include "helicopter.h"

Helicopter::Helicopter(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy, int nRotors, int liftingCapacity, string& specificUse) : Aircraft(N_number, brand, model, yearProduction, status, abilityPass, speedMax, autonomy), nRotors(nRotors), liftingCapacity(liftingCapacity), specificUse(specificUse) {}

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