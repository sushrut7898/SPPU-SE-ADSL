#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class record
{
   public:
   string no;
   string name;
   int chain;
   record()
   {
       no="-";
       name="-";
       chain=-1;
   }
};
class hash1
{
  record table[10];
  public:
  void display();
  int hash_key(string);
  void add(record );
  void search();
};
void hash1::display()
{
   for(int i=0;i<10;i++)
      {
           cout<<table[i].name<<"    "<<table[i].no<<"   "<<table[i].chain<<"\n";
      }
}
int hash1::hash_key(string s)
{
   int length=s.size();
   int value=0;
   for(int i=0;i<length;i++)
      {
          int index=int(s[i]-48);
          value=value+index;
      }
    value=value%10;
    return value;
}
void hash1::add(record r)
{
    int index=hash_key(r.no);
    int flag=0;
    for(int i=index;i<20;i++)
       {
           if(table[i].no=="-")
             {
                 table[i].no=r.no;
                 table[i].name=r.name;
                 if(flag==0)
                 {
                      table[i].chain=0;
                 }
                 else
                 {
                    table[i].chain=i;
                 }
                 break;
             }
            else
            {
             index=(index+1)%10;
             flag=1;
            }
       }
}
void hash1::search()
{
   record r;
   cout<<" \n ENTRE THE NO TO BE SEARCHED ";
   cin>>r.no;
   int index=hash_key(r.no);
   for(int i=index;i<20;i++)
   {
       if(table[i].no==r.no)
          {
              cout<<"\n THE ELEMENT IS PRESENT AT INDEX "<<i;
              cout<<" the name of person is "<<table[i].name;
          }
          index=(index+1)%10;
   }
}
int main()
{
   hash1 h;
   record r;             
   char ch;
   int n;
   do
      {
         cout<<"1. insert    2.display    3.search ";
         cin>>n;
         switch(n)
           {
              case 1:
                 {
                    
                    cout<<"\n ENTER THE NAME";
                    cin>>r.name;
                    cout<<"\n ENTER THE NUMBER ";
                    cin>>r.no;
                    h.add(r);
                    break;
                 }
              case 2:
                 {
                     h.display();
                     break;
                 }
              case 3:
                 {
                     h.search();
                     break;
                  }
             }
             cout<<"\n DO U WANT TO PERFORM ANY MORE OPERATION ";
             cin>>ch;
         }while(ch=='y'||ch=='Y');

return 0;
}
                     
