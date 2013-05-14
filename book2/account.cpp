#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Account{
public:
inline Account();
inline Account(const char*, double=0.0);
inline Account(const string&, double=0.0);
inline Account(const Account&);
inline void print();
~Account();

private:
inline int GetNewAcctNum(void);
//char* _name;
string _name;
unsigned int _acct_num;
double _balance;
static unsigned int _new_acct_number;
};

unsigned int Account::_new_acct_number = 0;

int Account::GetNewAcctNum(void)
{
	return _new_acct_number++;

}

Account::Account()
	: _balance(0.0)
{
	_acct_num = GetNewAcctNum();
}

Account::Account(const char* name, double saving)
	: _name(name), _balance(saving)
{
	//if (strlen(name)==0)
	//	return;

	//_name = new char[strlen(name)];
	//strcpy(_name,name);
	//_name = name;
	//_balance = saving;
	_acct_num = GetNewAcctNum();
}

Account::Account(const string &name, double saving)
	: _name(name), _balance(saving)
{
	//if (name.size() == 0)
	//	return;

	//_name = name;
	//_balance = saving;
	_acct_num = GetNewAcctNum();

}

Account::Account(const Account& rhs)
	: _name(rhs._name)
{
	//_name = new char[strlen(rhs._name)];
	//strcpy(_name,rhs._name);
	//_name = rhs._name;
	_balance = rhs._balance;
	_acct_num = GetNewAcctNum();	
}

Account::~Account()
{
	//delete [] _name;
}

void Account::print()
{
	//printf("Account holder: %s\nAccount NO: %d\nAmount: %f\n",_name,_acct_num,balance);
	cout<<"Account holder "<<_name<<endl
	<<"account NO: "<<_acct_num<<endl
	<<"Account balance "<<_balance<<endl;

}

int main()
{
	Account han("hanxiao",300);
	han.print();
	Account dandan("dan dan",200);
	dandan.print();
	Account zera = han;
	zera.print();
	Account suc = "unknow";
	suc.print();

	return 0;
}
