#include <stack>
#include <iostream>

using namespace std;

void Sort(stack<int> &src)
{
	stack<int> buf;
	int pick;

	while (!src.empty())
	{
		pick = src.top();
		src.pop();

		while ((!buf.empty())&&(buf.top() > pick))
		{
			src.push(buf.top());
			buf.pop();
		}

		buf.push(pick);
	}

	while (!buf.empty())
	{
		src.push(buf.top());
		buf.pop();
	}
}


int main()
{
	stack<int> src;

	src.push(3);
	src.push(2);
	src.push(4);
	src.push(9);
	src.push(5);
	src.push(1);

	Sort(src);

	while (!src.empty())
	{
		cout<<src.top()<<endl;
		src.pop();
	}

	return 0;
}
