#include<iostream>
using namespace std;
class node
{
 int val;
 node *left,*right;
 int ht;
 friend class AVL;	
};
class AVL
{
	node *root;
	public:
		AVL()
		{
			root=NULL;
		}
		int height(node *curr)
		{
			int lh,lr;
			if(curr==NULL)
			{
				return 0;
			}
			
			else if(curr->left==NULL && curr->right==NULL)
			{
				return 1;
			}
			
			else
			{
				if(curr->left!=NULL)
				{
					lh=curr->left->ht;
				}
				else
				{
					lh=0;
				}
				
				if(curr->right!=NULL)
				{
					lr=curr->right->ht;
				}
				
				else
				{
					lr=0;
				}
				
				if(lh>=lr)
				{
					return(lh+1);
				}
				
				else
				{
					return(lr+1);
				}
			}
		}
		
		int bf(node *curr)
		{
			int lh,rh;
			if(curr==NULL)
			{
				return 0;
			}
			
			if(curr->left==NULL && curr->right==NULL)
			{
				return 0;
			}
			
			if(curr->left!=NULL)
			{
				lh=ht->curr->left;
			}
			
			if(curr->right!=NULL)
			{
				rh=ht->curr->right;
			}
			
			return (lh-rh);
		}
		
		root=insert(root,v)
		node *insert(node *curr,int v)
		{
			if(curr==NULL)
			{
				curr=new node;
				curr->val=v;
				curr->left=NULL;
				curr->right=NULL;
			}
			
			else
		{
			if(curr->val>v)
			{
			curr->left=insert(curr->left,v);
				if(bf(curr)==2)
				{
					if(bf(curr->left==1))
					{
						curr=rightrotate(curr);
					}
					
					else
					{
						curr->left=leftrotate(curr->left);
						curr=rightrotate(curr);
					}
				}
			
			}
			
			else
			{
			curr->right=insert(curr->right,v);
			    if(bf(curr)==-2)
			    {
			    	if(bf(curr->right==-1))
			    	{
			    		curr=leftrotate(curr);
					}
					
					else
					{
						curr->right=rightrotate(curr->right);
						curr=leftrotate(curr);
					}
				}
			}
		}
		curr->ht=height(curr);
		return (curr);
	   }
	   
	   node *leftrotate(node *curr)
	   {
	   	  node *temp;
	   	  temp=curr->right;
	   	  curr->right=temp->left;
	   	  temp->left=curr;
	   	  curr->ht=height(curr);
	   	  temp->ht=height(temp);
	   	  return temp;
	   }		
	   
	   node *rightrotate(node *curr)
	   {
	   	  node *temp;
	   	  temp=curr->left;
	   	  curr->left=temp->right;
	   	  temp->right=curr;
	   	  curr->ht=height(curr);
	   	  temp->ht=height(temp);
	   	  return temp;
	   }
	   
	   void in_order()
	   {
	   	  
	   	  node *st[20],*curr;
	   	  int top=-1;
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
		  	cout<<"\t"<<curr->val;
		  	top--;
		  	curr=curr->right;
		  }
		  
	      }while(curr!=NULL || top!=-1);
       }
};

int main()
{
	int ch,v;
	AVL a1;
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
	   	  a1.
	   	  
	}
}





