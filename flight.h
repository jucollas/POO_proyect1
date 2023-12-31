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
#include <iomanip> // Para establecer el número de decimales
#include <cstdlib> // Para funciones de generación de números aleatorios
#include <ctime>

class Flight {
private:
  Aircraft *aircraft;
  ControlTower *control;
  std::list<Passenger*> passengers;
  std::list<Crew*> crewMates;
  std::string flightCode, date, origin, destiny;
  int height;
  double latitude, longitude;
  bool activeFlight, alreadyFlew;
  std::string gateId;
public:
  Flight( Aircraft *, ControlTower *, const std::list<Crew*> &, const std::string &, const std::string &, const std::string &, const std::string &, double, double, int );

  void sendFlightInformation();
  void receiveMessage( Message * );

  void land();
  void takeOff();
  bool activateFlight( bool );
  bool endFlight();
  
  bool isActive();
  bool isInAir();
  bool hasAvailableSeats();
  bool hasItAlreadyFlew();

  bool bookSeat( Passenger * );
  
  std::string getGateId();
  std::string getFlightCode();
  std::string getDate();
  std::string getOrigin();
  std::string getDestiny();
  Aircraft *getAircraft();
  std::list<Passenger*> getPassengers();
  std::list<Crew*> getCrewMates();
  int getBookedSeats();
  
  bool operator < ( const Flight & ) const;

  void info();
  void setCoordinates(int, double, double);
  void infoCord();
};

#endif //FLIGHT_H
