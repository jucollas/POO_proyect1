/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
2/10/2023
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
	std::string cedula, name, surname, birthDate, genre, address, phoneNumber, email;
public:
	Person( const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string & );

	/* Getters */

	std::string getCedula();
	std::string getName();
	std::string getSurname();
	std::string getBirthDate();
	std::string getGenre();
	std::string getAddress();
	std::string getPhoneNumber();
	std::string getEmail();

	/* Setters */

	void setAddress( const std::string & );
	void setPhoneNumber( const std::string & );
	void setEmail( const std::string & );

};

#endif // PERSON_H