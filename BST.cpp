#include<iostream>
using namespace std;
class node
{
	node *left,*right;
	int val;
	node *next;
	friend class BST;
};
class BST
{
	node *root;
	public:
		BST()
		{
			root=NULL;
		}
		void create(int v)
		{
			node *prev,*curr,*ptr;
			prev=NULL;
			curr=root;
			while(curr!=NULL && curr->val!=v)
			{
				prev=curr;
				if(curr!=NULL && curr->val==v)
				{
					cout<<"\n\tFound,Sorry No Duplication";
				}
				else
				{
					ptr=new node;
					ptr->val=v;
					ptr->left=NULL;
					ptr->right=NULL;
					if(prev!=NULL)
					{
						if(prev->val>v)
						{
							prev->left=ptr;
						}
						else
						{
							prev->right=ptr;
						}
					}
					else
					{
						root=ptr;
					}
					
				}
				cout<<"\n\tInserted";
			}
		}
		
		void inorder()
		{
			node *st[20];
			int top=-1;
			node *curr;
			curr=root;
			while(curr!=NULL)
			{
				top++;
				st[top]=curr;
				curr=curr->left;
			}
			if(top!=-1)
			{
				curr=st[top];
				cout<<"\t"<<st[top];
				top--;
				curr=curr->right;
				
				if(curr!=NULL)
				{
					top++;
				    st[top]=curr;
				    curr=curr->left;
				}
			}	
		}
};

int main()
{
	int ch,v;
	BST b1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Insert";
	cout<<"\n\t2.Display";
	cout<<"\n\t3.Exit";
	cout<<"\n\tEnter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n\tEnter the value:";
			cin>>v;
			b1.create(v);
			break;
			case 2:
				b1.inorder();
				break;
				case 3:
					cout<<"\n\tThank You";
					break;
					default:
						cout<<"\n\tInvalid Input";
	}
}while(ch!=3);
}
