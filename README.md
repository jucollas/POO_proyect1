# Proyecto de Modelamiento de Aeropuerto en C++

Este es un proyecto de programación orientada a objetos que modela un aeropuerto en C++. El objetivo principal de este proyecto es crear un sistema que pueda gestionar las operaciones básicas de un aeropuerto, como la llegada y salida de vuelos, la gestión de pasajeros y la disponibilidad de peuertos de embarque.

## Requisitos del Sistema

Para compilar y ejecutar este proyecto, necesitarás:

- Un compilador C++ compatible con el estándar C++11 o superior.
- Acceso a una terminal de línea de comandos para compilar y ejecutar el programa.
- Conocimientos básicos de C++ y programación orientada a objetos.

## Estructura del Proyecto

El proyecto está organizado de la siguiente manera:

Interfaz con el usuario (menu)
- `main.cpp`

Implentacion de clase Aircraft y su derivadas
- `aircraft.h` y `aircraft.cpp`
    - `helicopter.h` y `helicopter.cpp`
    - `jet.h` y `jet.cpp`
    - `plane.h` y `plane.cpp`

Implentacion de clase aircraftFactorty y su derivadas, Patrones : Factory.
- `aircraftFactory.h` y `aircraftFactory.cpp`
    - `HelicopterFactory.h` y `HelicopterFactory.cpp`
    - `PlaneFactory.h` y `PlaneFactory.cpp`
    - `JetFactory.h` y `JetFactory.cpp`

Implentacion de clase aircraftFactorty y message (clases relacionadas), Patrones : Singleton, Mediator.
- `ControlTower.h` y `ControlTower.cpp`
- `Message.h` y `Message.cpp`

Implentacion de clase aircraftFactorty y message (clases relacionadas).
- `Flight.h` y `Flight.cpp`
- `BuyingManager.h` y `BuyingManager.cpp`

Implentacion de clase BoardinGate y GateControl (clases relacionadas).
- `BoardingGate.h` y `BoardingGate.cpp`
- `GateControl.h` y `GateControl.cpp`

Implentacion de clase person y su derivadas
- `Person.h` y `Person.cpp`
  - `Crew.h` y `Crew.cpp`
  - `Passenger.h` y `Passenger.cpp`
  
## Compilación y Ejecución

Para compilar el proyecto, abre una terminal en el directorio raíz y ejecuta los siguientes comandos:
- .\makeFile.cmd
- .\airport.exe

## Manual

1. Complia y ejecuta desde la terminal segun las indicaciones anteriores.
2. Se deplagara un intefaz de usario con menus y comandos que permiten la adminstracion completa del arepuerto modelado, como dichos menus y comandos se encuentran correctamente explicados dentro del programa asi qeu no hace falta explicarlos aqui
