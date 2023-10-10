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
#include <cstdio>
#include <stdexcept>
#include <limits>

#include "aircraft.h"
#include "plane.h"
#include "jet.h"
#include "helicopter.h"
#include "crew.h"
#include "passenger.h"
#include "planeFactory.h"
#include "helicopterFactory.h"
#include "jetFactory.h"
#include "gateControl.h"
#include "controlTower.h"
#include "buyingManager.h"

/* menus */
void flightMenu();
void menuPrincipal();
void menuCompra();
void menuManager();
void aircraftMenu();
void controlTowerMenu();

/* creators\selectors */
Aircraft* aircraftSelector();
Passenger* createPassenger();
Aircraft * aircraftModule();
void flightCreator();
void crewCreator();
void gateCreator();

/* helpingOperations */
int requestRange( int, bool );
bool requestBool();
void levantamientoDeDatos();
std::string inLineStr();

/* global variables */
std::vector<Aircraft*> warehouse;
std::vector<Crew*> staff;
std::vector<Flight*> flights;
ControlTower *controlTower;
BuyingManager *buyingManager;

int main(){
	levantamientoDeDatos();
	menuPrincipal();
	delete buyingManager;
	delete controlTower;
	return 0;
}

/*
##########################################################################################################
########################################## MENU ##########################################################
##########################################################################################################
*/

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
			std::cout << "se reliza con los filtros: " << date << " - " << origin << " - " << destiny << std::endl;
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
		std::cin >> command;
	}
}

void menuPrincipal(){
	std::cout << "Escriba -1 para salir, 0 para comprar vuelo, 1 para entrar al modo manager." << std::endl;
	int command = requestRange( 2, true );
	while ( command != -1 ){
		system("cls");
		switch( command ) {
		case 0:
			menuCompra();
			break;
		case 1:
			menuManager();
			break;
		}
		system("cls");
		std::cout << "Escriba -1 para salir, 0 para comprar vuelo, 1 para entrar al modo manager." << std::endl;
		command = requestRange( 2, true );
	}
}

void menuManager(){
	Aircraft *aircraft;
	std::cout << "Welcome to the Manager Menu" << std::endl;
	std::cout << "Escriba [-1] para salir, [0] para crear vuelo, [1] para crear aeronaves, [2] para hacer operaciones sobre vuelos, [3] para hacer operaciones sobre aeronaves, [4] para hacer operaciones sobre puertas de abordaje, [5] para crear tripulantes" << std::endl;
	int comand = requestRange( 6, true );
	while ( comand != -1 ){
		system("cls");
		switch ( comand ){
		case 0:
			try{
				flightCreator();
			} catch(...){
				std::cout << "Unable to create the flight." << std::endl;
			}
			break;
		case 1:
			aircraft = aircraftModule();
			warehouse.push_back( aircraft );
			break;
		case 2:
			flightMenu();
			break;
		case 3:
			aircraftMenu();
			break;
		case 4:
			controlTowerMenu();
			break;
		case 5:
			crewCreator();
			break;
		}
		system("cls");
		std::cout << "Welcome to the Manager Menu" << std::endl;
		std::cout << "Escriba [-1] para salir, [0] para crear vuelo, [1] para crear aeronaves, [2] para hacer operaciones sobre vuelos, [3] para hacer operaciones sobre aeronaves, [4] para hacer operaciones sobre puertas de abordaje, [5] para crear tripulantes" << std::endl;
		comand = requestRange( 6, true );
	}
}

