#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>

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
    Aircraft(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy);
    ~Aircraft();

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
};

#endif