#include <stdlib.h>
#include <iostream>
#include "word.h"

using namespace std;

//Example of what to test ONLY.  Use at you own risk...


int main()
{
	cout<<"Test 10: Default Constructor\n";
	WORD you;
	cout<<"Testing the default constructor and printing empty word\n";
	cout<<you<<endl;

	cout<<"Test 11: Explicit-value Constructor\n";
	WORD me("123abc345abc129012");
	cout<<"Testing the explicit-value constructor\n";
	cout<<me<<endl;
	
	/*cout<<"Test 12: Copy Constructor\n";
	WORD them = me;
	cout<<"Testing the copy constructor\n";
	cout<< them <<" = "<< me << endl;
	*/
	/*cout<<"Test 2: Length\n";
	cout<<"Testing length\n";
	cout<<"The length of me is "<<me.Length()<<endl;
	cout<<"The length of them is "<<them.Length()<<endl;
	cout<<"The length of you is "<<you.Length()<<endl;*/

/*	cout<<"Test 3a: Insert\n";
	WORD them("XXXXXXXXX");
	WORD you("12345");
	cout<<you<<endl;
	cout<<"Testing Insert by inserting me into you at position 0\n";
	cout<<them<<endl;
	you.Insert(them,1);
	cout<<"The word you is "<<you<<endl;

	cout<<"Test 3b: Insert\n";
	you.Insert(me,5);
	cout<<"hello"<<endl<<you<<endl;*/


/*	cout<<"Test 7: operator=\n";
	WORD us;
	us = "abc";
	cout<<"Testing operator= by assignment the value of \"abc\" to use\n";
	cout<<us;

	cout<<"Test 8: operator=\n";
	WORD word1, word2, word3;
	word1 = "ABC123XYZ";
	cout<<"Testing overloaded operator= with chaining by assignment the value of \"ABC123XYZ\" to use\n";
	word3=word2=word1;
	cout<<"word3 is "<<word3<<", word2 is "<<word2<<" and word1 is "<<word1<<endl;
	cout<<"Testing overloaded operator= with chaining by assignment the value of word1, \"ABC123XYZ\", into itself \n";
	word1 = word1 = word1;
	cout<<"word1 is "<<word1<<endl;

	cout<<"Test 9: operator+\n";
	cout << "Testing operator+ without chaining";
	word3 + word2;
	cout<<word3<<endl*/

	////cout<<"Test 4: Remove\n";
	//us = "";
	//us = "12";
	//cout<<us<<endl;
	////them.Remove(us);
	//you.Remove(us);
	//cout<<you<<endl;

	//cout<<them<<endl;
	//cout<<"Testing Remove by removing us from them \n";
	//cout<<"The word them is "<<them<<endl;

	//cout<<"Test 5: RemoveAll\n";
	//me.RemoveALL(us);
	//cout<<"Testing RemoveAll by removing all occurrences of us in me \n";
	//cout<<"The word me is "<<me<<endl;

	//WORD our, him;

	//our = "XXXCCCYYY";
	//us = "XXXX";

	//cout<<"Test 14: IsEqual\n";
	//cout<<"Testing IsEqual by testing to see inf us is equal to our \n";
	//if (our.IsEqual(us))
	//	cout<<"The 2 words are equal\n";
	//else
	//	cout<<"The 2 words are not equal\n";


	system("pause");
	return 0;
}
