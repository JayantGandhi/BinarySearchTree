//CHAR.h
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#ifndef CHAR_H
#define CHAR_H

#include <iostream>

struct CHAR
{
	char data [256];

	CHAR();
	CHAR(char *x);
	CHAR(const CHAR& otherCHAR);
	~CHAR();
	const CHAR& operator=(const CHAR& rhs);
	bool operator==(const CHAR& rhs) const;
	bool operator<(const CHAR& rhs) const;

	friend std::ostream& operator<<(std::ostream& oStr, const CHAR& myCHAR);
};


#endif