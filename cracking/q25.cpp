#include <list>
#include <iostream>

using namespace std;

void padlist(list<int> &l1, int num)
{
	for (int i=0;i<num;++i)
		l1.push_front(0);
}

void addlist_do(list<int> &l1, list<int> &l2, list<int> &sum)
{
	int num1,num2,val;
	static int carry = 0;

	if(l1.empty()||l2.empty())	
	{
		carry = 0;
		return;
	}
	
	num1 = l1.front();
	num2 = l2.front();
	l1.pop_front(), l2.pop_front();

	addlist_do(l1,l2,sum);

	val = num1+num2+carry;
	sum.push_front(val%10);
	l1.push_front(num1);
	l2.push_front(num2);
	carry = val/10;;
}

void addlist(list<int> &l1, list<int> &l2, list<int> &sum)
{
	int len1,len2;

	len1 = l1.size();
	len2 = l2.size();
	
	if (len1 < len2)	padlist(l1, len2-len1);
	else if (len1 > len2)	padlist(l2, len1-len2);

	addlist_do(l1,l2,sum);
}

int main()
{
	list<int> l1,l2,res;

	list<int>::iterator it;

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l2.push_back(5);
	l2.push_back(6);
	l2.push_back(7);

	addlist(l1,l2,res);

	for (it = l1.begin(); it!=l1.end(); ++it)
		cout<<*it;
	cout<<endl;
	for (it = l2.begin(); it!=l2.end(); ++it)
		cout<<*it;
	cout<<endl;

	for (it = res.begin(); it!=res.end(); ++it)
		cout<<*it;
	cout<<endl;

	return 0;
}
