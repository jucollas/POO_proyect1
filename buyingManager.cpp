/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
6/10/2023
 */

#include "buyingManager.h"

BuyingManager::BuyingManager(){

}

bool BuyingManager::scheduleFlight( const std::string &flightId, Passenger *passenger ){
	bool res = false;
	std::map<std::string,Flight*>::iterator mapValue = this->scheduledFlights.find( flightId );
	if ( mapValue == this->scheduledFlights.end() ){
		std::cout << "Error: the flight code \"" << flightId << "\" isn't valid." << std::endl;
	} else if ( mapValue->second->hasAvailableSeats() ){
		res = mapValue->second->bookSeat( passenger );
	} else {
		std::cout << "Error: not enough space in the aircraft." << std::endl;
	}
	return res;
}
std::vector<std::string> BuyingManager::filterAndPrintFlight( const std::string &date, const std::string &origin, const std::string &destiny ){
	std::vector<std::string> res;
	for ( std::map<std::string,Flight*>::iterator it = this->scheduledFlights.begin(); it != this->scheduledFlights.end() ; ++it ){
		if ( ( date == std::string() || date == it->second->getDate() ) && ( origin == std::string() || origin == it->second->getOrigin() ) && ( destiny == std::string() || destiny == it->second->getDestiny() ) ){
			std::cout << "[" << res.size() << "] date: " << it->second->getDate() << ", origin: " << it->second->getOrigin() << ", destiny: " << it->second->getDestiny() << ". With [" << it->second->getBookedSeats() << "/" << it->second->getAircraft()->getAbilityPass() << "] available seats." << std::endl;
			res.push_back( it->first );
		}
	}
	return res;
}

void BuyingManager::addFlight( Flight *flight ){
	this->scheduledFlights.insert( std::pair<std::string,Flight*>( flight->getFlightCode(), flight ) );
}

void BuyingManager::info(){
	std::cout << "There are %d scheduled flights." << std::endl;
	for ( std::map<std::string,Flight*>::iterator it = this->scheduledFlights.begin() ; it != this->scheduledFlights.end() ; ++it ){
		it->second->info();
	}
}