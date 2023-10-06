/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
3/10/2023
*/

#include "crew.h"

/*
####################### constructores ############################
*/
Crew::Crew( const std::string &cedula,const std::string &name,const std::string &surname,const std::string &birthDate,const std::string &genre,const std::string &address,const std::string &phoneNumber,const std::string &email, const std::string &jobPosition, int dailyWorkingHours, int yearsExperience ) : Person( cedula, name, surname, birthDate, genre, address, phoneNumber, email ), jobPosition(jobPosition), dailyWorkingHours(dailyWorkingHours), yearsExperience(yearsExperience) {};

/*
####################### Getters ############################
*/

std::string Crew::getJobPosition(){
	return this->jobPosition;
}
int Crew::getDailyWorkingHours(){
	return this->dailyWorkingHours;
}
int Crew::getYearsExperience(){
	return this->yearsExperience;
}

/*
####################### Setters ############################
*/

void Crew::setJobPosition( const std::string &jobPosition ){
	this->jobPosition = jobPosition;
}
void Crew::setDailyWorkingHours( int dailyWorkingHours ){
	this->dailyWorkingHours = dailyWorkingHours;
}
void Crew::anotherYearsExperience(){
	++this->yearsExperience;
}

/*
####################### Information ############################
*/
void Crew::info(){
	Person::info();
	std::cout << ".Position: " << this->jobPosition;
}
