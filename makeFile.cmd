@echo off
g++ -c aircraft.cpp
g++ -c plane.cpp
g++ -c jet.cpp
g++ -c helicopter.cpp
g++ -c person.cpp
g++ -c crew.cpp
g++ -c passenger.cpp
g++ -c controlTower.cpp
g++ -c flight.cpp
g++ -c message.cpp
g++ -c flightBuilder.cpp
g++ -c aircraftFactory.cpp
g++ -c helicopterFactory.cpp
g++ -c planeFactory.cpp
g++ -c jetFactory.cpp
g++ -c boardingGate.cpp


g++ aircraft.o plane.o jet.o helicopter.o person.o crew.o passenger.o controlTower.o flight.o message.o flightBuilder.o aircraftFactory.o helicopterFactory.o planeFactory.o jetFactory.o boardingGate.o main.cpp -o airport
echo on