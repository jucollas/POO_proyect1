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

        cout << "Altura maxima (en pies): ";
        cin >> heightMax;
        cout << "Numero de motores: ";
        cin >> nEngines;
        cout << "Categoria: ";
        cin >> category;

        Plane* plane = new Plane(aircraft, heightMax, nEngines, category);
        
        return plane;
    }
};

#endif