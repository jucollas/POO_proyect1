/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "controlTower.h"

ControlTower* ControlTower::instance = NULL;

ControlTower::ControlTower(){
  this->gateControl = new GateControl();
}

ControlTower* ControlTower::getInstance(){
  if ( ControlTower::instance == NULL ){
    ControlTower::instance = new ControlTower();
  }
  return ControlTower::instance;
}

GateControl *ControlTower::getGateControl(){
  return this->gateControl;
}

void ControlTower::addFlight( Flight *f ){
  this->flights.insert( f );
}

void ControlTower::deleteFlight( Flight *f ){
  this->flights.erase( f );
}

void ControlTower::notifyFlights( Message* m ){
  for ( std::set<Flight*>::iterator it = this->flights.begin() ; it != this->flights.end() ; ++it ) {
    (*it)->receiveMessage( m );
  }
}

std::string ControlTower::bookBoardingGate( Flight *f ){
  std::string res;
  res = this->gateControl->bookBoardingGate( f );
  return res;
}

void ControlTower::freeBoardingGate( const std::string &gateId ){
  this->gateControl->freeBoardingGate( gateId );
}

void ControlTower::showMessage() {
  std::cout << "¡Hola desde la instancia ControlTower!" << std::endl;
}

