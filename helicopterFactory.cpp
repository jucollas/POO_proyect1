/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
5/10/2023
 */

#include "helicopterFactory.h"

Aircraft* HelicopterFactory::crearAeronave() {
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