#include <queue>
#include <iostream>

using namespace std;

typedef struct _node
{
	_node(int num1=0, int num2=0):x(num1),y(num2), count(0), prev_x(0), prev_y(0){}
	int x;
	int y;
	int count;
	int prev_x;
	int prev_y;
} Node;

class mazesolver
{
public:
	mazesolver(): curr(0,0), prev(0,0){}
	void solve(int m[10][10]);
	void findPath(int m[10][10]);
	void printpath(int m[10][10], int x, int y);
	void printmap(int m[10][10]);

private:
	Node curr;
	Node prev;
	queue<Node> q;
};

void mazesolver::findPath(int m[10][10])
{
	Node next;
	next.x = curr.x +1;
	next.y = curr.y;
	next.prev_x = curr.x;
	next.prev_y = curr.y;
	next.count = curr.count+1;
	if ((next.x<10)&&(m[next.y][next.x]==0)) q.push(next);
	next.x = curr.x;
	next.y = curr.y +1;
	if ((next.y<10)&&(m[next.y][next.x]==0)) q.push(next);
	next.x = curr.x -1;
	next.y = curr.y;
	if ((next.x>=0)&&(m[next.y][next.x]==0)) q.push(next);
	next.x = curr.x;
	next.y = curr.y -1;
	if ((next.y>=0)&&(m[next.y][next.x]==0)) q.push(next);
}

void mazesolver::solve(int m[10][10])
{
	//printmap(m);
	q.push(curr);
	while (((curr.x!=9)||(curr.y!=9))&&(!q.empty()))
	{
		curr = q.front();
		q.pop();
		m[curr.y][curr.x] = curr.prev_y*100+curr.prev_x*10+1000;
		//m[curr.y][curr.x] = 2;
		findPath(m);
	}
	m[curr.y][curr.x] = curr.prev_y*100+curr.prev_x*10+1000;

	cout<<"curr"<<curr.x<<curr.y<<q.empty()<<endl;

	cout<<"Find the exit"<<endl;
	//printmap(m);
	printpath(m,9,9);
}

void mazesolver::printpath(int m[10][10], int x, int y)
{
	int i,j;
	i = (m[y][x]/100)%10;
	j = (m[y][x]/10)%10;
	if (x!=0 && y!=0)
		printpath(m, j, i);
	cout<<"x: "<<x<<" y: "<<y<<endl;
}

void mazesolver::printmap(int m[10][10])
{
	int i;
	int j;
	for (i=0; i<10; i++)
	{
		for (j=0; j<10; j++)
		{
			cout<<m[i][j]<<endl;
		}
		cout<<endl;
	}

}

int main()
{
	mazesolver solver;
	int m[10][10] =
	{   {0,    1,    1,    0,    1,    1,    1,    1,    0,    1},
	    {0,    1,    0,    0,    0,    0,    1,    1,    1,    1},
	    {0,    1,    0,    0,    1,    0,    1,    1,    1,    1},
	    {0,    0,    0,    1,    1,    0,    1,    1,    1,    1},
	    {0,    1,    1,    1,    0,    0,    1,    0,    0,    1},
	    {1,    1,    1,    1,    0,    1,    1,    0,    0,    1},
	    {1,    1,    0,    1,    0,    0,    0,    0,    0,    1},
	    {1,    1,    0,    0,    1,    1,    1,    1,    0,    1},
	    {0,    1,    1,    0,    1,    1,    1,    1,    0,    1},
	    {0,    1,    1,    1,    1,    1,    1,    1,    0,    0}
	};


	//solver.printmap(m);

	solver.solve(m);

//	for(int i=0; i<10; i++)
//	{
//		for (int j=0; j<10; j++)
//		{
//			cout<<m[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	solver.printpath(m,9,9);

//	cout<<m[9][9]<<endl;

	return 0;
}
