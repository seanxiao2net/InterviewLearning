#include <iostream>

#define INF	9999

using namespace std;

template <int dim>
class Node
{
public:
Node();
void SetDist(int from, int to, int dist) {adjdist[from][to] = dist;}
void CalcDist(int from, int dist[]);

private:
int adjdist[dim][dim];

};

template <int dim>
Node<dim>::Node()
{
	for (int i=0; i<dim; i++)
		for(int j=0; j<dim; j++)
			adjdist[i][j]=INF;
}

template <int dim>
void Node<dim>::CalcDist(int from, int dist[])
{
	bool visited[dim];

	for(int i =0; i<dim; i++)
	{
		dist[i] = adjdist[from][i];
		visited[i] = false;
	}

	dist[from]=0;
	visited[from]=true;

	for (int i=0; i<dim; i++)
	{
		int min = INF;
		int token;

		for (int j=0; j<dim; j++)		//Find reachale unvisited node
		{
			if ((dist[j]<min)&&(!visited[j]))
			{
				token = j;
				min = dist[j];
				
			}
		}

		visited[token]=true;
		for (int j=0; j<dim; j++)
		{
			if (min + adjdist[token][j]<dist[j])
				dist[j]=min + adjdist[token][j];
		}
	}
}

int main()
{
	Node<5> dg;
	int result[5];
	dg.SetDist(0,1,5);
	dg.SetDist(0,2,3);
	dg.SetDist(0,4,2);
	dg.SetDist(1,2,2);
	dg.SetDist(1,3,6);
	dg.SetDist(2,3,2);
	dg.SetDist(2,1,1);
	dg.SetDist(4,1,6);
	dg.SetDist(4,2,10);
	dg.SetDist(4,3,4);

	dg.CalcDist(0, result);

	for (int i=0; i<5; i++)
		cout<<result[i]<<endl;

}
