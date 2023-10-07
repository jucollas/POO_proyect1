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

#include "aircraft.h"
#include "crew.h"
#include "passenger.h"
#include "planeFactory.h"
#include "helicopterFactory.h"
#include "jetFactory.h"
#include "gateControl.h"
#include "controlTower.h"
#include "buyingManager.h"

Aircraft * aircraftModule();
int requestRange( int, bool );
void levantamientoDeDatos();
void menuPrincipal();
void menuCompra();
void menuManager();
Passenger* createPassenger();
std::string inLineStr();

std::vector<Aircraft*> warehouse;
std::vector<Crew*> staff;
ControlTower *controlTower;
BuyingManager *buyingManager;

int main(){
	//warehouse.push_back( aircraftModule() );
	levantamientoDeDatos();
	menuPrincipal();
	return 0;
}

void menuCompra(){
	Passenger *client = createPassenger();

	std::cout << "Welcome to the flight buyer interface" << std::endl;
	std::cout << "write 'exit' to exit this interface" << std::endl;
	std::cout << "write 'book' <int> to book the corresponding flight." << std::endl;
	std::cout << "write 'info' to see a list of all available fligts." << std::endl;
	std::cout << "'date' <string> to filter through a date in the next 'info'" << std::endl;
	std::cout << "'origin' <string> to filter through a origin in the next 'info'" << std::endl;
	std::cout << "'destiny' <string> to filter through a destiny in the next 'info'" << std::endl;
	std::string command, date, origin, destiny;
	std::vector<std::string> tmp;
	int index;
	std::cin >> command;
	while ( command != "exit" ){
		if ( command == "book" ){
			index = requestRange( tmp.size(), true );
			if ( index != -1 ){
				bool succesfull = buyingManager->scheduleFlight( tmp[index], client );
				if ( succesfull ){
					std::cout << "flight booked succesfully." << std::endl;
				}
			}
		} else if ( command == "info" ){
			tmp = buyingManager->filterAndPrintFlight( date, origin, destiny );
			date = std::string();
			origin = std::string();
			destiny = std::string();
		} else if ( command == "date" ){
			date = inLineStr();
		} else if ( command == "origin" ){
			origin = inLineStr();
		} else if ( command == "destiny" ){
			destiny = inLineStr();
		} else {
			std::cout << "The command \"" << command << "\" wasn't understood." << std::endl;
		}
	}
}

void menuPrincipal(){
	std::cout << "Escriba -1 para salir, 0 para comprar vuelo, 1 para entrar al modo manager." << std::endl;
	int command = requestRange( 2, true );
	while ( command != -1 ){
		switch( command ) {
		case 0:
			menuCompra();
			break;
		case 1:
			menuManager();
			break;
		}
		command = requestRange( 2, true );
	}
}

void menuManager(){
	std::cout << "cagaste"<< std::endl;
}

void levantamientoDeDatos(){
	buyingManager = new BuyingManager();
	controlTower = ControlTower::getInstance();
	GateControl *tmp = controlTower->getGateControl();
	tmp->addGate( "01", "primero" );
	tmp->addGate( "02", "segundo" );
	tmp->addGate( "03", "tercero" );
	tmp->addGate( "04", "cuarto" );
	tmp->addGate( "05", "quinto" );

	// añadir a warehouse

	staff.push_back( new Crew( "1100", "Pedro", "De la renta", "4/5/1996", "H", "avenida -2", "31034086", "pedrito@inventos.com", "Piloto", 28, 5 ) );
	staff.push_back( new Crew( "1101", "Nidia", "Zapata", "36/9/1956", "M", "avenida -2", "31034086", "nidia@inventos.com", "Azafata", 20, 11 ) );
	staff.push_back( new Crew( "1102", "Jeronimo", "Gutierrez", "9/11/2001", "H", "avenida -2", "31034086", "jeronimo@inventos.com", "Azafato", 2, 15 ) );
	staff.push_back( new Crew( "1103", "Schex", "Zscellin", "9/1/1995", "?", "avenida -2", "31034086", "schex@inventos.com", "Piloto", 0, 20 ) );
	staff.push_back( new Crew( "1104", "Sandra", "Mora", "10/12/1959", "M", "avenida -2", "31034086", "sandra@inventos.com", "Azafata", 8, 10 ) );
	staff.push_back( new Crew( "1105", "Hermione", "Granger", "8/8/1976", "Maga", "avenida -2", "31034086", "hermione@inventos.com", "Mecanica", 6, 3 ) );
	staff.push_back( new Crew( "1106", "Jertrudis", "Alcancia", "17/1/1830", "M", "avenida -2", "31034086", "jertrudis@inventos.com", "Azafata", 7, 6 ) );
	staff.push_back( new Crew( "1107", "Batman", "Murcielago", "27/9/1999", "Batman", "avenida -2", "31034086", "laNoche@inventos.com", "Guardia de seguridad", 2, 1 ) );


}

Passenger* createPassenger(){
	std::string cedula, name, surname,medicalInfo;
	std::cout << "Welcome to the passenger account creator." << std::endl << std::endl;
    cin.ignore();
	std::cout << "Name: ";
	getline( cin, name );
	std::cout << "Surname: ";
	getline( cin, surname );
	std::cout << "Cedula: ";
	std::cin >> cedula;
	std::cout << "Medical information: ";
	getline( cin, medicalInfo );
	Passenger *res = new Passenger( cedula, name, surname, "?", "?", "?", "?", "?", "?", medicalInfo, 1 );
	return res;
}

int requestRange( int range, bool negative ){
	if ( range == 0 ){
		return -1;
	}
	int res;
	/*std:: cout << "Escriba un numero del 0-" << range << "para seleccionar una opcion.";
	if ( negative ){
		std::cout << "Escriba '-1' para no seleccionar ninguna.";
	}
	std::cout << std::endl;*/
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

std::string inLineStr(){
	std::string res;
	char t;
	do {
		std::cin >> t;
	} while ( t == ' ' );
	while ( t != ' ' && t != '\n' && std::cin ){
		res.push_back( t );
		std::cin >> t;
	}
	return res;
}
