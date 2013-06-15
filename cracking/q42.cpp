#include <iostream>
#include <queue>
#include <set>

using namespace std;

class Nodes
{
public:
Nodes():visited(false){}
void AddNeighbor(Nodes* name) {neighbor.insert(name);}
bool isRelated(Nodes* name);
bool isVisited(){return visited;}
void Mark(){visited = true;}
private:
bool visited;
set<Nodes*> neighbor;
};

bool Nodes::isRelated(Nodes* name)
{
	set<Nodes*>::iterator it;

	for(it = neighbor.begin(); it != neighbor.end(); ++it)
	{
		bool ret;
		if (*it == name) return true;
		ret = (*it)->isRelated(name);
		if (ret == true) return true;

	}

	return false;
}

//bool Nodes::isRelated(Nodes* name)
//{
//	queue<Nodes*> q;
//	q.push(this);

//	while (!q.empty())
//	{
//		Nodes* curr;
//		curr = q.front();
//		q.pop();
//		curr->Mark();
//		
//		if (curr == name) return true;

//		set<Nodes*>::iterator it;
//		for (it = curr->neighbor.begin(); it!=curr->neighbor.end(); it++)
//		{
//			if(!(*it)->isVisited()) q.push(*it);
//		}
//	}

//	return false;
//}

int main()
{
	Nodes big[5];

	big[0].AddNeighbor(&big[1]);
	big[0].AddNeighbor(&big[2]);
	big[0].AddNeighbor(&big[4]);
	big[2].AddNeighbor(&big[3]);

	cout<<"result is "<<big[0].isRelated(&big[3])<<endl;


	return 0;
}
