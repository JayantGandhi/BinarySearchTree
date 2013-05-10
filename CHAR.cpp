//CHAR.h
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#include <iostream>
#include <cstring>
#include "CHAR.h"

CHAR::CHAR()
{
}

CHAR::CHAR(char *x)
{
	strcpy (data, x);
}

CHAR::CHAR(const CHAR& otherCHAR)
{
	strcpy (data, otherCHAR.data);
}

CHAR::~CHAR()
{
}

const CHAR& CHAR::operator= (const CHAR& rhs)
{
	strcpy (data, rhs.data);
}

bool CHAR::operator== (const CHAR& rhs) const
{
	if (strcmp(data, rhs.data)==0)
		return true;
	else
		return false;
}

bool CHAR::operator< (const CHAR& rhs) const
{
	if (strcmp(data, rhs.data)<0)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& oStr, const CHAR& myCHAR)
{
	oStr << myCHAR.data;
}
