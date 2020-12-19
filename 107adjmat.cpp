#include<iostream>
using namespace std;
class mat
{
   int gr[10][10],n;
   public:
   mat()
     {
         for(int i=0;i<10;i++)
            {
               for(int j=0;j<10;j++)
                 {
                     gr[i][j]=0;
                 }
            }
      }
   void create();
   void display();
 };
 void mat::display()
 {
    
    for(int i=0;i<n;i++)
       {
          for(int j=0;j<n;j++)
             {
                  cout<<gr[i][j]<<"\t";
             }
             cout<<"\n";
       }
}
void mat::create()
{
   int l,m;
   char ch;
   int count=1;
   int flag=0;
   cout<<"\n enter number of connections ";
   cin>>n;
   do
    {
   cout<<"\n ENTER THE SOURCE INDEX ";
   cin>>l;
   cout<<"\n ENTER THE DESTINATION CITY INDEX ";
   cin>>m;
   for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
            {
                if((i==l)&&(j==m))
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
int main()
{
   mat m1;
   m1.create();
   m1.display();
   return 0;
 }










