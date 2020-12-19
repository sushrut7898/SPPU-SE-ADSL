#include<iostream>
using namespace std;
#define infinity 9999;

class Node
{
	friend class Graph;
	int data, weight;
	Node* next;
};

class Graph
{
	Node* g[20];
	int visited[20], dist[20], from[20];
	int n, e;
	
public:
	Graph()
	{
		for (int i = 0; i < 20; ++i)
		{
			g[i] = NULL;
			visited[i] = from[i] = 0;
			dist[i] = infinity;
		}
	}
	void ReadGraph();
	void Insert(int, int, int);
	void Display();
	void Prims(Graph *);
};

void Graph :: Prims(Graph *gs)
{
	gs->n = n;
	dist[0] = 0;
	visited[0] = 1;
	Node* q = g[0];
	while(q!=NULL)
	{
		dist[q->data] = q->weight;
		q = q->next;
	}

	int u, v;
	int mind, minc = 0;
	int no_edges = n-1;
	while(no_edges--)
	{
		mind = infinity;
		for (int i = 1; i < n; ++i)
		{
			if(visited[i] == 0 && dist[i] < mind)
			{
				v = i;
				mind = dist[i];
			}
		}
		u = from[v];

		gs->insert(u, v, mind);
		gs->insert(v, u, mind);

		visited[v] = 1;
		q = g[v];
		while(q!=NULL)
		{
			if(visited[q->data] == 0 && q->weight < dist[q->data])
			dist[q->data] = q->weight;
			q =q->next;
		}

		minc = minc + mind;
	}
	cout<<"\nSpanning Tree Cost: "<<minc<<endl;
}

void Graph :: Display()
{
	for (int i = 0; i < n; ++i)
	{
		node* q = g[i];	
		cout<<i;
		while(q!=NULL)
		{
			cout<<" --> ";
			cout<<q->data<<"("<<q->weight<<")"; 
			q= q->next;
		}
		cout<<endl;
	}
}

void Graph :: Insert(int vi, int vj, int w)
{
	Node* newnode = new Node, *current;
	current->data = vj;
	current->weight = w;
	current->next = NULL;
	
	if (g[vi]==NULL)
		g[vi] = newnode;
	else
	{
		current = g[vi];
		while(current->next != NULL)
			current = current->next;
		current->next = newnode;
	}
}

void Graph :: ReadGraph()
{
	int vi, vj, w;
	cout<<"\nEnter Number of Vertices: ";
	cin>>n;
	cout<<"\nEnter Number of Edges: ";
	cin>>e;
	cout<<"\nEnter Edges";
	for (int i = 0; i < e; ++i)
	{
		cin>>vi>>vj>>w;
		insert(vi, vj, w);
		insert(vj, vi, w);
	}
}

int main()
{
	int k;
	Graph b;
	b.ReadGraph();

	b.Display();

	Graph span;
	b.Prims(&span);
	return 0;
}
