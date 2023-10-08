/*
 *
 * Juan Collazos
 * Oscar Vargas
 * octubre 6 del 2023
*/

#ifndef GATE_CONTROL_H
#define GATE_CONTROL_H

class GateControl;

#include <map>
#include <string>
#include "boardingGate.h"
#include "flight.h"


class GateControl {
private:
    std::map<std::string,BoardingGate*> gates;
public:
    GateControl();

    std::string bookBoardingGate( Flight * );
    void freeBoardingGate( const std::string & );

    void addGate( const std::string &, const std::string & );

    void info();

    ~GateControl();
};


#endif //GATE_CONTROL_H
