#include <string>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
Node(): lvl(-1){}
Node(const char name[]): actor(name), lvl(-1){}
void AddFriend(Node* name) {friends.insert(name); name->friends.insert(this);}
void Print();
void FindConn(Node* name);

private:
string actor;
set<Node*> friends;
set<Node*>::iterator it;
int lvl;
};

void Node::Print()
{
	cout<<"Friend list of "<< actor<<endl;
	for (it = friends.begin(); it!=friends.end(); ++it)
	{
		cout<< (*it)->actor<< endl;
	}
}

void Node::FindConn(Node* name)	//breadth first search
{
	queue<Node*> q;
	Node* curr;
	q.push(this);
	lvl = 0;

	while(!q.empty())
	{
		curr = q.front();
		q.pop();

		if ( curr == name)
		{
			cout<<"you have "<<curr->lvl<<"lvl connection"<<endl;
			return;
		}

		for (it = curr->friends.begin(); it != curr->friends.end(); it++)
		{
			if ((*it)->lvl == -1)
			{
				q.push(*it);
				(*it)->lvl=curr->lvl+1;
			}
		}
	}

}

int main()
{
	Node actors[10];

	actors[0] = "Han Xiao";
	actors[1] = "peter";
	actors[2] = "Louisa";
	actors[3] = "Tao Bo";
	actors[4] = "Royer";
	actors[5] = "Wang Hui";
	actors[6] = "DanDan";
	actors[7] = "Lily Wang";
	actors[8] = "Tao yizhou";
	actors[9] = "Lily teacher";

	actors[0].AddFriend(&actors[1]);
	actors[0].AddFriend(&actors[2]);
	actors[1].AddFriend(&actors[2]);
	actors[1].AddFriend(&actors[3]);
	actors[1].AddFriend(&actors[4]);
	actors[1].AddFriend(&actors[5]);
	actors[0].AddFriend(&actors[6]);
	actors[4].AddFriend(&actors[7]);
	actors[8].AddFriend(&actors[3]);
	actors[9].AddFriend(&actors[7]);

	actors[0].FindConn(&actors[9]);

//	actors[0].Print();

	return 0;
}
