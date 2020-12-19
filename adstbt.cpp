#include<iostream>
using namespace std;
class node
{
	int val;
	node *next,*left,*right;
	int lflag;
	int rflag;
	friend class tbt;
};

class tbt
{
	node *troot,*root;
	public:
		tbt()
		{
			root=NULL;
			troot=NULL;
		}
		
		void insert()
		{
			int v;
			int flag;
			node *ptr,*curr;
			root=new node;
			troot=new node;
			
			cout<<"\n\tEnter the root value:";
			cin>>v;
			root->val=v;
			root->left=NULL;
			root->right=NULL;
			root->lflag=0;
			root->rflag=0;
			troot->left=root;
			troot->right=troot;
			root->left=troot;
			root->right=troot;
			cout<<"\n\tRoot Created:";
			curr=root;
			
			while(curr!=troot)
			{
				char ch,ch1;
				cout<<"\n\tDo you want to add to left";
				cin>>ch;
				
				if(ch=='y')
				{
					ptr=new node;
					cout<<"\n\tEnter value";
					cin>>ptr->val;
					ptr->lflag=0;
					ptr->rflag=0;
					ptr->left=curr->left;
					curr->left=ptr;
					curr->lflag=1;
					curr=ptr;
				}
				
				else
				{
					    flag=0;
						cout<<"\n\tDo you want to add to right";
						cin>>ch;
						while(flag==0 && curr!=troot)
						{
							if(ch=='y')
							{
								ptr=new node;
								cout<<"\n\tEnter value";
					            cin>>ptr->val;
								ptr->lflag=0;
								ptr->rflag=0;
								ptr->right=curr->right;
								curr->right=ptr;
								curr->rflag=1;
								curr=ptr;
								flag=1;
							}
							
							else
							{
								curr=curr->right;
							}
						}
				}
			}
			
		}
		
		void in_order()
		{
			int flag;
			node *curr;
			curr=root;
			while(curr!=root)
			{
				if(curr->lflag==1)
				{
					curr=curr->left;
				}
				
				else
				{
					flag=0;
					while(flag==0 &&  curr!=troot)
					{
						cout<<"\t"<<curr->val;
						if(curr->rflag==1)
						{
							curr=curr->right;
							flag=1;
						}
						
						else
						{
							curr=curr->right;
						}
					}
				}
			}
		}
};

int main()
{
	int ch;
	tbt t1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\tInsert";
	cout<<"\n\tInorder Display";
	cout<<"\n\t3.Exit";
	cout<<"\n\tEnter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			t1.insert();
			break;
			
			case 2:
				t1.in_order();
				break;
				
				case 3:
					cout<<"\n\tthank You";
					break;
					
					default:
						cout<<"\n\tInvalid Input";
			
	}
}while(ch!=3);
}
