#include <iostream>
#include "system.h"
#include<vector>
#include<string>

Ssystem::Ssystem() // constructor 
{
	try
	{
		loadFunction();
		userInterface();
	}
	catch (logic_error e)
	{
		cout << "Exception caught: ";
		e.what();
	}
}

void Ssystem::userInterface() // This function calls the show menue ( which prints out the menue and also asks the user to choose the number). this function
						// gets the user input and calls out each function that matches its specific number 

{
	char userInput;
	string trash;


	do {

		showMenue();
		cin >> userInput;

		switch (userInput)
		{
		case '1':
			listFunction(); // loads the entire catalog
			break;
		case '2':
			searchFunction(); // searches for an item
			break;
		case '3':
			checkOutFunction(); // checks out an item
			break;
		case '4':
			addFunction();// adds an item
			break;
		case '5':
			returnFunction(); // returns an item 
			break;
		case'6':
			saveFunction(); // saves the data and writes everything to a file and exits the function
			return;
		default:
			cout << " Please choose a number between 1-6" << endl;
			getline(cin, trash);
		}
	} while (true);

}




void Ssystem::loadFunction() // To open and  read from the file 
{
	ifstream in;
	in.open("C:\\Users\\mojga\\Desktop\\CSC2111\\Fproject\\readfile.txt");

	if (!in)
	{
		throw logic_error("This is a logic error.");
	}

	while (in.peek() != EOF)
	{
		string itemType;
		getline(in, itemType);
		string name;
		getline(in, name);
		string id;
		getline(in, id);
		string status;
		getline(in, status);
		string fourthItem;
		string trash;
		getline(in, fourthItem);
		getline(in, trash);

		if (itemType == "Book") {
			container.push_back(new book(name, id, status, fourthItem));
		}
		else if (itemType == "Journal") {
			container.push_back(new Journal(name, id, status, fourthItem));
		}
		else if (itemType == "Magazine") {
			container.push_back(new magazine(name, id, status, fourthItem));
		}
	}
	in.close();
}

bool  Ssystem::searchFunction()
{
	cin.clear();
	cin.ignore();
	string userInput;
	bool found = false;
	cout << " Enter a search term( Name of the book/ID/ Name of the Author/Issue Number 0r volume" << endl;
	getline(cin, userInput);

	for (it = container.begin(); it != container.end(); it++)
	{
		if ((*it)->search(userInput) == true)
		{
			(*it)->print();
			found = true;
		}
	}

	if (found == false)
		cout << "Not found." << endl;

	return found;
}

void Ssystem::listFunction() // prints out the entire vector 
{
	if (container.empty())
	{
		cout << "Empty.  Nothing to print." << endl;
		return;
	}

	for (it = container.begin(); it != container.end(); it++)
	{
		(*it)->print();
		cout << endl;
	}
	cout << endl;

}

void Ssystem::checkOutFunction()
{
	string id;
	bool found = false;
	if (!searchFunction())
		return;

	cout << "Please enter the ID number:" << endl;
	cin >> id;
	for (it = container.begin(); it != container.end(); it++)
	{
		if ((*it)->getID() == id && (*it)->getStatus() == "Available")
		{
			cout << "You successfully checked out the item." << endl;
			(*it)->setStatus("Unavailable");
			found = true;

		}
		else if ((*it)->getID() == id && (*it)->getStatus() == "unavailable")
		{
			cout << " The item you are looking for is currently unavailable." << endl;
			found = true;
		}


	}

	if (found == false)
		cout << "requested item not found" << endl;

}

void Ssystem::addFunction()
{
	// adding the books/ magazines/ journals to the container i.e pushing back to the vector

	string itemType;
	string id;
	string name;
	string status;
	string author;
	string issueNumber;
	string volume;

	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Please enter a type: (Magazine, Book, Journal): ";
	getline(cin, itemType);

	while (itemType != "Magazine" && itemType != "Book" && itemType != "Journal")
	{
		cout << "Invalid input.  Please try again.";
		getline(cin, itemType);
	}

	if (itemType == "Book") {
		cout << " please enter the author of the book: " << endl;
		getline(cin, author);
	}
	else if (itemType == "Journal") {
		cout << " Please enter the volume of the journal: " << endl;
		getline(cin, volume);
	}

	else
	{
		cout << " please enter the issue number of the magazine: " << endl;
		getline(cin, issueNumber);
	}

	cout << " Please enter the name of the item " << endl;
	getline(cin, name);
	cout << " please enter the ID number: " << endl;
	getline(cin, id);
	cout << "Is it available at the moment? (y/n) " << endl;
	getline(cin, status);

	while (status != "Y" && status != "N" && status != "y" && status != "n")
	{
		cout << "Invalid input. Try again." << endl;
		getline(cin, status);
	}

	if (status == "Y" || status == "y")
		status = "Available";
	else
		status = "Unavailable";


	for (it = container.begin(); it != container.end(); it++) {

		if (id == (*it)->getID() || name == (*it)->getName())
		{
			(*it)->print();
			cout << "Record already in system." << endl;
			return;
		}

	}
	if (itemType == "Book") {

		container.push_back(new book(name, id, status, author));// address of the new book object
	}

	else if (itemType == " Journal") {
		container.push_back(new Journal(name, id, status, volume));
	}

	else
	{
		container.push_back(new magazine(name, id, status, issueNumber));
	}

}

void Ssystem::returnFunction()
{
	string id;
	bool found = false;
	if (!searchFunction())
		return;
	cout << "Please enter the ID number:" << endl;
	cin >> id;
	for (it = container.begin(); it != container.end(); it++)
	{
		if ((*it)->getID() == id && (*it)->getStatus() == "unvailable")
		{
			cout << "You successfully returned the item." << endl;
			(*it)->setStatus("Available");
			found = true;

		}
		else if ((*it)->getID() == id && (*it)->getStatus() == "Available")
		{
			cout << " The item you are looking for is already returned." << endl;
			found = true;
		}


	}

	if (found == false)
		cout << "requested item not found" << endl;

}

void Ssystem::showMenue()
{
	cout << " choose an item from the Menue:" << endl;
	cout << " 1) Show the entire catalog" << endl;
	cout << " 2) Search for an item" << endl;
	cout << " 3) Check out an item" << endl;
	cout << " 4) Add an item to the existing catalog" << endl;
	cout << " 5) Return an item" << endl;
	cout << " 6) Exit." << endl;

}

void Ssystem::deletePointers()
{
	for (it = container.begin(); it != container.end(); it++) {

		if ((*it) != NULL)
			delete (*it);
	}

	container.clear();
}



void Ssystem::saveFunction() // save the existing or updated data and writes it to a text file
{
	ofstream fout;
	fout.open("C:\\Users\\mojga\\Desktop\\CSC2111\\Fproject\\output.txt");
	if (!fout)
	{
		throw string("The output file did not open");
	}

	for (it = container.begin(); it != container.end(); it++) {
		fout << (*it)->printfile();
	}

	if (!fout) {
		throw string("Could not write to the file");
	}

	fout.close();

	deletePointers();


}








