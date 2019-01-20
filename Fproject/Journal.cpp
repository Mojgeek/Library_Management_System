#include "Journal.h"

Journal::Journal(string name, string id, string status, string volumeNum)
	: library(name, id, status)
{
	volume = volumeNum;
}

Journal::~Journal()
{
}

string Journal::getVolume() const
{
	return volume;
}

void Journal::setVolume(string volumeNum)
{
	volume = volumeNum;
}

void Journal::print() const
{
	cout << getName() << endl;
	cout << getID() << endl;
	cout << getStatus() << endl;
	cout << volume << endl;

}

string Journal::printfile() const
{
	string temp;
	temp = "Journal\n" + getName() + "\n" + getID() + "\n" + getStatus() + "\n" + getVolume() + "\n\n";
	return temp;
}

bool Journal::search(string term) const
{
	return (term == getName() || term == getID() || term == getStatus() || term == getVolume());
}
