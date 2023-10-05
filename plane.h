#ifndef PLANE_H
#define PLANE_H

#include "aircraft.h"

class Plane : public Aircraft{
private:
    int heightMax;
    int nEngines;
    string category;
    
public:
    /*builders*/
    Plane(Aircraft* aircraft, int heightMax, int nEngines, string& category);
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
    void printInfo() override;
};

#endif