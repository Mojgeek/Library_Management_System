#ifndef library_cpp
#define library_cpp

#include "library.h"

library::library(string name, string id, string stat)
{
	setID(id);
	setName(name);
	setStatus(stat);
}

library::~library()
{
}

string library::getName() const
{
	return name;
}

string library::getID() const
{
	return ID;
}

string library::getStatus() const
{
	return status;
}

void library::setName(string name)
{
	this->name = name;
}

void library::setID(string id)
{
	ID = id;
}

void library::setStatus(string status)
{
	this->status = status;
}





#endif library_cpp