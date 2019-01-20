#ifndef Journal_h
#define Journal_h
#include"library.h"
#include<string>
#include<iostream>

class Journal : public library
{
public:
	Journal(string, string, string, string);
	~Journal();
	string getVolume()const;
	void setVolume(string);
	virtual void print() const;
	virtual string printfile() const;
	virtual bool search(string) const;
private:
	string volume;

};
#endif magazine_h


