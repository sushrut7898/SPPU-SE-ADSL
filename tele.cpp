/*
You have a business with several offices; you want to lease phone lines to
connect them up with each other; and the phone company charges different
amounts of money to connect different pairs of cities. You want a set of lines
that connects all your offices with a minimum total cost. Solve the problem by
suggesting appropriate data structures.
*/

#include<iostream>
using namespace std;

class graph
{
    int adj[10][10];
    int city_no;
    string city[10];
    int visited[10];
    int mst[10][10];

    public:
    
    void init_adj();
    void init_mst();
    void init_visit();
    void display(int a[10][10]);
    int city_index(string s); 
    void findmst();
    void create();
};

void graph::init_adj()
{
	for(int i=0;i<city_no;i++)
	{
		for(int j=0;j<city_no;j++)
		{
			adj[i][j]=0;
		}
	}
}

void graph::init_mst()
{
	for(int i=0;i<city_no;i++)
	{
		for(int j=0;j<city_no;j++)
		{
			mst[i][j]=0;
		}
	}
}

void graph::init_visit()
{
	for(int i=0;i<city_no;i++)
	{
		visited[i]=0;
	}
}

void graph::create()
{
    	char op;
        int cost;

        cout<<"Enter total number of cities"<<endl;
        cin>>city_no;

        cout<<"Enter cities"<<endl;
        for(int i=0;i<city_no;i++)
        {
             cout<<(i+1)<<endl;
             cin>>city[i];
        }
   
        init_adj();
        
        for(int i=0;i<city_no;i++)
        {
            for(int j=i+1;j<city_no;j++)
            {
               cout<<"\nIs there any line between "<<city[i]<<" & "<<city[j]<<endl;
	       cin>>op;

	       if(op=='Y'||op=='y')
	       {
		  cout<<"\nEnter the cost\n";
		  cin>>cost;
		  adj[i][j]=adj[j][i]=cost;
	       }
            }
        }

      display(adj);
}

void graph::findmst()
{
	string source_city;				
	int min,k,cost,loc,s,d;
	init_mst();
	init_visit();
	cout<<"\n\tEnter the source city : ";
	cin>>source_city;
	loc=city_index(source_city);
	visited[loc]=1;
	cost=k=0;
	while(k<city_no)
	{
		min=9999;
		for(int i=0;i<city_no;i++)
		{
			if(visited[i]==1)			
			{
				for(int j=0;j<city_no;j++)
				{
					if(visited[j]==0)
					{
						if(adj[i][j]!=0)
						{
							if(min>adj[i][j])
							{
								min=adj[i][j];
		  						s=i;
								d=j;
							}
						}
					}
				}
			}
		}
		if(min!=9999)
		{
			mst[s][d]=mst[d][s]=min;
			cost=cost+min;
			visited[d]=1;
		}
		k++;
	}
	cout<<"\n\tThe minimum spanning tree matrix is : \n\n";
	display(mst);
	cout<<"\n\tThe minimum cost required is : "<<cost<<endl;
}

void graph::display(int a[10][10])
{
	for(int i=0;i<city_no;i++)
	{
		for(int j=0;j<city_no;j++)
		{
			cout<<"\t"<<a[i][j];
		}
		cout<<"\n";
	}
}

int graph::city_index(string s)
{
	for(int i=0;i<city_no;i++)
	{
		if(city[i]==s)
		{
			return(i);
		}
	}
}

int main()
{
    graph g;
    g.create();
    g.findmst();
} 

/*

OUTPUT

apr@C04L0826:~/Desktop$ g++ code.cpp
apr@C04L0826:~/Desktop$ ./a.out
Enter total number of cities
4
Enter cities
1
Mumbai
2
Delhi
3
Kolkata
4
Chennai

Is there any line between Mumbai & Delhi
y

Enter the cost
450

Is there any line between Mumbai & Kolkata
y

Enter the cost
400

Is there any line between Mumbai & Chennai
y

Enter the cost
550

Is there any line between Delhi & Kolkata
y

Enter the cost
350

Is there any line between Delhi & Chennai
y

Enter the cost
600

Is there any line between Kolkata & Chennai
n
	0	450	400	550
	450	0	350	600
	400	350	0	0
	550	600	0	0

	Enter the source city : Mumbai

	The minimum spanning tree matrix is : 

	0	0	400	550
	0	0	350	0
	400	350	0	0
	550	0	0	0

	The minimum cost required is : 1300
*/ 

