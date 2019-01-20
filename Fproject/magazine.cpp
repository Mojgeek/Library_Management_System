#include "magazine.h"

magazine::magazine(string name, string id, string status, string issNum)
	: library(name, id, status)

{
	issueNum = issNum;
}

magazine::~magazine()
{
}

string magazine::getIssueNum() const
{
	return issueNum;
}

void magazine::setIssueNume(string issNum)

{
	issueNum = issNum;
}

void magazine::print() const
{
	cout << getName() << endl;
	cout << getID() << endl;
	cout << getStatus() << endl;
	cout << issueNum << endl;
}

string magazine::printfile() const
{

	string temp;
	temp = "Magazine\n" + getName() + "\n" + getID() + "\n" + getStatus() + "\n" + getIssueNum() + "\n\n";
	return temp;
}

bool magazine::search(string term) const
{
	return(term == getName() || term == getID() || term == getStatus() || term == getIssueNum());
}

