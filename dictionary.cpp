#include<iostream>

#include<iomanip>
using namespace std;

class dictionary
{
	public:
		string key;
		string meaning;
		dictionary()
		{
			key="-";
			meaning="-";
		}
		friend class hashing;
};
class hashing
{
	dictionary hashtable[20];
	public:
		int hash_key(string);
		void add(dictionary);
		void search();
		void display();
};
int hashing::hash_key(string key)
{
	int len=key.size();
	int hash=0;
	
		 int digit=int(key[len-1]-48);
		 hash=hash+digit;
		 cout<<"\n\tHASH="<<hash;
	
	hash=hash%10;
	return hash;
}

void hashing::add(dictionary d)
{
	int index=hash_key(d.key);
	cout<<"\n\t"<<index;
	
	if(hashtable[index].meaning=="-")
	{
		hashtable[index]=d;
	}
	
	else
	{
		cout<<"\n\tCould Not Add";
	}	
}

void hashing::search()
{
	dictionary d;
	cout<<"\n\tEnter the word to be searched";
	cin>>d.key;
	int index=hash_key(d.key);
	if(hashtable[index].key!="-")
	{
		cout<<"\n\tFound And Meaning of the word is:"<<hashtable[index].meaning;
	}
	else
	{
		cout<<"\n\tThe Word is not in the dictionary";
	}
}

void hashing::display()
{
	cout<<setw(15)<<"Word"<<setw(15)<<"Meaning";
	for(int i=0;i<10;i++)
	{
			cout<<setw(15)<<hashtable[i].key<<"-"<<setw(15)<<hashtable[i].meaning<<endl;
	}
}

int main()
{
	hashing h1;
	dictionary d;
	int ch;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Insert";
	cout<<"\n\t2.Search";
	cout<<"\n\t3.Display";
	cout<<"\n\t4.Exit";
	cout<<"\n\tEnter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n\tEnter the Word:";
			cin>>d.key;
			cout<<"\n\tEnter the Meaning";
			cin>>d.meaning;
			h1.add(d);
			break;
			case 2:
				h1.search();
				break;
				case 3:
					h1.display();
					break;
					case 4:
						cout<<"\n\tThank You";
						break;
						default:
							cout<<"\n\tInvalid Input";
	}
}while(ch!=4);
}
