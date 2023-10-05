#include "jet.h"

Jet::Jet(string& N_number, string& brand, string& model, string& yearProduction, string& status, int abilityPass, int speedMax, int autonomy) : Aircraft(N_number, brand, model, yearProduction, status, abilityPass, speedMax, autonomy){
    owner = NULL;
}

