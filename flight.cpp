/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "flight.h"

Flight::Flight( Aircraft *aircraft, ControlTower *control, const std::list<Passenger*> &passengers, std::list<Crew*> &crewMates, const std::string &flightCode, const std::string &date, const std::string &origin, const std::string &destiny, double latitude, double longitude, int height ) : aircraft(aircraft), control(control), passengers(passengers), crewMates(crewMates), flightCode(flightCode), date(date), origin(origin), destiny(destiny), longitude(longitude), latitude(latitude), height(height) {};


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

bool Flight::operator< ( const Flight &f ) const{
  bool res = this->flightCode < f.flightCode;
  return res;
}

void Flight::info(){
  std::cout << "Flight " << this->flightCode << " with " << this->passengers.size() << " passengers. It goes from " << this->origin << " to " << this->destiny << std::endl;
}