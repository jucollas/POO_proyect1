/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "controlTower.h"

ControlTower::ControlTower(){
  
}

ControlTower* ControlTower::getInstance(){
  if ( ControlTower::instance == NULL ){
    ControlTower::instance = new ControlTower();
  }
  return ControlTower::instance;
}

void addFlight( Flight *f ){
  flights.insert( f );
}

void deleteFlight( Flight *f ){
  flights.erase( f );
}

void notifyFlight( Message* m ){
  for ( std::set<Flight*>::iterator it = flights.begin() ; it != flights.end() ; ++it ) {
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
