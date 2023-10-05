#include "aircraft.h"

Aircraft::Aircraft(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy) : N_number(N_number), brand(brand), model(model),yearProduction(yearProduction), status(status), abilityPass(abilityPass), speedMax(speedMax), autonomy(autonomy){}

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