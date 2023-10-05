#include "aircraft.h"

Aircraft::Aircraft(const string& N_number,const string& brand,const string& model, const string& yearProduction, const string& status, int abilityPass, int speedMax, int autonomy) : N_number(N_number), brand(brand), model(model),yearProduction(yearProduction), status(status), abilityPass(abilityPass), speedMax(speedMax), autonomy(autonomy){}

string Aircraft::getN_number(){
    return N_number;
}
string Aircraft::getBrand(){
    return brand;
}

string Aircraft::getModel(){
    return model;
}

string Aircraft::getYearProduction(){
    return yearProduction;
}

string Aircraft::getStatus(){
    return status;
}

int Aircraft::getAbilityPass(){
    return abilityPass;
}

int Aircraft::getSpeedMax(){
    return speedMax;
}

int Aircraft::getAutonomy(){
    return autonomy;
}

void Aircraft::setBrand(string& brand){
    this->brand = brand;
}

void Aircraft::setModel(string& model){
    this->model = model;
}

void Aircraft::setYearProduction(string& year){
    this->yearProduction = year; 
}

void Aircraft::setStatus(string& status){
    this->status = status;
}

void Aircraft::setAbilityPass(int AbilityPass){
    this->abilityPass = abilityPass;

}

void Aircraft::setSpeedMax(int speedMax){
    this->speedMax = speedMax;
}
void Aircraft::setAutonomy(int autonomy){
    this->autonomy = autonomy;
}

void Aircraft::printInfo() {
    cout << "N Number: " << getN_number() << endl;
    cout << "Brand: " << getBrand() << endl;
    cout << "Model: " << getModel() << endl;
    cout << "Year of Production: " << getYearProduction() << endl;
    cout << "Status: " << getStatus() << endl;
    cout << "Ability to Passengers: " << getAbilityPass() << endl;
    cout << "Maximum Speed: " << getSpeedMax() << endl;
    cout << "Autonomy: " << getAutonomy() << endl;
}
