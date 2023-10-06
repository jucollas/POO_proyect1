/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "flight.h"

Flight::Flight( Aircraft *aircraft, ControlTower *control, const std::list<Passenger*> &passengers, std::list<Crew*> &crewMates, const std::string &flightCode, const std::string &date, const std::string &origin, const std::string &destiny, double latitude, double longitude, int height ) : aircraft(aircraft), control(control), passengers(passengers), crewMates(crewMates), flightCode(flightCode), date(date), origin(origin), destiny(destiny), longitude(longitude), latitude(latitude), height(height), activeFlight(false), gateId("") {};

std::string Flight::getGateId(){
  return this->gateId;
}

std::string Flight::getFlightCode(){
  return this->flightCode;
}
std::string Flight::getDate(){
  return this->date;
}
std::string Flight::getOrigin(){
  return this->origin;
}
std::string Flight::getDestiny(){
  return this->destiny;
}
Aircraft* Flight::getAircraft(){
  return this->aircraft;
}
std::list<Passenger*> Flight::getPassengers(){
  return this->passengers;
}
std::list<Crew*> Flight::getCrewMates(){
  return this->crewMates;
}

void Flight::sendFlightInformation(){
  Message *m = new Message( 1.0,2.1, 10, "avion1" );
  control->notifyFlights( m );
  delete m;
}

void Flight::receiveMessage( Message *m ){
  std::cout << "Message received: latitude( " << m->latitude << " ), longitude( " << m->longitude << " ), height( " << m->height << " ) flightCode( " << m->flightCode << " )" << std::endl;  
}

void Flight::land(){
  if ( !isActive() ){
    std::cout << "The flight is not active" << std::endl;
  } else if ( !isInAir() ){
    std::cout << "Was already on land" << std::endl;
  } else {
    this->gateId = control->bookBoardingGate( this );
    if ( this->gateId == std::string() ){
      std::cout << "Unable to land" << std::endl;
    } else {
      std::cout << "Landed. The assigned boarding gate is: " << this->gateId << std::endl;
    }
  }
}

void Flight::takeOff(){
  if ( !isActive() ) {
    std::cout << "The flight is not active" << std::endl;
  } else if ( isInAir() ) {
    std::cout << "The flight is already in the air" << std::endl;
  } else {
    control->freeBoardingGate( this->gateId );
    this->gateId = std::string();
    std::cout << "the Take off was sucessfull" << std::endl;
  }
}

bool Flight::activateFlight( bool onGround ){
  if ( isActive() ){
    std::cout << "already active" << std::endl;
    return false;
  }
  bool res;
  if ( onGround ) {
    this->activeFlight;
    res = true;
  } else {
    this->gateId = control->bookBoardingGate( this );
    res = this->gateId != std::string();
  }
  if ( res ) {
    control->addFlight( this );
    std::cout << "Flight connected to control tower" << std::endl;
  } else {
    std::cout << "Impossible to activate flight" << std::endl;
  }
  return res;
}

bool Flight::endFlight(){
  bool res = isActive();
  if ( res ) {
    control->deleteFlight( this );
    this->activeFlight = false;
    std::cout << "Flight disconected from control tower" << std::endl;
  } else {
    std::cout << "Flight unable to disconnect" << std::endl;
  }
  return res;
}


bool Flight::isActive(){
  return this->activeFlight;
}

bool Flight::isInAir(){
  return this->gateId == "";
}

bool Flight::operator< ( const Flight &f ) const{
  bool res = this->flightCode < f.flightCode;
  return res;
}

void Flight::info(){
  std::cout << "Flight " << this->flightCode << " with " << this->passengers.size() << " passengers. It goes from " << this->origin << " to " << this->destiny << std::endl;
}
