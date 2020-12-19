#include<iostream>
using namespace std;
class graph
{
	int gr[10][10];
	int visited[10];
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
			int m,l,n,i,j;
			int count=1;
			int flag=0;
			int cost;
		
			cout<<"\n\tEnter How many connections do you want?";
			cin>>n;
			do
			{
			cout<<"\n\tEnter the Start City";
			cin>>l;
			cout<<"\n\tEnter the Destination City";
			cin>>m;
			cout<<"\n\tEnter the cost";
			cin>>cost;
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					if(i==l && j==m)
					{
					flag=1;
					gr[i][j]=cost;
					gr[j][i]=cost;
				    }
					else
					flag=0;
				}
			}
			count++;

		    }while(count<=n);
	}
		   
		 void display()
        {
        	cout<<"\n\tThe Connections of the given cities are:";
        	for(int i=0;i<10;i++)
        	{
        		cout<<endl;
        		for(int j=0;j<10;j++)
        		{
        			cout<<"\t"<<gr[i][j];
				}
			}
		}
};
		
		int main()
		{
			int ch;
			graph g1;
			do
			{
			cout<<"\n\tMENU";
			cout<<"\n\t1.Create Connections";
			cout<<"\n\t2.Display Connections";
			cout<<"\n\t3.Exit";
			cout<<"\n\tEnter your choice";
			cin>>ch;
			switch(ch)
			{
				case 1:
					g1.create();
					break;
					case 2:
						g1.display();
						break;
						case 3:
							cout<<"\n\tThank You";
							break;
							default:
								cout<<"\n\tInvalid Input";
		    }
						
			}while(ch!=3);
			return 0;
		}
