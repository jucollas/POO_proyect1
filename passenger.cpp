/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
3/10/2023
*/

#include "passenger.h"

/*
####################### constructors ############################
*/


Passenger::Passenger( const std::string &cedula,const std::string &name,const std::string &surname,const std::string &birthDate,const std::string &genre,const std::string &address,const std::string &phoneNumber,const std::string &email,const std::string &nationality,const std::string &medicalInfo, int luggageAmount ) : Person( cedula, name, surname, birthDate, genre, address, phoneNumber, email ), nationality(nationality), medicalInfo(medicalInfo), luggageAmount(luggageAmount) {};

/*
####################### Getters ############################
*/

std::string Passenger::getNationality(){
	return this->nationality;
}
std::string Passenger::getMedicalInfo(){
	return this->medicalInfo;
}

/*
####################### Setters ############################
*/

void Passenger::setMedicalInfo( const std::string &medicalInfo ){
	this->medicalInfo = medicalInfo;
}

