//INT.cpp
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#include <iostream>
#include "INT.h"

INT::INT()
{
	data=NULL;
}

INT::INT(int x)
{
	data= x;
}

INT::INT(const INT& otherINT)
{
	data=otherINT.data;
}

INT::~INT()
{
}

const INT& INT::operator=(const INT& rhs)
{
	data=rhs.data;
}

bool INT::operator==(const INT& rhs)
{
	return (data==rhs.data);
}

bool INT::operator<(const INT& rhs)
{
	return (data<rhs.data);
}

std::ostream& operator<<(std::ostream& oStr, const INT& myINT)
{
	oStr << myINT.data;
	return oStr;
}