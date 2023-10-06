#ifndef FACTORY_AIRCRAFT_H
#define FACTORY_AIRCRAFT_H

#include "aircraft.h"

using namespace std;

class AircraftFactory {
public:
    virtual Aircraft* crearAeronave();
};

#endif