/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
4/10/2023
 */

#include <iostream>
#include <string>
#include <vector>

#include "flightBuilder.h"
#include "aircraft.h"
#include "crew.h"
#include "passenger.h"
#include "planeFactory.h"
#include "helicopterFactory.h"
#include "jetFactory.h"

Aircraft * aircraftModule();
Flight * crearVuelo();
Aircraft *aircraftCreator();
Passenger *createPassenger();
Crew *createCrewMember();
int requestRange( int, bool );

std::vector<Aircraft*> warehouse;
std::vector<Crew*> staff;
std::vector<Passenger*> regulars;

int main(){
	warehouse.push_back( aircraftModule() );
	crearVuelo();
	return 0;
}

Flight * crearVuelo(){
	FlightBuilder *helper = new FlightBuilder();
	std::cout << "Bienvenido al creador de vuelo. Los siguientes comandos permiten agregar informacion del vuelo:\n";
	std::cout << "'client', 'crew', 'aircraft', 'code', 'date', 'origin', 'destiny', 'latitude', 'longitude' y 'height'.\n";
	std::cout << "Para terminar, escriba 'exit'\n";
	std::string command;
	std::cin >> command;
	while ( command != "exit" ){
		if ( command == "client" ){
			Passenger *pass = createPassenger();
			helper->addPassenger( pass );
		} else if ( command == "crew" ){
			Crew *member = createCrewMember();
			helper->addCrewMember( member );
		} else if ( command == "aircraft" ){
			Aircraft *av = aircraftCreator();
			helper->setAircraft( av );
		} else if ( command == "code" ){
			std::cin >> command;
			helper->setFlightCode( command );
		} else if ( command == "date" ){
			std::cin >> command;
			helper->setDate( command );
		} else if ( command == "origin" ){
			std::cin >> command;
			helper->setOrigin( command );
		} else if ( command == "destiny" ){
			std::cin >> command;
			helper->setDestiny( command );
		} else if ( command == "latitude" ){
			double l;
			std::cin >> l;
			helper->setLatitude( l );
		} else if ( command == "longitude" ){
			double l;
			std::cin >> l;
			helper->setLongitude( l );
		} else if ( command == "height" ){
			int h;
			std::cin >> h;
			helper->setHeight( h );
		} else {
			std::cout << "No se le entendio el comando" << std::endl;
		}
		std::cin >> command;
	}
	Flight *res = helper->getResult();
	delete helper;
	return res;
}

Aircraft *aircraftCreator(){
	std::cout << "Opciones de aeronave.\n";
	for ( int index = 0 ; index < warehouse.size() ; ++index ){
		std::cout << '[' << index << ']' << " ";
		warehouse[index]->printInfo();
		std::cout << std::endl;
	}
	int num = requestRange( warehouse.size(), true );
	Aircraft *res;
	if ( num == -1 ){
		res = new Aircraft( "100", "toyota", "1946", "1948", "dead", 0, 0, 0 );
		warehouse.push_back( res );
	} else {
		res = warehouse[num];
	}
	return res;
}
Passenger *createPassenger(){
	std::cout << "Opciones de pasajero.\n";
	for ( int index = 0 ; index < regulars.size() ; ++index ){
		std::cout << '[' << index << ']' << " ";
		regulars[index]->info();
		std::cout << std::endl;
	}

	int num = requestRange( regulars.size(), true );
	Passenger *res;
	if ( num == -1 ){
		res = new Passenger( "100", "josefo", "brisales", "0/0/2000", "undefined", "?", "?", "?", "colombia", "dead", 0 );
		regulars.push_back( res );
	} else {
		res = regulars[num];
	}
	return res;
}
Crew *createCrewMember(){
	std::cout << "Opciones de tripulacion.\n";
	for ( int index = 0 ; index < staff.size() ; ++index ){
		std::cout << '[' << index << ']' << " ";
		staff[index]->info();
		std::cout << std::endl;
	}
	int num = requestRange( staff.size(), true );
	Crew *res;
	if ( num == -1 ){
		res = new Crew( "1001", "Jeronimo", "Gutierrez", "0/0/2000", "undefined", "?", "?", "?", "alcalde", 1, 100 );
		staff.push_back( res );
	} else {
		res = staff[num];
	}
	return res;
}
int requestRange( int range, bool negative ){
	if ( range == 0 ){
		return -1;
	}
	int res;
	std:: cout << "Escriba un numero del 0-" << range << "para seleccionar una opcion.";
	if ( negative ){
		std::cout << "Escriba '-1' para no seleccionar ninguna.";
	}
	std::cout << std::endl;
	do {
		std::cout << "> ";
		std::cin >> res;
	} while ( ( ( !negative || res != -1 ) && res < 0 ) || res >= range  );
	return res;
}

Aircraft * aircraftModule(){
    AircraftFactory* factory = NULL;
    Aircraft* aircraft = NULL;
    int option;
    cout << "Bienvenido al modulo de Aeronaves" << endl;
    cout << "que tipo de areo nave desea ingresar en el sistema ?" << endl;
    cout << "1. avion" << endl;
    cout << "2. jet" << endl;
    cout << "3. helicoptero" << endl;
    cin >> option;
    
    if (option == 1){
        factory = new PlaneFactory();
    }else if(option == 2){
        factory = new JetFactory();
    }else if(option == 3){
        factory = new HelicopterFactory();
    }
    aircraft = factory->crearAeronave();
    aircraft->printInfo();
    return aircraft;
}