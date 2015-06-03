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
/////////////
/*******************************************************
H E A D E R  F I L E
******************************************************/

//*****************************************************************************
//
//  Name:  Wein T. Wong
//	Z#:  Z23320315
//	Instructor:  Dr. Bullard
//	Class:  Data Structures
//	Term:  Summer 2015
//	Assignment #2 (singly linked list)
//	Due Date:  June 3, 2015   
//	Due Time:  10:00PM
//	Points:  100 
//	
//  Description: Implement the WORD abstract data type using a singly-linked list of characters.
//				 
//******************************************************************************

#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#pragma once

#pragma once
#include <iostream>
#include <string>


class character
{
public:
	char symbol;
	character *next;
};


class WORD
{
public:

	// Structors
	WORD();
	WORD(std::string);
	WORD(const WORD & w);
	~WORD();

	// Operator overloads
	WORD & operator=(const std::string &);
	WORD & operator=(const WORD &w);
	// Friends
	friend std::ostream & operator<<(std::ostream &, WORD &);

	// Behaviors
//	void CatWords(WORD &);
	int  Length();
//	void Print();
//	void Insert(WORD, int);
	bool IsEmpty();
	bool IsEqual(WORD &);
	bool Remove(WORD &);
	void RemoveALL(WORD &);
//	void SetEqual(WORD &);

	// Getter functions
	character * getFront() { return front; }  // returns the address to the front node

private:

	// Helper functions
	//character * Search(WORD &); // returns a character address to a matched word
	void Search(character*&, character*&, WORD &);
	character * SearchPrior(WORD &); // searches for what kind of mischief the node has been up to, then returns the node prior to a matched word
//	void InsertLetter(char, int);    // creates a new node in memory and inserts it into the middle of the list
//	void InsertLetter(char); // creates a new node in the front of a list
	void add(char); // adds a character to the end of a list

	// state variables 
	character *front;  // front node in the list
	character *back;   // back node in the list

};

#endif
