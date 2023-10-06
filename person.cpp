/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
2/10/2023
*/

#include "person.h"

/*
####################### Constructor ############################
*/

Person::Person( const std::string &cedula,const std::string &name,const std::string &surname,const std::string &birthDate,const std::string &genre,const std::string &address,const std::string &phoneNumber,const std::string &email ) : cedula(cedula), name(name), surname(surname), birthDate(birthDate), genre(genre), address(address), phoneNumber(phoneNumber), email(email) {};

/*
####################### Getters ############################
*/

std::string Person::getCedula(){
	return this->cedula;
}
std::string Person::getName(){
	return this->name;
}	
std::string Person::getSurname(){
	return this->surname;
}
std::string Person::getBirthDate(){
	return this->birthDate;
}
std::string Person::getGenre(){
	return this->genre;
}
std::string Person::getAddress(){
	return this->address;
}
std::string Person::getPhoneNumber(){
	return this->phoneNumber;
}
std::string Person::getEmail(){
	return this->email;
}

/*
####################### Setters ############################
*/

void Person::setAddress( const std::string &address ){
	this->address = address;
}
void Person::setPhoneNumber( const std::string &phoneNumber ){
	this->phoneNumber = phoneNumber;
}
void Person::setEmail( const std::string &email ){
	this->email = email;
}

/*
####################### information ############################
*/

void Person::info(){
	std::cout << name << " " << surname << "[" << cedula << "]";
}
