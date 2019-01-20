#ifndef system_h
#define system_h
#include<typeinfo>
#include<vector>
#include "library.h"
#include"book.h"
#include"Journal.h"
#include"magazine.h"
#include<string>
#include<fstream>
using namespace std;


class Ssystem
{
public:
	Ssystem();
	void userInterface();
	void loadFunction();
	bool searchFunction();
	void listFunction();
	void checkOutFunction();
	void addFunction();
	void returnFunction();
	void  showMenue();
	void deletePointers();
	void saveFunction();






private:

	vector<library*> container;
	vector<library*>::iterator it;




};
#endif system_h

