#include <cstdlib>
#include <string>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

class ActorNode
{
public:
	ActorNode():lvl(-1), prev(NULL){}
	ActorNode(const char name[]): actorname(name), lvl(-1), prev(NULL){}
	void AddEdge(ActorNode* friends);
	void PrintFriends();
	void FindFriend(const ActorNode* friends);
	void unsetNumber();
	void BackTracking(string& str);

private:
	string actorname;
	set<ActorNode*> LinkedActors;
	set<ActorNode*>::iterator it;
	int lvl;
	ActorNode* prev;
};

void ActorNode::AddEdge(ActorNode* friends)
{
	LinkedActors.insert(friends);
	friends->LinkedActors.insert(this);
}

void ActorNode::PrintFriends()
{
	for (it = LinkedActors.begin(); it!= LinkedActors.end(); ++it)
	{
		cout<<(*it)->actorname<<endl;
	}
	cout<<"Current lvl"<<lvl<<endl;

}

void ActorNode::FindFriend(const ActorNode* friends)
{
	queue<ActorNode*> q;
	ActorNode* curr;

	lvl = 0;
	q.push(this);

	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (curr == friends)
		{
			cout<<"you have "<<curr->lvl<<" degree connection"<<endl;
			return;
		}

		for (it = curr->LinkedActors.begin(); it != curr->LinkedActors.end(); it++)
		{
			if ((*it)->lvl == -1)
			{
				(*it)->lvl = curr->lvl +1;
				(*it)->prev = curr;
				q.push(*it);

				//cout<< (*it)->actorname<< " "<< (*it)->lvl <<endl;
			}
		}
		
	}

}

void ActorNode::unsetNumber()
{
	if(lvl != -1)
	{
		lvl = -1;
		for (it = LinkedActors.begin(); it!=LinkedActors.end(); it++)
		{
			(*it)->unsetNumber();
			(*it)->prev = NULL;
		}
	}
}

void ActorNode::BackTracking(string& str)
{
	str.insert(0, actorname+", ");
	if (prev!= NULL)
		prev->BackTracking(str);
}

int main()
{
	ActorNode actors[20];
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

	actors[0].AddEdge(&actors[1]);
	actors[0].AddEdge(&actors[2]);
	actors[1].AddEdge(&actors[2]);
	actors[1].AddEdge(&actors[3]);
	actors[1].AddEdge(&actors[4]);
	actors[1].AddEdge(&actors[5]);
	actors[0].AddEdge(&actors[6]);
	actors[4].AddEdge(&actors[7]);
	actors[8].AddEdge(&actors[3]);
	actors[9].AddEdge(&actors[7]);

	//actors[0].PrintFriends();

	actors[0].FindFriend(&actors[9]);

	string track;

	actors[9].BackTracking(track);

	cout<< track<< endl;

	actors[0].unsetNumber();

//	for (int i=0; i<10; i++)
//		actors[i].PrintFriends();


//	actors[1].FindFriend(&actors[9]);


	return 0;
}
