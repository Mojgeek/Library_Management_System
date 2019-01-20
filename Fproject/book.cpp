
#include"book.h"
#include<string>
using namespace std;


book::book(string name, string id, string status, string writer)
	: library(name, id, status)
{
	author = writer;
}

book::~book()
{
}

string book::getAuthor() const
{
	return author;
}

void book::setAuthor(string writer)
{
	author = writer;
}

void book::print() const
{
	cout << getName() << endl;
	cout << getID() << endl;
	cout << getStatus() << endl;
	cout << author << endl;
}

string book::printfile() const
{


	string temp;
	temp = "Book\n" + getName() + "\n" + getID() + "\n" + getStatus() + "\n" + getAuthor() + "\n\n";
	return temp;
}

bool book::search(string term) const
{
	return (term == getName() || term == getID() || term == getStatus() || term == getAuthor());
}

