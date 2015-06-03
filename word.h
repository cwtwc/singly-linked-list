#ifndef WORD_H
#define WORD_H

using namespace std; 

// Declaration for a node in the list
class character {				// Node
public:						
	char symbol;				// Data in node
	character *next;			// Point to the next node
};

// Declaration of a list class
class WORD {
public:
	WORD();						// Default constructor
	WORD(const WORD &);			// Copy constructor
	WORD(string);			// Explicit-value constructor
	WORD::~WORD();				// Destructor
	void toEmpty();
	void Print();				// Prints linked list
	friend ostream & operator<<(ostream &, WORD &);
	WORD & operator=(const string &rhs);
	WORD & operator+(WORD &);
	bool Is_Empty();			// Checks whether linked list is empty
	int Length();				// Determines number of elements in linked list
	void Insert(WORD &, int);		// Inserts a node
	void Search(character * &, const int &);	// Searches for a certain node
	void Remove(const char &);		// Removes a node

private:
	character *front, *back;
	int count;
	int length;
};

#endif
