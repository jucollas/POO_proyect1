/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "flight.h"

Flight::Flight( Aircraft *aircraft, ControlTower *control, const std::list<Crew*> &crewMates, const std::string &flightCode, const std::string &date, const std::string &origin, const std::string &destiny, double latitude, double longitude, int height ) : aircraft(aircraft), control(control), crewMates(crewMates), flightCode(flightCode), date(date), origin(origin), destiny(destiny), longitude(longitude), latitude(latitude), height(height), activeFlight(false), gateId("") {
  this->aircraft->assignFlight();
  this->alreadyFlew = false;
}

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
  if ( !this->isActive() ){
    std::cout << "The flight is inactive" << std::endl;
    return;
  }
  srand(time(0));
  int height;
  double latitude, longitude;
  int random_num;
  latitude =static_cast<double>(rand() % 18001 - 9000) / 100.0;
  height =rand() % 18001 - 9000;
  longitude =static_cast<double>(rand() % 36001 - 18000) / 100.0;
  this->setCoordinates(height,latitude, longitude);
  this->infoCord();
  Message *m = new Message( longitude,latitude, height, this->flightCode );
  control->notifyFlights( m );
  delete m;
}

void Flight::receiveMessage( Message *m ){
  if ( m->flightCode != this->flightCode ){
    std::cout << this->flightCode << " received the message: latitude( " << m->latitude << " ), longitude( " << m->longitude << " ), height( " << m->height << " ) flightCode( " << m->flightCode << " )" << std::endl;  
  }
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
  bool res = !this->isActive() && !this->alreadyFlew;
  res = res && !this->aircraft->isInFlight() && !this->aircraft->inManteinance();
  if ( onGround && res ) {
    this->gateId = control->bookBoardingGate( this );
    res = this->gateId != std::string();
  }
  if ( res ) {
    control->addFlight( this );
    this->activeFlight = true;
    this->aircraft->activateFlight();
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
    this->alreadyFlew = true;
    std::cout << "Flight disconected from control tower" << std::endl;
  } else {
    std::cout << "Flight unable to disconnect" << std::endl;
  }
  return res;
}

bool Flight::hasItAlreadyFlew(){
  return this->alreadyFlew;
}


bool Flight::isActive(){
  return this->activeFlight;
}

bool Flight::isInAir(){
  return this->gateId == "";
}

bool Flight::hasAvailableSeats(){
  return this->passengers.size() < this->aircraft->getAbilityPass();
}

bool Flight::bookSeat( Passenger *passenger ){
  bool res = this->hasAvailableSeats();
  if ( res ){
    this->passengers.push_back( passenger );
  } else {
    std::cout << "Error: there are not enough seats." << std::endl;
  }
  return res;
}
int Flight::getBookedSeats(){
  return this->passengers.size();
}


bool Flight::operator< ( const Flight &f ) const{
  bool res = this->flightCode < f.flightCode;
  return res;
}

void Flight::info(){
  std::cout << "Flight " << this->flightCode << " with " << this->passengers.size() << " passengers. It goes from " << this->origin << " to " << this->destiny << ". It is assigned to the aircraft " << this->aircraft->getN_number();
  if ( this->isActive() ){
    std::cout << ". It's active";
    if ( this->isInAir() ){
      std::cout << " and flying.";
    } else {
      std::cout << " and assigned to gate " << this->gateId;
    }
  }
  std::cout << std::endl;
}

void Flight::setCoordinates(int height, double latitude, double longitude){
  this->height =height;
  this->latitude = latitude;
  this->longitude = longitude;
}

void Flight::infoCord(){
  cout << "------------------------------------------" << endl;
  cout << " Flight " << this->flightCode << " report :"<< endl;
  cout << "- height :" << this->height << endl;
  cout << "- latitude :" << this->latitude << endl;
  cout << "- longitude :" << this->longitude << endl;
  cout << "------------------------------------------" << endl;
}