void flightMenu(){
	std::cout << "Welcome to the flight Menu" << std::endl;
	std::cout << "Escriba 'exit' para salir, 'info', 'activate' <int>, 'end' <int>, 'land' <int>, 'takeOff' <int>, 'sendPosition' <int>" << std::endl;
	std::string comand;
	std::cin >> comand;
	int index;
	bool question;
	while ( comand != "exit" ){
		if ( comand == "info" ){
			for ( index = 0 ; index < flights.size() ; ++index ){
				std::cout << "[" << index << "] ";
				flights[index]->info();
			}
		} else if ( comand == "activate" ){
			index = requestRange( flights.size(), false );
			question = flights[index]->getOrigin() == "aragon";
			flights[index]->activateFlight( question );
			buyingManager->delFlight( flights[index]->getFlightCode() );
		} else if ( comand == "end" ){
			index = requestRange( flights.size(), false );
			question = flights[index]->endFlight();
			if ( question ){
				if ( flights[index]->isInAir() && flights[index]->getOrigin() != "aragon" ){
					delete flights[index];
				}
				flights.erase( flights.begin()+index );
			}
		} else if ( comand == "land" ){
			index = requestRange( flights.size(), false );
			flights[index]->land();
		} else if ( comand == "takeOff" ){
			index = requestRange( flights.size(), false );
			flights[index]->takeOff();
		} else if ( comand == "sendPosition" ){
			index = requestRange( flights.size(), false );
			flights[index]->sendFlightInformation();
		} else {
			std::cout << "Error: the command \"" << comand << "\" wasn't understood." << std::endl;
		}
		std::cout << "Welcome to the flight Menu" << std::endl;
		std::cout << "Escriba 'exit' para salir, 'info', 'activate' <int>, 'end' <int>, 'land' <int>, 'takeOff' <int>, 'sendPosition' <int>." << std::endl;
		std::cin >> comand;
	}
}

void aircraftMenu(){
	std::string comand;
	std::cout << "Welcome to the aircraft Menu.\n -> type 'exit' to exit, 'manteinance' <int> <bool> to select an Aircraft for manteinance, 'info' to get information on all aircrafts" << std::endl;
	std::cin >> comand;
	int index;
	bool question;
	while ( comand != "exit" ){
		if ( comand == "manteinance" ){
			index = requestRange( warehouse.size(), false );
			question = requestBool();
			if ( question ){
				warehouse[index]->putInManteinance();
			} else {
				warehouse[index]->endManteinance();
			}
		} else if ( comand == "info" ){
			for ( index = 0 ; index < warehouse.size() ; ++index ){
				std::cout << "[" << index << "] ";
				warehouse[index]->printInfo();
			}
		} else {
			std::cout << "Error: the comand \"" << comand << "\" wasn't understood" << std::endl;
		}
		std::cout << "Welcome to the aircraft Menu.\n -> type 'exit' to exit, 'manteinance' <int> <bool> to select an Aircraft for manteinance, 'info' to get information on all aircrafts" << std::endl;
		std::cin >> comand;
	}
}
void controlTowerMenu(){
	std::cout << "type [-1] to exit, [0] to get information on all flights and boarding gates, [1] to create a boarding gate" << std::endl;
	int comand = requestRange( 2, true );
	while ( comand != -1 ){
		switch( comand ){
		case 0:
			controlTower->info();
			break;
		case 1:
			gateCreator();
			break;
		}
		comand = requestRange( 2, true );
	}
}

/*
##########################################################################################################
########################################## creadores/selectores ##########################################
##########################################################################################################
*/

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
	cin.ignore();
	getline( cin, medicalInfo );
	Passenger *res = new Passenger( cedula, name, surname, "?", "?", "?", "?", "?", "?", medicalInfo, 1 );
	return res;
}

Aircraft* aircraftSelector(){
	std::cout << "Index | choose an aircraft with the index:" << std::endl;
	for ( int i = 0 ; i < warehouse.size() ; ++i ){
		std::cout << "[" << i << "] - " << warehouse[i]->getN_number() << " - " << warehouse[i]->getModel() << ". capacity: " << warehouse[i]->getAbilityPass() << ". flights [" << warehouse[i]->getAsociatedFlights() << "/" << MaxFlightsPerAircraft << "]" << std::endl; 
	}
	int index = requestRange( warehouse.size(), true );
	while ( index != -1 && !warehouse[index]->canAssignFlight() ){
		index = requestRange( warehouse.size(), true );
	}
	Aircraft *res = ( index != -1 ) ?  warehouse[index] : NULL;
	return res;
}


