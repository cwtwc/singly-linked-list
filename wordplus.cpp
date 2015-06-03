/*******************************************************
S O U R C E  F I L E
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
//  Description: Implement the WORD abstract data type using a
//				 singly-linked list of characters.
//				 
//******************************************************************************
#include <iostream>
#include <string>
#include "word.h"

using namespace std;
/*
/********************************************************************
Function Name: WORD
Preconditon: Front and back nodes are not initialized
Postcondition: Front and back nodes are initialized to 0 (null)
Description:  Default constructor; constructs an instance of a WORD
*********************************************************************/
WORD::WORD() {
	//cout << "Inside the default constructor\n";
	front = back = 0;							// Initialize front and back nodes to 0
}

/*********************************************************************
Function Name: WORD
Preconditon: WORD is being passed by reference
Postcondition: A hard copy of WORD has been created
Description: Copy constructor; used during a call by value, return,
or initialization/declaration of a WORD object
**********************************************************************/
WORD::WORD(const WORD & Org)
{
	//cout << "Copy Constructor Invoked" << endl;
	front = back = 0;							// Initialize front and back nodes to 0
	(*this) = Org;								// Pointer of WORD points to WORD from parameter
}

/*********************************************************************
Function Name: WORD
Preconditon: Front and back nodes are not initialized, and WORD object
does not reflect the string
Postcondition: WORD is initialized, nodes are initialized,
characters in the string are represented by the nodes
in WORD
Description: Explicit value constructor; parameter is a string,
results in creation of a WORD
**********************************************************************/
WORD::WORD(string str)
{
	//cout << "Explicit-value constructor invoked" << endl;
	/*if (str.length() == 0) {
		front = 0;
	}
	front = new character;
	character *p = front;
	for (int i = 0; i < str.length(); i++) {
		p->symbol = str[i];
		if (i != (str.length() - 1)) {
			p->next = new character;
			p = p->next;
		}
		else {
			p->next = 0;
		}
	}*/
	front = back = 0;
	(*this) = str;
}

/*********************************************************************
Function Name: ~WORD
Preconditon: Destructor has not been invoked
Postcondition: Nodes deleted
Description: Deallocates memory
**********************************************************************/
WORD::~WORD() {
	cout << "destructor called\n";
/*	character *p = front;						// Pointer points to front of WORD A
	character *q;								// Declare *q
	while (p != 0) {							// Iterate through nodes
		q = p->next;							// q takes value of p's next node
		delete p;								// The node before p's next node, p, is deleted
		p = q;									// Continues loop
	}
	front = 0;									// front becomes null (0)
	*/
	character *current = front;
	character *nxt;
	while (current != 0)
	{
		nxt = current->next;
		delete current;
		current = nxt;
	}
	front = 0;
}

/*********************************************************************
Function Name: operator<<
Preconditon: Nothing is printed
Postcondition: WORD A is printed
Description: Overloads the insertion operator as a friend function
			 with chaining to print WORD A
**********************************************************************/
/*ostream & operator<<(ostream & out, WORD & Org) {
	character *p;
	for (p = Org.front; p != 0; p = p->next) {
		out << p->symbol << endl;
	}
	return out;
}*/
ostream & operator<<(ostream &out, WORD &w)
{
	character *current = w.front;
	while (current != 0)
	{
		out << current->symbol;
		current = current->next;
	}
	return out;
}


/*********************************************************************
Function Name: operator=
Preconditon: Left hand side does not have value of right hand side
Postcondition: WORD on left hand side takes value of WORD from right
			   hand side
Description: Overloads the assignment operator as a member function
			 (including chaining) to take a WORD object as an argument and
			 assigns its value to A, the current object
**********************************************************************/
/*WORD & WORD::operator=(const string & rhs)
{
	front = new character;
	character *p = front;
	if (rhs.length() == 0) {
		front = 0;
		return *this;
	}
	for (int i = 0; i < rhs.length(); i++) {
		p->symbol = rhs[i];
		if (i != (rhs.length() - 1)) {
			p->next = new character;
			p = p->next;
		}
		else {
			p->next = 0;
		}
	}
	character *q = p;
	while (q->next != 0) {
		q->next = front;
	}
	return (*this);
}*/
WORD & WORD::operator=(const string &s)
{
	character *current = front;
	character *nxt;

	// get rid of the original list
	while (current != 0)
	{
		nxt = current->next;
		delete current;
		current = nxt;
	}

	// start a new list
	(*this).front = 0;
	(*this).back = 0;

	for (unsigned int i = 0; i<s.size(); i++)
	{
		(*this).add(s[i]);
	}

	return (*this);
}
/*****************************/

