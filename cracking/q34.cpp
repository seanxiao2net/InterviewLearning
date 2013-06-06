#include <stack>
#include <iostream>

using namespace std;

void hanoi(stack<int> &src, stack<int> &dst, stack<int> &buf, int lvl)
{
	if (lvl == 1)
	{
		dst.push(src.top());
		src.pop();
		//cout<<"last step"<<endl;
		return;
	}
	hanoi(src, buf, dst, lvl-1);
	dst.push(src.top());
	src.pop();
	//cout<<"in step"<<endl;
	hanoi(buf, dst, src, lvl-1);
}

int main()
{
	stack<int> src, dst, buf;

	for (int i=0; i<10; i++)
		src.push(i);

	hanoi(src,dst,buf,src.size());

	while (!dst.empty())
	{
		int i;
		i = dst.top();
		cout<<i<<endl;
		dst.pop();
	}

	return 0;
}
