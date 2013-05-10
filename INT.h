//INT.h
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#ifndef INT_H
#define INT_H

#include <iostream>

struct INT
{
	int data;

	INT();
	INT(int x);
	INT(const INT& otherINT);
	~INT();
	const INT& operator=(const INT& rhs);
	bool operator==(const INT& rhs);
	bool operator<(const INT& rhs);

	friend std::ostream& operator<<(std::ostream& oStr, const INT& myINT);
};

#endif