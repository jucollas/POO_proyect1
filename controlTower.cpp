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
  std::cout << "alo alo" << std::endl;
}

ControlTower* ControlTower::getInstance(){
  if ( ControlTower::instance == NULL ){
    ControlTower::instance = new ControlTower();
  }
  return ControlTower::instance;
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

void ControlTower::showMessage() {
  std::cout << "¡Hola desde la instancia ControlTower!" << std::endl;
}

int main(){
  ControlTower *a = ControlTower::getInstance();
  ControlTower *b = ControlTower::getInstance();
  a->showMessage();
  std::cout << (a == b) << std::endl;
  return 0;
}