WORD & WORD::operator=(const WORD &w)
{
	// test if replacing the same object
	if (this == &w) { return *this; }

	// replace everything in (*This) with 
	character *current = front;
	character *nxt;

	// get rid of the original list
	while (current != 0)
	{
		nxt = current->next;
		delete current;
		current = nxt;
	}

	// make a new list
	(*this).front = 0;
	(*this).back = 0;

	current = w.front;

	while (current != 0)
	{
		(*this).add(current->symbol);
		current = current->next;
	}
	return (*this);
}
/*******/
void WORD::add(char c)
{
	// create new node
	character *add = new character;
	add->symbol = c;
	add->next = 0;

	// for the first node
	if (front == 0)
	{
		front = add;
		back = add;
		return;
	}

	// point the back node to the new node
	back->next = add;

	// define the new back node
	back = add;
}
/*********************************************************************
Function Name: operator+
Preconditon: WORD A does not have WORD B added to the back of it
Postcondition: WORD B is added to the back of WORD A
Description: Overloads operator + as a member function without chaining
			 to add WORD B to the back of WORD A
**********************************************************************/
/*WORD & WORD::operator+(WORD & word) {
	int position = (*this).Length() + 1;
	Insert(word, position);
	return (*this);
}*/

/*********************************************************************
Function Name: IsEmpty
Preconditon: None
Postcondition: Bool returns true if empty
Description: Checks to see if WORD A is empty
**********************************************************************/
bool WORD::IsEmpty() {
	return front == 0;							// Returns true if front is null
}

/*********************************************************************
Function Name: Length
Preconditon: None
Postcondition: An int of the number of nodes is returned
Description: Determines the length of the word A
**********************************************************************/
int WORD::Length() {
/*	int count = 0;							// count is initialized to 0
	character *p = front;					// Points to front
	while (p != 0) {						// Iterates through list
		count++;							// Increase counter
		p = p->next;						// Proceed to the next node
	}
	return count;							// Return int of number of nodes
	*/
	int count = 0;
	character *current = front;
	while (current != 0)
	{
		count++;
		current = current->next;
	}
	return count;
}

/*********************************************************************
Function Name: Insert
Preconditon: WORD B is not inserted
Postcondition: WORD B is inserted into WORD A at the beginning, middle, or end
Description: Inserts a copy of WORD B into WORD A at any position
**********************************************************************/
/*void WORD::Insert(WORD & word, int position) {
	if (!word.Is_Empty()) {
		character *frontB = new character;
		frontB = word.front;
		character *r = frontB;
		character *location;
		(*this).Search(location, position); //pasing Traverse a pointer to a node and the     position in the list
		if (location == 0) {
			character *t = r; //t is pointing to the begin. of the copied words list
			while (t->next != 0) {
				t = t->next;//t goes to the back 
			}
			t->next = front; //k(the back) is now the front of *this
			front = r;//front now points to r, the copy
		}
		else if (position > (*this).Length())
		{
			character *t = (*this).front;
			while (t->next != 0)
			{
				t = t->next;
			}
			back = t;
			character *p = new character;
			p = back;
		}
		else {
			character *u = r;
			while (u->next != 0) {
				u = u->next;
			}
			u->next = location->next;
			location->next = r;
		}
	}
}

void WORD::Search(character * & p, const int & position) {
	if (position <= 1) {
		p = 0;
	}
	else if (position > (*this).Length()) {
		p = back;
	}
	else {
		p = front;
		for (int i = 1; i < position - 1; i++)
		{
			p = p->next;
		}
	}
}*/

