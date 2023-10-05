#ifndef PLANE_H
#define PLANE_H

#include "aircraft.h"

class Plane : private Aircraft{
private:
    int heightMax;
    int nEngines;
    string category;
    
public:
    /*builders*/
    Plane(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy, int heightMax, int nEngines, string& category);
    ~Plane();

    /*gets*/
    int getHeightMax();
    int getNEngines();
    string getCategory();

    /*sets*/
    void getHeightMax(int);
    void getNEngines(int);
    void getCategory(string&);

    /*functions*/
};

#endif