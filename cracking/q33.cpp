#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStacks
{

public:
	SetOfStacks(){}
	~SetOfStacks(){}
	void push(int val);
	int pop();
	int popAt(unsigned int stacknum);

private:
	vector<stack<int>*> mystacks;
	static const unsigned int maxsz = 10;
};

void SetOfStacks::push(int val)
{
	if((mystacks.size() == 0)||(mystacks.back()->size()>=maxsz))
	{
		mystacks.push_back(new stack<int>);
	}

	stack<int>* curr;
	curr = mystacks.back();

	curr->push(val);
}

int SetOfStacks::pop()
{
	if((mystacks.size() == 0))
	{
		return 0;
	}

	stack<int>* curr;
	int ret;
	curr = mystacks.back();

	ret = curr->top();
	curr->pop();

	if (curr->size() == 0)
	{
		delete curr;
		mystacks.pop_back();
	}

	return ret;
}

int SetOfStacks::popAt(unsigned int stacknum)
{
	if (stacknum > mystacks.size())	return 0;

	stack<int> *curr;
	int ret;

	curr = mystacks[stacknum];

	ret = curr->top();
	curr->pop();

	if (curr->size() == 0)
	{
		delete curr;
		mystacks.erase(mystacks.begin()+stacknum);
	}

	return ret;
}

int main()
{
	SetOfStacks s;
	int res;
	for (int i=0; i<50; ++i)
		s.push(i);

	for (int i=0; i<50; ++i)
	{
		res = s.pop();
		cout<<res<<endl;
	}

	for (int i=0; i<50; ++i)
		s.push(i);

	res = s.popAt(3);
	cout<<res<<endl;

	res = s.popAt(3);
	cout<<res<<endl;

	res = s.popAt(2);
	cout<<res<<endl;

	res = s.popAt(2);
	cout<<res<<endl;

	for (int i=0; i<50; ++i)
	{
		res = s.pop();
		cout<<res<<endl;
	}
	
	return 0;
}
