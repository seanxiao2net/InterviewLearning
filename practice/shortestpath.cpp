#include <cstdlib>
#include <iostream>
#define infiniti	9999

template <int graphsize>
class Digraph
{
public:
Digraph() :count(graphsize){clear();}
void clear();
void NodeConf(int src, int dst, int dist) { adjdist[src][dst] = dist;}
void setDist(int src, int dist[]);
void PrintDist();

private:
int adjdist[graphsize][graphsize];
int count;
};

template <int graphsize>
void Digraph<graphsize>::clear()
{
	int i,j;
	for (i=0;i<graphsize;i++)
	{
		for (j=0;j<graphsize;j++)
		{
			adjdist[i][j] = infiniti;
		}
	}

	return;
}

template <int graphsize>
void Digraph<graphsize>::PrintDist()
{
	int i,j;
	for (i=0; i<graphsize; i++)
	{
		for (j=0; j<graphsize; j++)
		{
			std::cout<<adjdist[i][j]<<' ';
		}
		std::cout<< std::endl;
	}
}

template <int graphsize>
void Digraph<graphsize>::setDist(int src, int dist[])
{
	bool visited[graphsize];
	int token;

	for (int i=0; i<graphsize; i++)
	{
		visited[i]=false;
		dist[i]=adjdist[src][i];
	}
	dist[src]=0;
	visited[src]=true;

	for (int i=0; i<graphsize; i++)		//go through all the nodes
	{
		int min = infiniti;
		for(int j=0; j<graphsize; j++)
		{
			if((!visited[j])&&(dist[j]<infiniti))	//if not visited and can be reached
			{
				min = dist[j];
				token = j;
			}
		}

		visited[token]=true;
		for(int j=0; j<graphsize;j++)
		{
			if(min+adjdist[token][j]<dist[j])
				dist[j] = min+adjdist[token][j];
		}
	}
}



int main()
{
	int dist[5];
	Digraph<5> dg;
	dg.NodeConf(0,1,5);
	dg.NodeConf(0,2,3);
	dg.NodeConf(0,4,2);
	dg.NodeConf(1,2,2);
	dg.NodeConf(1,3,6);
	dg.NodeConf(2,3,2);
	dg.NodeConf(2,1,1);
	dg.NodeConf(4,1,6);
	dg.NodeConf(4,2,10);
	dg.NodeConf(4,3,4);

	dg.PrintDist();

	dg.setDist(0,dist);

	for (int i=0; i<5; i++)
		std::cout<<dist[i]<<std::endl;

	return 0;
}
