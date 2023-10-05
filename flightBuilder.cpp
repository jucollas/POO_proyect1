/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
4/10/2023
 */

#include "flightBuilder.h"

FlightBuilder::FlightBuilder(){
	this->aircraft = NULL;
	this->flightCode = "0000";
	this->date = "today";
	this->origin = "aeropuertoAragon";
	this->destiny = "aeropuertoAragon";
	this->latitude = 0;
	this->longitude = 0;
	this->height = 0;
}

void FlightBuilder::addPassenger( Passenger *p ){
	this->passengers.push_back( p );
}
void FlightBuilder::addCrewMember( Crew *c ){
	this->crewMates.push_back( c );
}

void FlightBuilder::setAircraft( Aircraft *aircraft ){
	this->aircraft = aircraft;
}
void FlightBuilder::setFlightCode( const std::string &flightCode ){
	this->flightCode = flightCode;
}
void FlightBuilder::setDate( const std::string &date ){
	this->date = date;
}
void FlightBuilder::setOrigin( const std::string &origin ){
	this->origin = origin;
}
void FlightBuilder::setDestiny( const std::string &destiny ){
	this->destiny = destiny;
}
void FlightBuilder::setLatitude( double latitude ){
	this->latitude = latitude;
}

void FlightBuilder::setLongitude( double longitude ){
	this->longitude = longitude;
}

void FlightBuilder::setHeight( int height ){
	this->height = height;
}

Flight * FlightBuilder::getResult(){
	Flight *res = new Flight( this->aircraft, ControlTower::getInstance(), this->passengers, this->crewMates, this->flightCode, this->date, this->origin, this->destiny, this->latitude, this->longitude, this->height );
	return res;
}