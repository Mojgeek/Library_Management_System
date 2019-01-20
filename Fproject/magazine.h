#ifndef magazine_h
#define magazine_h
#include"library.h"
#include<string>
#include<iostream>

class magazine : public library
{
public:
	magazine(string, string, string, string);
	~magazine();
	string getIssueNum()const;
	void setIssueNume(string);
	virtual void print() const;
	virtual string printfile()const;
	virtual bool search(string) const;
private:
	string  issueNum;

};
#endif magazine_h
