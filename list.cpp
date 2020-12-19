#include<iostream>
using namespace std;
class node
{
	node *next;
	int vertex;
	public:
	friend class list;
};
class list
{
		node *gr[40];
	int n,visited[40];
	
	public:
		void create()
		{
			int vi,vj,no_of_edges,i;
			cout<<"\n\tEnter the number of vertices";
			cin>>n;
			for(i=0;i<n;i++)
			{
				gr[i]=NULL;
			}
			cout<<"\n\tEnter the number of edges";
			cin>>no_of_edges;
			for(i=0;i<no_of_edges;i++)
			{
				cout<<"\n\tEnter an edge";
				cin>>vi>>vj;
				insert(vi,vj);
			}
		}
		
		void insert(int vi,int vj)
		{
			node *p,*q;
			q=new node;
			q->vertex=vj;
			q->next=NULL;
			
			if(gr[vi]==NULL)
			{
				gr[vi]=q;
			}
			
			else
			{
				p=gr[vi];
				while(p->next!=NULL)
				{
					p=p->next;
				}
					p->next=q;
			}
		}
		
		void dfs(int i)
		{
			node *p;
			cout<<"\n\tVisit:";
			cout<<"\n"<<i;
			p=gr[i];
			visited[i]=1;
			while(p!=NULL)
			{
				i=p->vertex;
				if(!visited[i])
				{
				dfs(i);
			}
				p=p->next;
			}
			}
		void dfs_t()
		{
		int i;	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	
	dfs(0);
		}
};

int main()
{
	list l1;
	l1.create();
	l1.dfs_t();

	
}
