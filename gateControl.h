/*
 *
 * Juan Collazos
 * Oscar Vargas
 * octubre 6 del 2023
*/

#ifndef GATE_CONTROL_H
#define GATE_CONTROL_H

#include "flight.h"
#include "boardingGate.h"
#include <map>
#include <string>

class GateControl {
 private:
  std::map<std::string,BoardingGate*> gates;
 public:
  GateControl();

  std::string bookBoardingGate( Flight * );
  void freeBoardingGate( const std::string & );

};


#endif //GATE_CONTROL_H
