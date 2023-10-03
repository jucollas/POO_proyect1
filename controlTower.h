#ifndef CONTROL_TOWER_H
#define CONTROL_TOWER_H

#include <iostream>
#include <vector>

class ControlTower {
private:
    //vector<>
    ControlTower();
public:
    static ControlTower& getInstance() {
        static ControlTower instance;
        return instance;
    }

    void showMessage() {
        std::cout << "¡Hola desde la instancia ControlTower!" << std::endl;
    }
};

#endif