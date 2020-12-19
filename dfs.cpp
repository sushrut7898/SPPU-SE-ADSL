#include<iostream>
using namespace std;
class graph
{
	int gr[10][10],visited[10],cost,n;
	public:
	graph()
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				gr[i][j]=0;
			}
		}
	}
	
	void create()
{
		int flag=0;
		int l,m;
		int count=1;
		cout<<"\n\tEnter the number of connections?";
		cin>>n;
		do
		{
		cout<<"\n\tEnter the code of the starting city";
		cin>>l;
		cout<<"\n\tEnter the code of the destination city";
		cin>>m;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==l && j==m)
				{
					flag=1;
					gr[i][j]=1;
					
				}
				else
				{
					flag=0;
				}
			}
		}
		count++;
	    }while(count<=n);
}
	
	
	void display()
	{
		cout<<"\n\tThe Connection of the cities is:";
		for(int i=0;i<n;i++)
		{
			cout<<endl;
			for(int j=0;j<n;j++)
			{
				cout<<"\t"<<gr[i][j];
			}
		}
    }
		
		void dfs(int i)
	{
		int j;
		cout<<"\n\tThe DFS traversal is:";
		cout<<"\n"<<i;
		visited[i]=1;
		for(int j=0;j<n;j++)
		{
			if(!visited[j] && gr[i][j]==1)
			{
				dfs(j);
			}
		}
	}
	
	   void dfs_traversal()
	   {
	   	 for(int i=0;i<n;i++)
	   	 {
	   	   visited[i]=0;	
		 }
		 dfs(0);
	   }
};
	  

int main()
{
	int ch;
	graph g1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Create";
	cout<<"\n\t2.Display";
	cout<<"\n\t3.DFS traversal";
	cout<<"\n\t4.Exit";
	cout<<"\n\tEnter your choice";
	cin>>ch;
	switch (ch)
	{
		case 1:
			g1.create();
			break;
			case 2:
				g1.display();
				break;
				case 3:
				g1.dfs_traversal();
				break;
				case 4:
				 cout<<"\n\tThank You";
				 break;
					default:
						cout<<"\n\tInvlid Input";
	}
}while(ch!=4);
}
