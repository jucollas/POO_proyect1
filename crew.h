/*
 * Juan Diego Collazos
 * Oscar Vargas
 *
 * Proyecto POO
3/10/2023
*/

#ifndef CREW_H
#define CREW_H

#include "person.h"

class Crew : public Person {
protected:
	std::string jobPosition;
	int dailyWorkingHours, yearsExperience;
public:
	Crew( const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,const std::string &,int, int );

	/* Getters */

	std::string getJobPosition();
	int getDailyWorkingHours();
	int getYearsExperience();

	/* Setters */

	void setJobPosition( const std::string & );
	void setDailyWorkingHours( int );
	void anotherYearsExperience();

};

#endif //CREW_H
