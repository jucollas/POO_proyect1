/*
 * Juan Diego Collazos
 * Oscar Vargas Pabon
 *
 * Proyecto POO
octubre 4 2023
 */

#include "message.h"

Message::Message( double latitude, double longitude, int height, const std::string &flightCode ) : latitude(latitude), longitude(longitude), height(height), flightCode(flightCode) {};

Message::Message() = default;
