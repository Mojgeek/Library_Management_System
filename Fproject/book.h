#ifndef book_h
#define book_h
#include "library.h"
#include<string>
#include<iostream>


class book : public library
{
public:
	book(string, string, string, string);
	~book();
	string getAuthor()const;
	void setAuthor(string);
	virtual void print() const;
	virtual string printfile()const;
	virtual bool search(string) const;
private:
	string author;

};

#endif book_h

