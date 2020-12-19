#include<iostream>
using namespace std;
class node
{
	int val;
	node *next,*left,*right;
	int flag;
	friend class BT; 
};
class stack
{
	public:
	node *st[20];
	int top=-1;
};
class BT
{
	node *root;
	public:
		BT()
		{
			root=NULL;
		}
		void create()
		{
			int ch,v;
			char ch1;
			node *ptr,*prev,*curr;
		    cout<<"\n\tThe First Value is taken as Root";
		   // root_insert();
			do
			{
			prev=NULL;
			curr=root;
			cout<<"\n\tWhere Do You want to insert?1.Left 2.Right:";
			cin>>ch;
			cout<<endl;
			if(ch==1)
			{
			prev=curr;
			cout<<"\n\tEnter The Value";
			cin>>v;
			ptr=new node;
			ptr->val=v;
			ptr->left=NULL;
			ptr->right=NULL;
			if(prev!=NULL)
			{
				prev->left=ptr;
			}
			else
			{
				root=ptr;
				
			}
		    }
		    
		    else if(ch==2)
		    {
		    prev=curr;
		    cout<<"\n\tEnter The Value:";
			cin>>v;
			ptr=new node;
			ptr->val=v;
			ptr->left=NULL;
			ptr->right=NULL;
			if(prev!=NULL)
			{
				prev->right=ptr;
			}
			else
			{
				root=ptr;
			}
		    }
		    cout<<"\n\tInserted successfully";
			cout<<"\n\tDo you want to continue?";
			cin>>ch1;
			}while(ch1=='y' || ch1=='Y');
}
   
    node *root_insert()
    {
    	node *ptr;
    	ptr=new node;
    	cout<<"\n\tEnter the Root value:";
    	cin>>ptr->val;
    	ptr->left=NULL;
    	ptr->right=NULL;
    	
    	return (ptr);
	}
    void display_inorder()
    {
    	node *st[10];
    	int top=-1;
    	node *curr;
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
	
	void display_preorder()
	{
		node *st[10],*curr;
		int top=-1;
		curr=root;
		do
		{
		while(curr!=NULL)
		{
			cout<<"\t"<<curr->val;
			top++;
			st[top]=curr;
			curr=curr->left;
		}
		
		if(top!=-1)
		{
			curr=st[top];
			top--;
			curr=curr->right;
		}
	}while(curr!=NULL || top!=-1);
}

   void display_postorder(node *curr)
   {
   	node *st[20];
   	int top=-1;
   	/*  node *st[20];
   	  node *st1[20];
   	  int top=-1;
   	  curr=root;
   	  while(curr!=NULL)
   	  {
   	      top++;
		  st[top]=curr;
		  st1[top]=NULL;
		  curr=curr->left;	
	  }
	  
	  while(top!=-1)
	  {
	  	curr=st[top];
	  	top--;
	  	if(st1[top]==NULL)
	  	{
	  	   top++;
		   st[top]=curr;
		   st1[top]=(node*)1;
		   curr=curr->right;
		   while(curr!=NULL)
		   {
		   	top++;
		   	st[top]=curr;
		   	st1[top]=NULL;
		   	curr=curr->left;
		   }
	    }
		   else
		   {
		      cout<<"\t"<<st[curr->val];	
		   }	
		}
		*/
		
		node *temp;
		temp=root;
		do
		{
			while(temp!=NULL)
			{
				temp->flag=0;
				top++;
				st[top]=temp;
				temp=temp->left;
			}
			
			while(top!=-1)
			{
				temp=st[top];
				top--;
				if(temp->flag==0)
				{
					temp->flag=1;
					top++;
					st[top]=temp;
					temp=temp->right;
					while(temp!=NULL)
					{
					    temp->flag=0;
						top++;
					    st[top]=temp;
					    temp=temp->left;
					}
			     }
			    else
					{
						cout<<"\t"<<temp->val;
					}
				}
			}while(top!=-1);
		}
	  
   	  
   
   
   void display_post_order_r()
   {
   	  display_postorder(root);
   }
};
int main()
{
	int ch;
	BT  b1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.Create";
	cout<<"\n\t2.Display Inorder";
	cout<<"\n\t3.Display Preorder";
	cout<<"\n\t4.Display Postorder";
	cout<<"\n\t5.Exit";
	cout<<"\n\tEnter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			b1.create();
			break;
			case 2:
				b1.display_inorder();
				break;
				case 3:
					b1.display_preorder();
					break;
					case 4:
					b1.display_post_order_r();
					break;
			    case 5:
				cout<<"\n\tThank You";
				break;
				default:
					cout<<"\n\tInvalid Input";
	}
}while(ch!=5);
}
