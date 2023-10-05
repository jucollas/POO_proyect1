#include "helicopterFactory.h"
#include "planeFactory.h"
#include "jetFactory.h"

int main(){
    AircraftFactory* factory = NULL;
    Aircraft* aircraft = NULL;
    int option;
    cout << "Bienvenido al modulo de Aeronaves" << endl;
    cout << "que tipo de areo nave desea ingresar en el sistema ?" << endl;
    cout << "1. avion" << endl;
    cout << "2. jet" << endl;
    cout << "3. helicoptero" << endl;
    cin >> option;
    
    if (option == 1){
        factory = new PlaneFactory();
    }else if(option == 2){
        factory = new JetFactory();
    }else if(option == 3){
        factory = new HelicopterFactory();
    }
    aircraft = factory->crearAeronave();
    aircraft->printInfo();
}