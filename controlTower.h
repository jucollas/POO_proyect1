/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#ifndef CONTROL_TOWER_H
#define CONTROL_TOWER_H

class ControlTower;

#include <iostream>
#include <set>
#include "flight.h"
#include "message.h"

class ControlTower {
private:
  static ControlTower* instance;
  std::set<Flight*> flights;
  ControlTower();
public:
  static ControlTower* getInstance();

  void addFlight( Flight * );
  void deleteFlight( Flight * );

  void notifyFlights( Message* );
  
  void showMessage();
  
};

#endif
