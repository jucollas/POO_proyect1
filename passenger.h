/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
3/10/2023
*/

#ifndef PASSENGER_H
#define PASSENGER_H

#include "person.h"

class Passenger : public Person {
protected:
	std::string nationality, medicalInfo;
public:
	int luggageAmount;

	/* constructor */

	Passenger( const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &, int );

	/* Getters */

	std::string getNationality();
	std::string getMedicalInfo();

	/* Setters */

	void setMedicalInfo( const std::string & );

};

#endif //PASSENGER_H
