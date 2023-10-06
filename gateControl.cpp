  /*
 *
 * Juan Collazos
 * Oscar Vargas
 * octubre 6 del 2023
*/

#include "gateControl.h"

GateControl::GateControl(){
  std::cout << "terminar para mas rato" << std::endl;
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

void freeBoardingGate( const std::string &gateId ){
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
