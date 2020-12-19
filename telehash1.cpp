#include<iostream>
using namespace std;
class hash
{
	int size=10;
	int phno;
	int hashtable[50];
	int flag[];
	public:
		void init()
		{
			for(int i=0;i<10;i++)
			{
				hashtable[i]=0;
			}
		}
		
		void insert()
		{
			int j=phno%10;
			for(int i=0;i<10;i++)
			{
				if(flag[j]==0)
				{
					hashtable[j]=phno;
					flag[j]=1;
					return;
				}
				else
				{
					j=(j+1)%10;
				}		
			}
			cout<<"\n\tTable is full";
		}
		
		void print()
		{
			int j;
			for(int i=0;i<10;i++)
			{
				if(flag[i]==1)
				cout<<"\n("<<i<<")  "<<hashtable[i];
				else
				cout<<"\n("<<i<<") ---";
			}
		}
};
int main()
{
	hash h1;
	int ch,phno;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Insert";
	cout<<"\n\t2.Display";
	cout<<"\n\t3.Exit";
	cout<<"\n\tEnter yor choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n\tEnter the number of the user";
			cin>>phno;
			h1.insert();
			break;
			case 2:
				h1.print();
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