void flightCreator(){
	Flight* flight = NULL;
	std::string flightCode, date, origin, destiny;
	std::cout << "Welcome to the flight creator" << std::endl;
    cin.ignore();
	std::cout << "flight code: ";
	std::cin >> flightCode;
	std::cout << "date: ";
	std::cin >> date;
	std::cout << "if origin == 'aragon', then it will be available to the client.\norigin: ";
	std::cin >> origin;
	std::cout << "destiny: ";
	std::cin >> destiny;
	Aircraft *aircraft = aircraftSelector();
	if ( aircraft == NULL  ){
		throw( "There ain't an aircraft assigned\n" );
	}
	std::list<Crew*> crewMates;
	std::cout << "type the indexes of the crew members desired: (-1 to end)" << std::endl;
	for ( int i = 0 ; i < staff.size() ; ++i ){
		std::cout << "[" << i << "]";
		staff[i]->info();
	}
	std::set<int> repeated;
	int index = requestRange( staff.size(), true );
	while ( index != -1 ){
		if ( !repeated.count( index ) ){
			crewMates.push_back( staff[index] );
			repeated.insert( index );
		}
		index = requestRange( staff.size(), true );
	}
	std::cout << "The crew members selected:" << std::endl;
	for ( std::list<Crew*>::iterator it = crewMates.begin() ; it != crewMates.end() ; ++it ){
		(*it)->info();
	}
	flight = new Flight( aircraft, controlTower, crewMates, flightCode, date, origin, destiny, 0, 0, 0 );
	if ( origin == "aragon" ){
		buyingManager->addFlight( flight );
	}
	flights.push_back( flight );
}

