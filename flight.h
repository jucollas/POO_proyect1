/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#ifndef FLIGHT_H
#define FLIGHT_H

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
  std::string codigo;
  // otras maridasasfas
public:
  Flight();

  void sendFlightInformation();
  void receiveMessage( Message * );
  
  bool operator < ( const Flight & ) const;
};

#endif //FLIGHT_H
