#ifndef JET_H
#define JET_H

#include <list>
#include "aircraft.h"
#include "person.h"

class Jet : public Aircraft{
private:
    Person* owner;
    list<string> services;
    list<string> frequentDestinations;
    
public:
    /*builders*/
    Jet(Aircraft* aircraft, Person* owner);
    //~Jet();

    /*gets*/
    Person* getOwner();
    /*sets*/
    void setOwner(Person*);

    /*functions*/
    void addServices(string&);
    void delServices(int);
    void addDestination(string&);
    void delDestination(int);
    void delAllServices();
    void delAllDestination();

    void printServices();
    void printgetFrequentDestinations();

    void printInfo() override;
};

#endif