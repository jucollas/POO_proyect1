#ifndef FACTORY_PLANE_H
#define FACTORY_PLANE_H

#include "aircraftFactory.h"
#include "plane.h"

class PlaneFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override;
};

#endif