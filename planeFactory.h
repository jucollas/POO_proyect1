#ifndef FACTORY_PLANE_H
#define FACTORY_PLANE_H

#include "aircraftFactory.h"
#include "plane.h"

class PlaneFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override {
        int heightMax, nEngines;
        string category;

        cout << "----- PLANE -----" << endl;
        Aircraft* aircraft = AircraftFactory::crearAeronave();

        cout << "Ingrese la altura máxima del avión (en pies): ";
        cin >> heightMax;
        cout << "Ingrese el número de motores del avión: ";
        cin >> nEngines;
        cout << "Ingrese la categoría del avión: ";
        cin >> category;

        Plane* plane = new Plane(aircraft, heightMax, nEngines, category);
        
        return plane;
    }
};

#endif