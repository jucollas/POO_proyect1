#ifndef FACTORY_HELICOPTER_H
#define FACTORY_HELICOPTER_H

#include "aircraftFactory.h"
#include "helicopter.h"

class HelicopterFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override {
        int nRotors, liftingCapacity;
        string specificUse;

        cout << "----- HELICOPTER -----" << endl;
        Aircraft* aircraft = AircraftFactory::crearAeronave();

        cout << "Ingrese el número de rotores: ";
        cin >> nRotors;

        cout << "Ingrese la capacidad de elevación (en libras): ";
        cin >> liftingCapacity;

        cout << "Ingrese el uso específico: ";
        cin.ignore(); // Limpiar el buffer del teclado
        getline(cin, specificUse);

        Helicopter* helicopter = new Helicopter(aircraft, nRotors, liftingCapacity, specificUse);
        return helicopter;
    }
};

#endif