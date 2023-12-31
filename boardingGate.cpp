/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
5/10/2023
*/

#include "boardingGate.h"

BoardingGate::BoardingGate( const std::string &identification, const std::string &location ) : identification(identification), location(location), inGate(NULL), boardingTime("") {};

BoardingGate::~BoardingGate(){
	for ( std::list<Flight*>::iterator it = this->history.begin() ; it != this->history.end() ; ++it ){
		delete *it;
	}
}

std::string BoardingGate::getIdentification(){
	return this->identification;
}
std::string BoardingGate::getLocation(){
	return this->location;
}
std::list<Flight*> BoardingGate::getHistory(){
	return this->history;
}
Flight* BoardingGate::getInGate(){
	return this->inGate;
}

bool BoardingGate::assignFlight( Flight *f ){
	bool res = isAvailable();
	if ( res ){
		this->inGate = f;
		this->boardingTime = f->getDate();
	}
	return res;
}

void BoardingGate::dispatchFlight(){
	if ( this->inGate != NULL ){
		this->history.push_back( this->inGate );
		this->inGate = NULL;
	}
}

bool BoardingGate::isAvailable(){
	return this->inGate == NULL;
}

void BoardingGate::info(){
	std::cout << "Gate: " << this->identification << ", located in " << this->location;
	if ( this->inGate == NULL ){
		std::cout << ". It hosts no flight.";
	} else {
		std::cout << ". It hosts flight with code: " << this->inGate->getFlightCode() << " at " << this->boardingTime;
	}
	std::cout << std::endl;
}
