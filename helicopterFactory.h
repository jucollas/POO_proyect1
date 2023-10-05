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

        cout << "Numero de rotores: ";
        cin >> nRotors;

        cout << "Capacidad de elevacion (en libras): ";
        cin >> liftingCapacity;

        cout << "Uso especifico: ";
        cin.ignore(); // Limpiar el buffer del teclado
        getline(cin, specificUse);

        Helicopter* helicopter = new Helicopter(aircraft, nRotors, liftingCapacity, specificUse);
        return helicopter;
    }
};

#endif