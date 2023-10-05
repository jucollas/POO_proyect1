#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <iostream>

using namespace std;

class Aircraft{
private:
    string N_number;
    string brand;
    string model;
    string yearProduction;
    string status;
    int abilityPass;
    int speedMax;
    int autonomy;
    
public:
    /*builders*/
    Aircraft(const string& N_number, const string& brand, const string& model, const string& yearProduction, const string& status, int abilityPass, int speedMax, int autonomy);
    //~Aircraft();

    /*gets*/
    string getN_number();
    string getBrand();
    string getModel();
    string getYearProduction();
    string getStatus();
    int getAbilityPass();
    int getSpeedMax();
    int getAutonomy();

    /*sets*/
    void setBrand(string&);
    void setModel(string&);
    void setYearProduction(string&);
    void setStatus(string&);
    void setAbilityPass(int);
    void setSpeedMax(int);
    void setAutonomy(int);

    /*functions*/
    virtual void printInfo();
};

#endif