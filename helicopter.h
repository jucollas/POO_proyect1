#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "aircraft.h"

class Helicopter : private Aircraft{
private:
    int nRotors;
    int liftingCapacity;
    string specificUse;
    
public:
    /*builders*/
    Helicopter(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy, int nRotors, int liftingCapacity, string& specificUse);
    ~Helicopter();

    /*gets*/
    int getNRotors();
    int getLiftingCapacity();
    string getSpecificUse();

    /*sets*/
    void setNRotors(int);
    void setLiftingCapacity(int);
    void setSpecificUse(string&);
    /*functions*/
};

#endif