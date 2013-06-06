#include <stack>
#include <iostream>

using namespace std;

class myQ
{
public:
	myQ(){}
	void enqueue(int val);
	int peek();
	void pop();
	int size();

private:
	stack<int> in,out;
};

void myQ::enqueue(int val)
{
	while (!out.empty())
	{
		in.push(out.top());
		out.pop();
	}

	in.push(val);
}

int myQ::size()
{
	return in.size()+out.size();
}

int myQ::peek()
{
	if (size() == 0)	return 0;
	while (!in.empty())
	{
		out.push(in.top());
		in.pop();
	}

	return out.top();
}

void myQ::pop()
{
	if (size() == 0)	return;
	while (!in.empty())
	{
		out.push(in.top());
		in.pop();
	}

	out.pop();
}

int main()
{
	myQ q;
	int res;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	res = q.peek();
	cout<<res<<endl;
	q.pop();

	res = q.peek();
	cout<<res<<endl;
	q.pop();

	res = q.peek();
	cout<<res<<endl;
	q.pop();

	res = q.peek();
	cout<<res<<endl;
	q.pop();

	res = q.peek();
	cout<<res<<endl;
	q.pop();


	return 0;
}
