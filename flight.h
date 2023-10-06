/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight;

#include <list>
#include <string>
#include <iostream>

#include "message.h"
#include "passenger.h"
#include "crew.h"
#include "controlTower.h"
#include "aircraft.h"

class Flight {
private:
  Aircraft *aircraft;
  ControlTower *control;
  std::list<Passenger*> passengers;
  std::list<Crew*> crewMates;
  std::string flightCode, date, origin, destiny;
  int height;
  double latitude, longitude;
public:
  Flight( Aircraft *, ControlTower *, const std::list<Passenger*> &, std::list<Crew*> &, const std::string &, const std::string &, const std::string &, const std::string &, double, double, int );

  void sendFlightInformation();
  void receiveMessage( Message * );

  std::string getFlightCode();
  std::string getDate();
  std::string getOrigin();
  std::string getDestiny();
  Aircraft *getAircraft();
  std::list<Passenger*> getPassengers();
  std::list<Crew*> getCrewMates();
  
  bool operator < ( const Flight & ) const;

  void info();
};

#endif //FLIGHT_H
