#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <iostream>

using namespace std;

#define MaxFlightsPerAircraft 3

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
    int asociatedFlights;
    bool inFlight;
    
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
    int getAsociatedFlights();
    bool isInflight();

    /*sets*/
    void setBrand(string&);
    void setModel(string&);
    void setYearProduction(string&);
    void setStatus(string&);
    void setAbilityPass(int);
    void setSpeedMax(int);
    void setAutonomy(int);

    /*functions*/

    bool canAssignFlight();
    bool assignFlight();
    void activateFlight();
    void deactivateFlight();
    virtual void printInfo();
};

#endif