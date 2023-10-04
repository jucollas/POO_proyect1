/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
  double latitude, longitude;
  int height;
  std::string flightCode;
  
  Message( double, double, int, const std::string & );
  Message();
};


#endif //MESSAGE_H
