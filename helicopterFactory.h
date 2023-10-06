#ifndef FACTORY_HELICOPTER_H
#define FACTORY_HELICOPTER_H

#include "aircraftFactory.h"
#include "helicopter.h"

class HelicopterFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override;
};

#endif