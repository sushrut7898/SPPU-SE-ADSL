#include<iostream>
using namespace std;
class node
{
	int val;
	node *left;
	node *right;
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
				cout<<"\n\tFound,Sorry No Duplication!!!";
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
				cout<<"\n\tInserted Successfully";
			}
		}
		void inorder()
		{
			node *curr;
            node *st[20];
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
	void search(int v)
	{
		node *curr,*prev;
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
				cout<<"\n\tFound";
			}
			else
			{
				cout<<"\n\tNot Found";
			}
	   }
	int height(node *curr)
	{
		int lh,lr;
		if(curr==NULL)
		{
			return 0;
		}
		if(curr->left==NULL && curr->right==NULL)
		{
			return 1;
		}
		else
		{
			lh=height(curr->left);
			lr=height(curr->right);
			
			if(lh>lr)
			cout<<"\n\t"<<(lh+1);
			
			else
			cout<<"\n\t"<<(lr+1);
		}
}
		
		void total_nodes()
		{
			node *curr;
			node *st[20];
			int top=-1;
			int count=0;
			curr=root;
		    do
		    {
		    	while(curr!=NULL)
		    	{
		    		top++;
		    		st[top]=curr;
		    		curr=curr->left;
				}
				
				if(top!=-1)
				{
					curr=st[top];
					top--;
					count++;
				}
			}while(curr!=NULL || top!=-1);
			cout<<"\n\tTotal Number of nodes are:"<<count;
		}
		
	}
	
	void height_r()
	{
		height(root);
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
	cout<<"\n\t2.Inorder";
	cout<<"\n\t3.Search";
	cout<<"\n\t4.Height";
	cout<<"\n\t5.Total Nodes";
	cout<<"\n\t6.Exit";
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
					cout<<"\n\tEnter the node to be searched";
					cin>>v;
					b1.search(v);
					break;
					case 4:
						b1.height_r();
						break;
				        case 5:
					    cout<<"\n\tThank You";
					    break;
					default:
						cout<<"\n\tInvalid Input";
	}
}while(ch!=5);
}
