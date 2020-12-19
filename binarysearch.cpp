#include<iostream>
using namespace std;
class node
{
	int val;
	node *left;
	node *right;
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
		void insert(int v)
		{
			node *ptr,*prev,*curr;
			prev=NULL;
			curr=root;
			while(curr!=NULL && curr->val!=v)
			{
				prev=curr;
				if(curr->val>v)
				{
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}
			if(curr!=NULL && curr->val==v)
			{
				cout<<"\n\tFound,But No Duplication Allowed.";
			}
			else
			{
				ptr=new node;
				ptr->left=NULL;
				ptr->right=NULL;
				ptr->val=v;
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
				cout<<"\n\tInserted Successfully";
			}
		}
		void in_order()
		{
			node *curr;
			node *st[10];
			int top=-1;
			curr=root;
			if(root==NULL)
			{
				cout<<"\n\tEmpty Tree";
			}
			else
			{
			do
			{
				while(curr!=NULL)
				{
					//cout<<"\t"<<curr->val;
					top++;
					st[top]=curr;
					curr=curr->left;
				}
				
				if(top!=-1)
				{
					curr=st[top];
					top--;
					cout<<"\t"<<curr->val;
					curr=curr->right;
				}
			}while(curr!=NULL || top!=-1);
		}
	}
};
int main()
{
	int ch;
	BST b1;
	int v;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Insert";
	cout<<"\n\t2.Inorder";
	cout<<"\n\t3.Exit";
	cout<<"\n\tEnter Your Choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n\tEnter the value";
			cin>>v;
			b1.insert(v);
			break;
			case 2:
				b1.in_order();
				break;
				case 3:
					cout<<"\n\tThank You";
					break;
					default:
						cout<<"\n\tInvalid Choice";
	}
}while(ch!=3);
}
