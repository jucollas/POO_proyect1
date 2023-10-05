#include "plane.h"

Plane::Plane(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy, int heightMax, int nEngines, string& category) : Aircraft(N_number, brand, model, yearProduction, status, abilityPass, speedMax, autonomy), heightMax(heightMax), nEngines(nEngines), category(category) {}

int Plane::getHeightMax(){
    return heightMax;
}

int Plane::getNEngines(){
    return nEngines;
}

string Plane::getCategory(){
    return category;
};

void Plane::getHeightMax(int heightMax){
    this->heightMax = heightMax;
}
void Plane::getNEngines(int nEngines){
    this->nEngines = nEngines;
}

void Plane::getCategory(string& category){
    this->category = category;
}