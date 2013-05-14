#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
Person():_name("nihao"),_address("idk"){}
Person(const string &n, const string &a) :_name(n), _address(a){}
string name() {return _name;}
string address() {return _address;}

private:
string _name;
string _address;
};

int main()
{
	Person sb;
	Person Han("Han","10067 157A ST");
	Person *ptr = malloc (sizeof(Person));

	//ptr->Person();

	//Han.Person("han","10067 157A ST");
	cout<<Han.name()<<endl;
	cout<<Han.address()<<endl;
	cout<<sb.name()<<endl;
	cout<<ptr->name()<<endl;

	return 0;
}
