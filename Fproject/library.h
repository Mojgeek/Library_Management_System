#ifndef library_h
#define library_h
#include <string>
using namespace std;

class library {
public:
	library(string, string, string);
	virtual ~library();
	string getName() const;
	string getID() const;
	string getStatus() const;
	void setName(string);
	void setID(string);
	void setStatus(string);
	virtual void print() const = 0;
	virtual string printfile() const = 0;
	virtual bool search(string) const = 0;






private:
	string ID;
	string name;
	string status;

};

#endif library_h
