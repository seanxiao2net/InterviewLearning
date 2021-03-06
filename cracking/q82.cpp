#include <string>
#include <list>
using std::string;
using std::list;

class Employee {
public:
virtual ~Employee(){}
bool isAvaliable() {return Avaliable;}
void setAvaliable() {Avaliable = true;}
void unAvaliable() {Avaliable = false;}
int Rank() {return rank;}
void setRank(int val) {rank = val;}

protected:
Employee(const char* str, int r): name(str), Avaliable(true), rank(r){}
string name;
bool Avaliable;
int rank;
};

class respondent: public Employee {
public:
respondent(const char* str): Employee(str, 0){}
virtual ~respondent(){}
};

class manager: public Employee {
public:
manager(const char* str): Employee(str, 1){}
virtual ~manager(){}
};

class director: public Employee {
public:
director(const char* str): Employee(str, 2){}
virtual ~director(){}
};

class call
{
public:
call():rank(0), receiver(NULL){}
void SetAnswerer(Employee* ans){receiver = ans;}
int getRank() {return rank;}
void increaseRank() {++rank;}

private:
int rank;
Employee* receiver;
};


class CallCenter
{
private:
	list<call> calllist;
	static const int lvls = 3;
	list<Employee*> responders[lvls];
public:
	CallCenter();
	void employeeCheckin(Employee* name);
	void employeeCheckout(Employee* name);
	void dispatchCall(call& c);
	void callcheckin(call& c) {calllist.push_front(c);dispatchCall(c);}
	void callcheckout(call& c);//delete in calllist, free the answerer
	void forward(call& c) {c.increaseRank(); dispatchCall(c);}
};

void CallCenter::dispatchCall(call& c)
{
	list<Employee*>::iterator it;
	int callrank= (c.getRank() < lvls) ? c.getRank() : lvls-1;
	for (it=responders[callrank].begin(); it!=responders[callrank].end(); ++it)
	{
		if ((*it)->isAvaliable())
		{
			c.SetAnswerer(*it);
			(*it)->unAvaliable();
		}
	}
}

int main()
{

	return 0;
}
