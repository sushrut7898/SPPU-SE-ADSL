#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class record
{
	public:
		string name;
		string no;
		record()
		{
			name="-";
			no="-";
		}
		friend class telephone;
};

class telephone
{
	record table[10];
	public:
		int hashing(string no);
		void add(record);
		void display();
};
int telephone::hashing(string no)
{
	int len=no.size();
	int hash_key=0;
	for(int i=len-4;i<len;i++)
	{
		cout<<"i="<<i<<"no[i]"<<no[i]<<endl;
		int digit=int(no[i]-48);
		cout<<"Digit="<<digit;
		hash_key+=digit*digit;
		cout<<"\n\tHash-Key="<<hash_key;
	}
	hash_key=hash_key%10;
	cout<<"\n\tHash-key="<<hash_key;
	return hash_key;
}

void telephone::add(record r)
{
	int index=hashing(r.no);
	if(table[index].name=="-")
	{
		table[index]=r;
	}
	else
	{
		cout<<"\n\tCould not Add";
	}
}

void telephone::display()
{
	cout<<setw(15)<<"NAME"<<setw(15)<<"NUMBER";
	for(int i=0;i<10;i++)
	{
		cout<<setw(15)<<table[i].name<<"-"<<setw(15)<<table[i].no<<endl;
	}
}

int main()
{
	telephone t1;
	int n;
	cout<<"\n\tHow many Entries you want to make";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		record r;
		cout<<"\n\tENTER NAME";
		cin>>r.name;
		cout<<"\n\tENTER NUMBER";
		cin>>r.no;
		t1.add(r);
		t1.display();
	}
}

