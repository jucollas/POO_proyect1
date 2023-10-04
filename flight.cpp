/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "flight.h"

void Flight::sendFlightInformation(){
  Message *m = new Message( 1.0,2.1, 10, "avion1" );
  control->notifyFlights( m );
  delete m;
}

void Flight::receiveMessage( Message *m ){
  std::cout << "Message received: latitude( " << m->latitude << " ), longitude( " << m->longitude << " ), height( " << m->height << " ) flightCode( " << m->flightCode << " )" << std::endl;  
  }

bool Flight::operator< ( const Flight &f ) const{
  bool res = this->codigo < f.codigo;
  return res;
}
