#include "Folder.h"
#include <string>
using std::string;

int main()
{
	string s1("contents1");
	string s2("contents2");
	string s3("contents3");
	string s4("contents4");
	string s5("contents5");
	string s6("contents6");
	
	// all new messages, no copies yet
	Message m1(s1);
	Message m2(s2);
	Message m3(s3);
	Message m4(s4);
	Message m5(s5);
	Message m6(s6);

	Folder f1;   // use to make point it is not Folder f1() that declare
	Folder f2;   // a function returning a Folder!

	m1.save(f1); m3.save(f1); m5.save(f1);
	m1.save(f2);
	m2.save(f2); m4.save(f2); m6.save(f2);
	
	m1.debug_print();
	f2.debug_print();

	// create some copies
	Message c1(m1);
	Message c2(m2), c4(m4), c6(m6);
	
	m1.debug_print();
	f2.debug_print();

	// now some assignments
	m2 = m3;
	m4 = m5;
	m6 = m3;
	m1 = m5;

	m1.debug_print();
	f2.debug_print();

	// finally, self-assignment
	m2 = m2;
	m1 = m1;

	m1.debug_print();
	f2.debug_print();

	return 0;
}
