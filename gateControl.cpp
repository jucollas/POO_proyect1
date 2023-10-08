  /*
 *
 * Juan Collazos
 * Oscar Vargas
 * octubre 6 del 2023
*/

#include "gateControl.h"

GateControl::GateControl(){
}

std::string GateControl::bookBoardingGate( Flight * f ){
  std::map<std::string,BoardingGate*>::iterator mapValue = this->gates.begin();
  while ( mapValue != this->gates.end() && !mapValue->second->isAvailable() ) {
    ++mapValue;
  }
  std::string res;
  if ( mapValue != this->gates.end() ) {
    if ( mapValue->second->assignFlight( f ) ) {
      res = mapValue->first;
    }
  }
  if ( res == std::string() ){
    std::cout << "Error: impossible to book a gate" << std::endl;
  }
  return res;
}

void GateControl::freeBoardingGate( const std::string &gateId ){
  std::map<std::string,BoardingGate*>::iterator mapValue = this->gates.find( gateId );
  if ( mapValue == this->gates.end() ) {
    std::cout << "Error: the gateId \"" << gateId << "\" is not in the gates" << std::endl;
  } else if ( mapValue->second->isAvailable() ) {
    std::cout << "The gate \"" << gateId << "\" is already free." << std::endl;
  } else {
    mapValue->second->dispatchFlight();
    std::cout << "The gate \"" << gateId << "\" is now free." << std::endl;
  }
}

void GateControl::addGate( const std::string &id, const std::string &location ){
  BoardingGate *tmp = new BoardingGate( id, location );
  this->gates.insert( std::pair<std::string,BoardingGate*>( id, tmp ) );
}

GateControl::~GateControl(){
  for ( std::map<std::string,BoardingGate*>::iterator it = this->gates.begin() ; it != this->gates.end() ; ++it ){
    delete it->second;
  }
}

void GateControl::info(){
  std::cout << "There are " << this->gates.size() << " gates:" << std::endl;
  for ( std::map<std::string,BoardingGate*>::iterator it = this->gates.begin() ; it != this->gates.end() ; ++it ){
    it->second->info();
  }

}
