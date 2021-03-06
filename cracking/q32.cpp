#include <iostream>
#include <stack>

using namespace std;

class istack
{
public:
istack(){}
void push(int val);
int pop();
int min();

private:
stack<int> mys;
stack<int> mins;

};

void istack::push(int val)
{
	mys.push(val);

	if ((mins.size()==0)||(val<=mins.top()))
		mins.push(val);
}

int istack::pop()
{
	int ret;

	ret = mys.top();
	mys.pop();

	if (mins.top() >=ret )
	mins.pop();

	return ret;
}

int istack::min()
{
	return mins.top();
}

int main()
{
	istack s;

	s.push(3);
	s.push(6);
	s.push(8);
	s.push(2);
	s.push(4);
	s.push(5);
	s.push(1);
	s.push(6);

	cout<<s.min()<<endl;
	s.pop();
	cout<<s.min()<<endl;
	s.pop();
	cout<<s.min()<<endl;
	s.pop();
	cout<<s.min()<<endl;
	s.pop();
	cout<<s.min()<<endl;
	s.pop();
	cout<<s.min()<<endl;
	s.pop();
	cout<<s.min()<<endl;
	s.pop();



	return 0;
}
