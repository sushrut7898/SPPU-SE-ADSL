#include<iostream>
#define size 10
#define false 0
#define true 1
using namespace std;
class hash
{
	string name;
	int phno,hashtable[50];
	int flag[];
	int j=phno%size;
	public:
	void init()
	{
		for(int i=0;i<50;i++)
		{
			hashtable[i]=0;
		}
	}
	
	void insert()
	{
		string name;
		int phno;
		cout<<"\n\tEnter the name of the person";
		cin>>name;
		cout<<"\n\tEnter the telephone number of the person";
		cin>>phno;
		for(int i=0;i<size;i++)
		{
		if(flag[j]==false)
		{
			hashtable[j]=phno;
			flag[j]=true;
			return;
		}
		else
		j=(j+1)%size;
		
		cout<<"\n\tTelephone Number of the person is inserted in the Directory";
	}
	cout<<"\n\tTable is Full";
}
	
	void print()
	{
		string name;
		int phno;
		for(int i=0;i<size;i++)
		{
			if(flag[i])
			cout<<"\n("<<i<<")"<<hashtable[i];
			else
			cout<<"\n("<<i<<")---";
		}
	}
};
int main()
{
	hash h1;
	int ch,phno;
	string name;
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
			cout<<"\n\tEnter the name of the user";
			cin>>name;
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
