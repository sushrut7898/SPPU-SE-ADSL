#include<iostream>
using namespace std;
class node
{
	int airport_name;
	node *next;
	public:
		friend class list;
};
class list
{
	node *gr[20];
	int visited[20],n,i;
	
	public:
		void create()
		{
			int vi,vj,no_of_cities;
			cout<<"\n\tEnter the number of cities:";
			cin>>n;
			for(i=0;i<n;i++)
			{
				gr[i]=NULL;
			}
			cout<<"\n\tEnter the no of cities which are connected:";
			cin>>no_of_cities;
			cout<<"\n\t"<<no_of_cities;
			for(i=0;i<no_of_cities;i++)
			{
				cout<<"\n\tEnter the codes of the cities which are connectes(city1,city2)";
				cin>>vi>>vj;
				insert(vi,vj);
			}
		}
		
		void insert(int vi,int vj)
		{
			node *q,*p;
			q=new node;
			q->airport_name=vj;
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
				i=p->airport_name;
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
	int ch;
	list l1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Create";
	cout<<"\n\t2.Adjancency DFS traversal";
	cout<<"\n\t3.Exit";
	cout<<"\n\tEnte your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			l1.create();
			break;
			case 2:
				l1.dfs_t();
				break;
				case 3:
					cout<<"\n\tThank You";
					break;
					default:
						cout<<"\n\tInvalid Input";
						break;
	}
}while(ch!=3);
}


