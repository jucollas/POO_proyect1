#include "plane.h"

Plane::Plane(Aircraft* aircraft, int heightMax, int nEngines, string& category) : Aircraft(*aircraft), heightMax(heightMax), nEngines(nEngines), category(category) {}

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

void Plane::printInfo(){
    cout << "----- PLANE -----" << endl;
    Aircraft::printInfo();
    cout << "Height Max: " << getHeightMax() << endl;
    cout << "N Engines: " << getNEngines() << endl;
    cout << "Categoty: " << getCategory() << endl;
}