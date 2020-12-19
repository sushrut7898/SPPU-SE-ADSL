#include<iostream>
using namespace std;
class graph
{
	int gr[10][10],n,v;
	int visted[10];
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
			int cost;
			int flag=0;
			int count=0;
			int temp,min,l,m,k,i,j,x,y;
			int sum=0,visited[10];
		  
		    cout<<"\n\tHow Many Verttices?";
		    cin>>v;
			cout<<"\n\tEnter how many lines you want to create?";
			cin>>n;
			do
			{
			
			if((n+1)<v)
			{
				cout<<"Gand mara bc"<<endl;
				break;
			}
				cout<<"\n\tEnter the first connect:";
			     cin>>l;
			     cout<<"\n\tEnter the second connect:";
				 cin>>m;
			     cout<<"\n\tEnter the cost of the connection:";
			     cin>>cost;
			for(int i=0;i<v;i++)
			{
			  for(int j=0;j<v;j++)
			  {
			     if(i==l && j==m)
				 {
				 	flag=1; 
				 	gr[i][j]=cost;
				 	gr[j][i]=cost;
				 }	
				else
				{
					flag=0;
				}
			  }
			}
			count++;			
		}while(count<n);
	}
		
		void min_cost()
		{
			int temp,min,k,i,j,x,y;
			int sum=0;
			int visited[10];
			 for(int i=0;i<v;i++)
		   {
		   	visited[i]=0;  //Initialization of the visited Array.
		   }
		    visited[0]=1;
		   for(int pass=1;pass<v;pass++)
		   {
		   	   min=9999;
		   	   for(int i=0;i<v;i++)
		   	   {	
					if(visited[i]==1)
					{																			
		   	       //  temp=9999;
						for(int j=0;j<v;j++)
						{
							if(visited[j]==0)
							{
								if(gr[i][j]!=0)
								{	
							    	if(min>gr[i][j])
								    {
								    	min=gr[i][j];
								    	x=i;
								        y=j;
									}
								}		
						 	}	
						}
			   		}
				}
				visited[x]=visited[y]=1;
				sum=sum+min;
				cout<<"\tMIN="<<min;
        	}
        	cout<<"\n\tThe Minimum cost is:"<<sum;
		}

		void display()
		{
			cout<<"\n\tThe Representation of the connected lines is:";
			for(int i=0;i<v;i++)
			{
				cout<<endl;
				for(int j=0;j<v;j++)
				{
					cout<<"\t"<<gr[i][j];
				}
			}
		}
};
int main()
{
	int ch,n;
	graph g1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Create";
	cout<<"\n\t2.Display";
	cout<<"\n\t3.Minimum Cost of the travel:";
	cout<<"\n\t4.Exit";
	cout<<"\n\tEnter your choice:";
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
					g1.min_cost();
					break;
				case 4:
					cout<<"\n\tThank You";
					//break;
					default:
						cout<<"\n\tInvlid Input";
	}
   }while(ch!=4);
}
