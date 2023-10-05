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

/*class HelicopterFactory : public AircraftFactory {
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
};*/

/*class AvionFactory : public AeronaveFactory {
public:
    Aeronave* crearAeronave() override {
        return new Avion();
    }
};

class JetFactory : public AeronaveFactory {
public:
    Aeronave* crearAeronave() override {
        return new Jet();
    }
};

int main() {
    // Aquí, puedes obtener la elección del usuario desde la entrada de la terminal.
    // Por simplicidad, usaremos un valor constante para demostrar la creación de aeronaves.

    AeronaveFactory* factory = nullptr;

    // Supongamos que el usuario eligió crear un Avión.
    factory = new AvionFactory();

    Aeronave* aeronave = factory->crearAeronave();
    aeronave->despegar();
    aeronave->aterrizar();

    delete aeronave;
    delete factory;

    return 0;
}*/




#endif