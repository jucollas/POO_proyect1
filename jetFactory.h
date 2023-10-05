#ifndef FACTORY_JET_H
#define FACTORY_JET_H

#include "aircraftFactory.h"
#include "jet.h"

using namespace std;

class JetFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override {
        string cedula, name, surname, birthDate, genre, address, phoneNumber, email, aux;

        cout << "----- JET -----" << endl;
        Aircraft* aircraft = AircraftFactory::crearAeronave();

        cout << "| Informacion de Dueno | " << endl;
        cout << "Cedula: ";
        cin >> cedula;
        cout << "Nombre: ";
        cin >> name;
        cout << "Apellido: ";
        cin >> surname;
        cout << "Fecha de nacimiento: ";
        cin >> birthDate;
        cout << "Genero: ";
        cin >> genre;
        cout << "Direccion: ";
        cin >> address;
        cout << "Telefono: ";
        cin >> phoneNumber;
        cout << "Correo electronico: ";
        cin >> email;

        Person* owner = new Person(cedula, name, surname, birthDate, genre, address, phoneNumber, email);

        Jet* jet = new Jet(aircraft, owner);

        cout << "| Informacion de Servicios | " << endl;
        cout << "Ingrese los servicios prestados (separados por espacio o por enter, se detiene con el caracter '#') : " << endl;
        cin.ignore();
        while(cin >> aux && aux != "#"){
            jet->addServices(aux);
        }

        cout << "| Informacion de destinos frecuentes | " << endl;
        cout << "Ingrese los destinos frecuentes (separados por espacio o por enter, se detiene con el caracter '#') : " << endl;
        while(cin >> aux && aux != "#"){
            jet->addDestination(aux);
        }
        
        return jet;
    }
};

#endif