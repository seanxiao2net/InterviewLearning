#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class NameList
{
	//Here everyone can access
	public:
	NameList(const string& str, int number);

	NameList(const string& str);
	
	void show(void);

	NameList& operator=(const NameList &rhs);
		

	//only children can access
	protected:
	string name;
	int _size;

	void init(const string& str, int number);
	
	//private memebers, only itself can access
	private:
};

void NameList::init(const string& str, int number)
{
	name = str;
	_size = number;
	std::cout << "str is copied "<< name << std::endl;
}


NameList::NameList(const string& str, int number)
{
	init(str, number);
}

NameList::NameList(const string& str = "buhao")
{
	init(str, 0);
}


NameList& NameList::operator=(const NameList &rhs)
{
	NameList result;
	cout << "copying "<< endl;
	this->name = (this->name + rhs.name);
	this->_size = rhs._size;
	return *this;
}

void NameList::show()
{
	std::cout << "Number includede "<< _size << std::endl;
	cout << "names: "<<name << endl;
}



int main()
{
	string x = "hello1";
	string y = "henhao";
	//int y = 1;
	NameList namelist(x,1);
	NameList namelist2(x);
	NameList namelist3;
	namelist.show();
	namelist3.show();
	namelist3 = namelist;
	namelist.show();

	namelist3.show();
return 0;
}
