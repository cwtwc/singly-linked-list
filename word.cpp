#include <iostream>
#include <string>
#include "word.h"

using namespace std;

WORD::WORD() {
	cout << "Inside the default constructor\n";
	front = back = 0;		 // Initialize front and back nodes
}

WORD::WORD(const WORD & Org) {
	cout << "Copy Constructor Invoked" << endl;
	front = Org.front;
	back = Org.back;
	character *p = front;
	cout << endl << endl;
	while (p != 0) {
		cout << p->symbol;
		p = p->next;
	}
	cout << endl << endl;
}

WORD::WORD(string str) {
	cout << "Explicit-value constructor invoked" << endl;
	if (str.length() == 0) {
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
	}
}

WORD::~WORD()
{
	cout << "Destructor has been called\n";
	//(*this).toEmpty();
	character *p = (*this).front;
	if ((*this).Is_Empty())
	{
		cout << "Linked list is empty" << endl;
		return;
	}
	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}
}

/*void WORD::toEmpty()
{
	character *q = (*this).front;
	if ((*this).Is_Empty())
	{
		cout << "Linked list is empty" << endl;
		return;
	}
	while (front != 0)
	{
		character *q = front;
		front = front->next;
		delete q;
	}
	return;
}
*/
ostream & operator<<(ostream & out, WORD & Org) {
	character *p;
	for (p = Org.front; p != 0; p = p->next) {
		out << p->symbol << endl;
	}
	return out;
}

WORD & WORD::operator=(const string & rhs)
{
	int counter = 0;
	length = rhs.length();
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
}

WORD & WORD::operator+(WORD & word) {
	int position = (*this).Length() + 1;
	Insert(word, position);
	return (*this);
}

bool WORD::Is_Empty() {		// Checks whether linked list is empty
	return front == 0;
}

int WORD::Length() {
	count = 0;							// Initialize count to 0 
	character* p = front;
	while (p != 0) {		// Iterate throught the linked list as long as not empty
		count++;						// Increase counter
		p = p->next;					// Go to next node
	}
	return count;
}

void WORD::Insert(WORD & word, int position) {
	if (!word.Is_Empty()) {
		character *frontB = new character;
		frontB = word.front;
		character *r = frontB;
		character *location;
		(*this).Search(location, position); //pasing Traverse a pointer to a node and the     position in the list
		if (location == 0) {
			character *t = r; //t is pointing to the begin. of the copied words list
			while(t->next != 0) {
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
			while(u->next != 0) {
				u = u->next;
			}
			u->next = location->next;
			location -> next = r;
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
}

void WORD::Remove(const char & key)
{
/*	character *p = Search(key);
	if (p == 0)
	{
		cout << key << "\n" << " not in list\n";
	}
	else
	{
		if (p == front && front == back)
		{
		delete p;
		front = back = 0;
		}
		else if (p == front)
		{
			front = front->next;
			delete p;
		}
		else
		{
			character *back_ptr = front;

			while (back_ptr != 0 && back_ptr->next != p)
			{
				back_ptr = back_ptr->next;
			}
			back_ptr->next = p->next;
			delete p;
		}
	}*/
}

