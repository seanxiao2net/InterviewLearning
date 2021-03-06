#include <iostream>
using namespace std;

class istack
{
public:
	istack(){ptr[0]=0;ptr[1]=100;ptr[2]=200;}
	void push(int val, int stack);
	int pop(int stack);

private:
	int buff[300];
	int ptr[3];
	static const int sz = 100;
};

void istack::push(int val, int stacknum)
{
	if ((stacknum>2)||(stacknum < 0)) return;

	if (ptr[stacknum]>=(stacknum+1)*100) return;

	buff[ptr[stacknum]] = val;
	++ptr[stacknum];
}

int istack::pop(int stacknum)
{
	if ((stacknum>2)||(stacknum < 0)) return 0;

	if (ptr[stacknum]<=100*stacknum)	return 0;

	return buff[--ptr[stacknum]];
}


int main()
{
	istack s;
	int result;

	s.push(3,1);
	s.push(4,2);
	s.push(5,0);
	s.push(6,2);
	s.push(2,1);
	s.push(1,1);

	result = s.pop(1);
	cout<<"result is "<<result<<endl;
	result = s.pop(1);
	cout<<"result is "<<result<<endl;
	result = s.pop(1);
	cout<<"result is "<<result<<endl;
	result = s.pop(2);
	cout<<"result is "<<result<<endl;
	result = s.pop(0);
	cout<<"result is "<<result<<endl;
	result = s.pop(2);
	cout<<"result is "<<result<<endl;
	return 0;
}
