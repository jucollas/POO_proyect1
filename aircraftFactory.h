#ifndef FACTORY_AIRCRAFT_H
#define FACTORY_AIRCRAFT_H

#include "aircraft.h"

using namespace std;

class AircraftFactory {
public:
    virtual Aircraft* crearAeronave(){
        string n_number, brand, model, yearProduction, status;
        int abilityPass, speedMax, autonomy;

        cin.ignore();
        cout << "Ingrese el número de registro: ";
        getline(cin, n_number);

        cout << "Ingrese la marca: ";
        getline(cin, brand);

        cout << "Ingrese el modelo: ";
        getline(cin, model);

        cout << "Ingrese el año de producción: ";
        cin >> yearProduction;

        cout << "Ingrese el estado: ";
        cin >> status;

        cout << "Ingrese la capacidad de pasajeros: ";
        cin >> abilityPass;

        cout << "Ingrese la velocidad máxima (en mph): ";
        cin >> speedMax;

        cout << "Ingrese la autonomía (en millas): ";
        cin >> autonomy;

        // Crear una instancia de Aircraft con la información proporcionada por el usuario
        Aircraft* aircraft = new Aircraft(n_number, brand, model, yearProduction, status, abilityPass, speedMax, autonomy);
        return aircraft;
    }
};

#endif