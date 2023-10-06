/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
4/10/2023
 */

#include "aircraftFactory.h"


Aircraft* AircraftFactory::crearAeronave() {
    string n_number, brand, model, yearProduction, status;
    int abilityPass, speedMax, autonomy;
    int option;

    cin.ignore();
    cout << " - Por favor ingrese la informacion requerida." << endl;
    cout << "| Informacion General (aeronave) |" << endl;
    cout << "Numero de registro: ";
    getline(cin, n_number);

    cout << "Marca: ";
    getline(cin, brand);

    cout << "Modelo: ";
    getline(cin, model);

    cout << "Ano de produccion: ";
    cin >> yearProduction;

    cout << "Estado ([1] en servicio, [2] mantenimiento): ";
    cin >> option;
    if(option == 1)
        status = "In service";
    else if(option == 2)
        status = "maintenance";
        
    cout << "Capacidad de pasajeros: ";
    cin >> abilityPass;

    cout << "Velocidad maxima (en mph): ";
    cin >> speedMax;

    cout << "Autonomia (en millas): ";
    cin >> autonomy;

    Aircraft* aircraft = new Aircraft(n_number, brand, model, yearProduction, status, abilityPass, speedMax, autonomy);
    return aircraft;
}