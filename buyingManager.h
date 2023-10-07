/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
6/10/2023
 */

#ifndef BUYING_MANAGER_H
#define BUYING_MANAGER_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "flight.h"

class BuyingManager {
private:
	std::map<std::string,Flight*> scheduledFlights;
public:
	BuyingManager();

	bool scheduleFlight( const std::string &, Passenger * );
	std::vector<std::string> filterAndPrintFlight( const std::string &, const std::string &, const std::string & );

	void addFlight( Flight * );

	void info();
};

#endif //BUYING_MANAGER_H