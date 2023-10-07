/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
5/10/2023
*/

#ifndef BOARDING_GATE_H
#define BOARDING_GATE_H

class BoardingGate;

#include <string>
#include <list>
#include <iostream>
#include "flight.h"

class BoardingGate {
private:
	std::string identification, location;
	Flight *inGate;
	std::list<Flight*> history;
public:
	std::string boardingTime;

	BoardingGate( const std::string &, const std::string & );

	std::string getIdentification();
	std::string getLocation();
	std::list<Flight*> getHistory();
	Flight *getInGate();

	bool assignFlight( Flight * );
	void dispatchFlight();

	bool isAvailable();

	void info();

};

#endif //BOARDING_GATE_H