/*****************************************************************************************************
Function Name:  Remove

Preconditon:  The list is initialized.

Postcondition:  A single matched instance of word 'w' will be removed from the list.

Description:  The function checks for a match of the incoming word.  It then deletes the matching nodes.

*******************************************************************************************************/
bool WORD::Remove(WORD &w)
{
	// find the addresses to the first node of the word being removed and the address prior to that node
	character *p = 0, *prior = 0;
	(*this).Search(prior, p, w); // helper function that returns the addresses before and at the matching word.


	// the word couldn't be found
	if (p == 0)
	{
		return false;
	}

	int size = w.Length(); // this determines the amount of loops in the forloop
	character *ptwo = p; // this pointer keeps track of the letters being deleted
	character *del = p; // we'll delete this one because it'll be one behind

	for (int i = 0; i<size; i++)
	{
		// check if it's the front node being removed
		if (front == ptwo)
		{
			front = ptwo->next;
		}
		// check if it's removing the back node
		if (back == ptwo)
		{
			back = prior;
			back->next = 0;
			return false;
		}
		// move forward and delete the current node
		del = ptwo;
		ptwo = ptwo->next;
		delete del;
	}

	// link the list back together
	prior->next = ptwo;

	return true;

}
/*****************************************************************************************************
Function Name:  RemoveAll

Preconditon:  The list is initialized.

Postcondition:  Multiple matched instances of word 'w' will be removed from the list.

Description:  Keeps calling the remove function until everything is gone.

*******************************************************************************************************/
void WORD::RemoveALL(WORD &w)
{
	while (Remove(w)) {}
}

/*********************************************************************
Function Name: IsEqual
Preconditon: None
Postcondition: Bool returns true if the characters between the compared WORDs are equal,
otherwise false
Description: Returns true if two word objects are equal; otherwise false

**********************************************************************/
bool WORD::IsEqual(WORD & w) {
/*	character *p = front;			// p node holder
	character *t = Org.front;  // incoming node holder
	while (p != 0 && t != 0)
	{
		// check if they match
		if (p->symbol != t->symbol) { return false; }

		// move forward 1 node
		t = t->next;
		p = p->next;
	}
	return true;  // they must match or the loop would have returned.
	*/
	character *visitor = w.getFront();  // incoming node holder
	character *current = front;			// current node holder
	while (current != 0 && visitor != 0)
	{
		// check if they match
		if (current->symbol != visitor->symbol) { return false; }

		// move forward 1 node
		visitor = visitor->next;
		current = current->next;
	}
	return true;  // they must match or the loop would have returned.
}

/*****************************************************************************************************
Function Name:  Search

Preconditon:  The list is initialized.

Postcondition:  character addresses returned

Description:  Searches for a WORD and returns the address at the begining of the match, as well as, the prior character node

*******************************************************************************************************/
void WORD::Search(character* &prior, character* &start, WORD &item)
{
	bool match = false;
	character *possible_this;         // possible matching character of current object
	character *possible_item;         // possible matching item of the incoming word
	character *address_prior = front; // address of node before match
	character *address = front;       // address of first matching node
	int size = item.Length();

	// if the incoming word is bigger than the actual word it's looking through, it couldn't possibly match; just return 0
	if (size > (*this).Length()) { start = 0; prior = 0; return; }

	// first test:  find if the first letter matches
	while (address != back)
	{
		if (address->symbol == item.front->symbol)
		{
			possible_this = address;
			possible_item = item.front;
			// second test:  find if the rest of the letters match
			for (int i = 0; i<size; i++)
			{
				if (possible_this->symbol != possible_item->symbol) { match = false; break; }
				else { match = true; }
				possible_this = possible_this->next;
				possible_item = possible_item->next;
			}

			// if the match has remained true through all the letters, then return the addresses
			if (match)
			{
				start = address;
				prior = address_prior;
				return;
			}
		}
		address_prior = address;
		address = address->next;
	}
}

*/
