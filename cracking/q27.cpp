#include <stack>
#include <list>
#include <iostream>

using std::stack;
using std::list;
using std::cout;
using std::endl;

bool isPal(list<char> test)
{
	int len;
	stack<char> s;
	len = test.size();

	for (int i=0;i<len/2;++i)
	{
		s.push(test.front());
		test.pop_front();
	}

	if (len%2)	test.pop_front();

	while(!test.empty())
	{
		if (s.top() != test.front())	return false;
		else
		{
			s.pop();
			test.pop_front();
		}
	}
	return true;
}

int main()
{
	bool res;

	list<char> test;
	test.push_front('a');
	test.push_front('b');
	test.push_front('c');
	test.push_front('c');
	test.push_front('b');
	test.push_front('a');

	res = isPal(test);

	cout<<"result is"<<res<<endl;

	return 0;
}
