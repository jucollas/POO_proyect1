#include "jet.h"

Jet::Jet(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy) : Aircraft(N_number, brand, model, yearProduction, status, abilityPass, speedMax, autonomy){
    owner = NULL;
}

Person* Jet::getOwner(){
    return owner;
}

void Jet::setOwner(Person* owner){
    this->owner = owner;
}

void Jet::addServices(string& serv){
    services.push_back(serv);
}

void Jet::delServices(int index){
    list<string>::iterator it = services.begin();
    advance(it, index - 1);
    services.erase(it);
}

void Jet::addDestination(string& des){
    frequentDestinations.push_back(des);
}

void Jet::delDestination(int index){
    list<string>::iterator it = frequentDestinations.begin();
    advance(it, index - 1);
    services.erase(it);
}

void Jet::delAllServices(){
    services.clear();
}
void Jet::delAllDestination(){
    frequentDestinations.clear();
}

void Jet::printInfo(){
    list<string>::iterator it;
    cout << "----- JET -----" << endl;
    Aircraft::printInfo();
    cout << "Services:" << endl;
    for(it = services.begin(); it != services.end(); ++it)
        cout << "  - " << *it << endl;
    cout << "Frequent Destinations:" << endl;
    for(it = frequentDestinations.begin(); it != frequentDestinations.end(); ++it)
        cout << "  - " << *it << endl;
}