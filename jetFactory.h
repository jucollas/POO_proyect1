#ifndef FACTORY_JET_H
#define FACTORY_JET_H

#include "aircraftFactory.h"
#include "jet.h"

using namespace std;

class JetFactory : public AircraftFactory {
public:
    Aircraft* crearAeronave() override;
};

#endif // FACTORY_JET_H