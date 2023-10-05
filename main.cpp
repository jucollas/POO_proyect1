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

Flight * crearVuelo();
Aircraft *aircraftCreator();
Passenger *createPassenger();
Crew *createCrewMember();
int requestRange( int, bool );

std::vector<Aircraft*> warehouse;
std::vector<Crew*> staff;
std::vector<Passenger*> regulars;

int main(){
	crearVuelo();
	return 0;
}

Flight * crearVuelo(){
	FlightBuilder *helper = new FlightBuilder();
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
	return helper->getResult();
}

Aircraft *aircraftCreator(){
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
	int res;
	do {
		std::cout << "> ";
		std::cin >> res;
	} while ( ( ( negative && res == -1 ) || res >= 0 ) && res < range  );
	return res;
}
