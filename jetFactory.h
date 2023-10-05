#ifndef FACTORY_JET_H
#define FACTORY_JET_H

#include "aircraftFactory.h"
#include "jet.h"

class JetFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override {
        string cedula, name, surname, birthDate, genre, address, phoneNumber, email, aux;
        int n;

        cout << "----- JET -----" << endl;
        Aircraft* aircraft = AircraftFactory::crearAeronave();

        cout << "| Ingrese informacion de Dueño | " << endl;
        string cedula, name, surname, birthDate, genre, address, phoneNumber, email;
        cout << "Ingrese la cédula: ";
        cin >> cedula;
        cout << "Ingrese el nombre: ";
        cin >> name;
        cout << "Ingrese el apellido: ";
        cin >> surname;
        cout << "Ingrese la fecha de nacimiento: ";
        cin >> birthDate;
        cout << "Ingrese el género: ";
        cin >> genre;
        cout << "Ingrese la dirección: ";
        cin >> address;
        cout << "Ingrese el número de teléfono: ";
        cin >> phoneNumber;
        cout << "Ingrese el correo electrónico: ";
        cin >> email;

        Person* owner = new Person(cedula, name, surname, birthDate, genre, address, phoneNumber, email);

        Jet* jet = new Jet(aircraft, owner);

        cout << "| Ingrese informacion de Servicios | " << endl;
        cout << "Ingrese los servicios prestados (separados por espacio o por enter, se detiene con el caracter '#') : " << endl;
        cin.ignore();
        while(cin >> aux && aux != "#"){
            jet->addServices(aux);
        }

        cout << "| Ingrese informacion de destinos frecuentes | " << endl;
        cout << "Ingrese los destinos frecuentes (separados por espacio o por enter, se detiene con el caracter '#') : " << endl;
        while(cin >> aux && aux != "#"){
            jet->addDestination(aux);
        }
        
        return jet;
    }
};

#endif