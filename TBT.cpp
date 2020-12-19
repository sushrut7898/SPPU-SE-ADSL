#include<iostream>
using namespace std;
class node
{
	int val;
	int lth,rth;
	node *left,*right;
	friend class TBT;
};
class TBT
{
	node *root,*dummy;
	public:
		TBT()
		{
			root=NULL;
		}
		void create()
		{
			node *ptr;
			ptr=new node;
			cin>>ptr->val;
			ptr->lth=0;
			ptr->rth=0;
			ptr->left=NULL;
			ptr->right=NULL;
			if(root==NULL)
			{
				root=ptr;
				dummy=new node;
				dummy->val=-9999;
				dummy->left=root;
				dummy->lth=1;
				dummy->rth=0;
				root->left=root->right=dummy;
		    }
				else
				{
				insert(root,ptr);
			    }
		    }
			void insert(node *root,node *ptr)
			{
				if(root->val>ptr->val)
				{
					if(root->lth==0)
					{
						ptr->left=root->left;
						root->left=ptr;
						ptr->lth=1;
						ptr->right=root;
						
					}
					else
					{
						insert(root->left,ptr);
					}
				}
				
				else
				{
					if(root->rth==0)
					{
					   ptr->right=root->right;
					   root->right=ptr;
					   root->rth=1;
					   ptr->left=root;
					}
					else
					{
						insert(root->right,ptr);
					}
				}
			}   
		 void in_order()
		 {
		 	node *temp;
		 	temp=root;
		 	while(temp!=dummy)
		 	{
		 		while(temp->lth==1)
		 		{
		 	  	temp=temp->left;
		 	    }
		 	  	cout<<"\t"<<temp->val;
		 	  	while(temp->rth==0)
		 	  	{
		 	  		temp=temp->right;
		 	  		if(temp==dummy)
		 	  		{
		 	  		  return;	
					}
		 	  		cout<<"\t"<<temp->val;
				}
				if(temp->rth==1)
				{
					temp=temp->right;
				}
			}
		 }
	};
	int main()
{
		TBT b1;
		int ch;
		do
		{
		cout<<"\n\tMENU";
		cout<<"\n\t1.Insert A node";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Exit";
		cout<<"\n\tEnter your choice";
		cin>>ch;
		switch (ch)
		{
			case 1:
				b1.create();
				break;
				case 2:
					b1.in_order();
					break;
					case 3:
						cout<<"\n\tThank You";
						break;
						default:
							cout<<"\n\tInvalid Input";
		}
		
	}while(ch!=3);
}
