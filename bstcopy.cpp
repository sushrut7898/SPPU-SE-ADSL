#include<iostream>
using namespace std;
class node 
{
	int val;
	node *next,*left,*right;
	friend class bst;
};
class bst
{
	node *root;
	public:
		bst()
		{
			root=NULL;
		}
		
		void insert(int v)
		{
			node *curr,*prev,*ptr;
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
				cout<<"\n\tSorry!!!No Duplication";
			}
			
			else
			{
				ptr=new node;
				ptr->val=v;
				ptr->next=NULL;
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
			cout<<"\n\tThe Node is inserted Successfully!!!";
		}
		
		void in_order(node *curr)
		{
			if(curr!=NULL)
			{
			in_order(curr->left);
			cout<<"\t"<<curr->val;
			in_order(curr->right);
		    }
		    
		}
		
		void in_order_display()
		{
			in_order(root);
		}
		
		node *copy_r(node *curr)
		{
			node *p;
			p=NULL;
			if(curr!=NULL)
			{
				p=new node;
				p->val=curr->val;
				p->left=copy_r(curr->left);
				p->right=copy_r(curr->right);
			}
			return p;
		}
		
		void display_copy()
		{
			copy_r(root);
		}
		
		void make_empty(node *curr)
		{
			if(curr!=NULL)
			{
				make_empty(curr->left);
				make_empty(curr->right);
				delete curr;
			}
		}
		
		void make_empty_r()
		{
			cout<<"\n\tAll Nodes Are deleted Successfully";
			make_empty(root);
		}
};

int main()
{
	int ch;
	bst b1;
	int v;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Insert";
	cout<<"\n\t2.Copy";
	cout<<"\n\t3.Dsiplay";
	cout<<"\n\t4.Delete All Node";
	cout<<"\n\t5.Display Copied tree";
	cout<<"\n\t6.Exit";
	cout<<"\n\tEnter your choice:";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			cout<<"\n\tEnter the value to be inserted:";
			cin>>v;
			b1.insert(v);
			break;
			case 2:
				b1.display_copy();
				break;
				case 3:
					b1.in_order_display();
					break;
					case 4:
						b1.make_empty_r();
						break;
						case 5:
						b1.in_order_display();
						break;	
						case 6:
							cout<<"\n\tThank You";
							break;
							default:
								cout<<"\n\tInvalid Input";
	}
}while(ch!=6);
}
