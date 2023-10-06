/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
4/10/2023
 */

#include "planeFactory.h"

Aircraft* PlaneFactory::crearAeronave() {
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