Aircraft * aircraftModule(){
    AircraftFactory* factory = NULL;
    Aircraft* aircraft = NULL;
    int option;
    cout << "Bienvenido al modulo de Aeronaves" << endl;
    cout << "que tipo de areonave desea ingresar en el sistema ?" << endl;
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

void crewCreator(){
	std::string cedula, name, surname, birthDate, genre, address, phoneNumber, email, jobPosition;
	int dailyWorkingHours, experience;
	std::cout << "Welcome to the crew creator" << std::endl;
	std::cout << "type your 'cedula': ";
	std::cin >> cedula;
	std::cout << "type your name: ";
	std::cin >> name;
	std::cout << "type your surname: ";
	std::cin >> surname;
	std::cout << "Type your birht date: ";
	std::cin >> birthDate;
	std::cout << "Type your genre: ";
	std::cin >> genre;
	std::cout << "Type your address: ";
	std::cin >> address;
	std::cout << "Type your phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Type your email: ";
	std::cin >> email;
	std::cout << "type your position/job: ";
	std::cin >> jobPosition;
	std::cout << "Type the hours you work daily: ";
	std::cin >> dailyWorkingHours;
	std::cout << "Type your years of experience: ";
	std::cin >> experience;
	Crew *c = new Crew( cedula, name, surname, birthDate, genre, address, phoneNumber, email, jobPosition, dailyWorkingHours, experience );
	staff.push_back( c );
}

void gateCreator(){
	std::cout << "Welcome to the boarding gate creator" << std::endl;
	std::string id, loc;
	std::cout << "Type the identification: ";
	std::cin >> id;
	std::cout << "Type the location: ";
	cin.ignore();
	getline( cin, loc );
	controlTower->addGate( id, loc );
}

/*
##########################################################################################################
########################################## helping operations ############################################
##########################################################################################################
*/

void levantamientoDeDatos(){
	Flight *flight;
	buyingManager = new BuyingManager();
	controlTower = ControlTower::getInstance();
	controlTower->addGate( "01", "La mas cerca a la puerta" );
	controlTower->addGate( "02", "al lado de la '01'" );
	controlTower->addGate( "03", "ni p* idea" );
	controlTower->addGate( "04", "Por donde el de los helados" );

	Aircraft *tmp = new Aircraft( "T-0001", "Avianca", "boeing", "2000", "dormido", 10, 100, 100 );
	tmp = new Plane( tmp, 10000, 2, "Comercial" );
	warehouse.push_back( tmp );

	flight = new Flight( tmp, controlTower, std::list<Crew*>(), "Pred-01", "7/10/2023", "aragon", "medellin", 0,0,0 );
	flights.push_back( flight );
	buyingManager->addFlight( flight );

	flight = new Flight( tmp, controlTower, std::list<Crew*>(), "Pred-02", "15/12/2023", "aragon", "bogota", 0,0,0 );
	flights.push_back( flight );
	buyingManager->addFlight( flight );

	tmp = new Aircraft( "T-0002", "Avianca", "boeing", "2000", "dormido", 2, 100, 100 );
	tmp = new Plane( tmp, 100, 2, "Comercial" );
	warehouse.push_back( tmp );

	tmp = new Aircraft( "T-0003", "Avianca", "boeing", "2000", "dormido", 5, 100, 100 );
	tmp = new Plane( tmp, 500, 2, "Comercial" );
	warehouse.push_back( tmp );

	flight = new Flight( tmp, controlTower, std::list<Crew*>(), "Pred-00", "7/10/2023", "aragon", "bogota", 0,0,0 );
	flights.push_back( flight );
	buyingManager->addFlight( flight );

	staff.push_back( new Crew( "1100", "Pedro", "De la renta", "4/5/1996", "H", "avenida -2", "31034086", "pedrito@inventos.com", "Piloto", 28, 5 ) );
	staff.push_back( new Crew( "1101", "Nidia", "Zapata", "36/9/1956", "M", "avenida -2", "31034086", "nidia@inventos.com", "Azafata", 20, 11 ) );
	staff.push_back( new Crew( "1102", "Jeronimo", "Gutierrez", "9/11/2001", "H", "avenida -2", "31034086", "jeronimo@inventos.com", "Azafato", 2, 15 ) );
	staff.push_back( new Crew( "1103", "Schex", "Zscellin", "9/1/1995", "?", "avenida -2", "31034086", "schex@inventos.com", "Piloto", 0, 20 ) );
	staff.push_back( new Crew( "1104", "Sandra", "Mora", "10/12/1959", "M", "avenida -2", "31034086", "sandra@inventos.com", "Azafata", 8, 10 ) );
	staff.push_back( new Crew( "1105", "Hermione", "Granger", "8/8/1976", "Maga", "avenida -2", "31034086", "hermione@inventos.com", "Mecanica", 6, 3 ) );
	staff.push_back( new Crew( "1106", "Jertrudis", "Alcancia", "17/1/1830", "M", "avenida -2", "31034086", "jertrudis@inventos.com", "Azafata", 7, 6 ) );
	staff.push_back( new Crew( "1107", "Batman", "Murcielago", "27/9/1999", "Batman", "avenida -2", "31034086", "laNoche@inventos.com", "Guardia de seguridad", 2, 1 ) );

}

std::string inLineStr(){
	std::string res;
	char t;
	do {
		t = getc( stdin );
	} while ( t == ' ' );
	while ( t != ' ' && t != '\n' ){
		res.push_back( t );
		t = getc( stdin );		
	}
	return res;
}

bool requestBool(){
	std::cout << "[Y/N]" << std::endl;
	std::string comand;
	do {
		std::cout << "> ";
		std::cin >> comand;
	} while ( comand != "Y" && comand != "N" );
	return comand == "Y";
}

int requestRange( int range, bool negative ){
	if ( range == 0 ){
		return -1;
	}
	int res;
	bool validInput = false;
	do {
		std::cout << "> ";
		try{
			if(scanf ( "%d", &res ) != 1 ){
				throw std::runtime_error("Input is not Integer");
			}
			validInput = true;
		}catch(const std::runtime_error& e){
			std:: cerr << "Error:" << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}	
	} while (!validInput || ( ( !negative || res != -1 ) && res < 0 ) || res >= range  );
	return res;
}
