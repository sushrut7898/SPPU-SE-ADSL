#include<iostream>
using namespace std;
class prim
{
   int adj[10][10];
   int city_no;
   int mst[10][10];
   string city[10];
   int visited[10];
   public:
   void init_adj();
   void init_mst();
   void init_visited();
   int city_index(string);
   void create();
   void out();
   void display(int a[10][10]);
};
void prim::init_adj()
{
   for(int i=0;i<city_no;i++)
       {
           for(int j=0;j<city_no;j++)
                 {
                       adj[i][j]=0;
                 }
       }
}
void prim::init_mst()
{
   for(int i=0;i<city_no;i++)
       {
           for(int j=0;j<city_no;j++)
                 {
                       mst[i][j]=0;
                 }
       }
}
void prim::init_visited()
{
    for(int i=0;i<city_no;i++)
       {
             visited[i]=0;
       }
}
int prim::city_index(string s)
{
    for(int i=0;i<city_no;i++)
       {
          if(city[i]==s)
             {
                return i;
             }
       }
}
void prim::display(int a[10][10])
{
    for(int i=0;i<city_no;i++)
       {
           for(int j=0;j<city_no;j++)
                {
                       cout<<a[i][j]<<"\t";
                }
              cout<<"\n";
       }
}
void prim::create()
{
   char op;
   int cost;
   cout<<"\n ENTER NUMBER OF CITIES ";
   cin>>city_no;
   cout<<"\n THE CITIES ARE ";
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
                      cout<<"\n IS THERE AN EDGE BETWEEN"<<city[i]<<" & "<<city[j];
                      cin>>op;
                      if(op=='y'||op=='Y')
                         {
                               cout<<"\n ENTER THE COST ";
                               cin>>cost;
                               adj[i][j]=adj[j][i]=cost;
                         }
                }
        }
      display(adj);
}
void prim::out()
{
   int cost,k;
   int min;
   int s,d;
   string source_city;
   init_mst();
   init_visited();
   cout<<"\n ENTER THE NAME OF SOURCE CITY ";
   cin>>source_city;
   int loc=city_index(source_city);
   visited[loc]=1;
   k=cost=0;
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
   display(mst);
   cout<<"\n THE MINIMUM COST IS"<<cost;
   
}
int main()
{
   prim p;
   p.create();
   p.out();
   return 0;
          
}
