/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
4/10/2023
 */

#ifndef FLIGHT_BUILDER_H
#define FLIGHT_BUILDER_H

#include "flight.h"
#include "passenger.h"
#include "crew.h"
#include "controlTower.h"

#include <list>
#include <string>

class FlightBuilder {
private:
	std::list<Passenger*> passengers;
	std::list<Crew*> crewMates;
	Aircraft *aircraft;
	std::string flightCode, date, origin, destiny;
	double latitude, longitude;
	int height;
public:
	FlightBuilder();

	void addPassenger( Passenger * );
	void addCrewMember( Crew * );

	void setAircraft( Aircraft * );
	void setFlightCode( const std::string & );
	void setDate( const std::string & );
	void setOrigin( const std::string & );
	void setDestiny( const std::string & );
	void setLatitude( double );
	void setLongitude( double );
	void setHeight( int );

	Flight * getResult();
};

#endif //FLIGHT_BUILDER_H