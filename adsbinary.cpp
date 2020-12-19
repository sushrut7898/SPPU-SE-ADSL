 #include<iostream>
 using namespace std;
 class node
 {
 	int val;
 	node *next;
 	node *left,*right;
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
					cout<<"\n\tSorry!!!No Duplication";
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
		void display()
		{
		    node *curr;
		    node *st[10];
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
		  	cout<<"\n\tThe Number is Found in the tree";
		  }
		  
		  else
		  {
		  	cout<<"\n\tThe Number was not in the Tree";
		  }
		}
		
		void min_val()
		{
		  node *curr;
		  curr=root;
		  while(curr->left!=NULL)
		  {
		    curr=curr->left;	
		  }	
		  cout<<"\n\tThe smallest value in the tree is"<<curr->val;
		}
		
		void mirror_r(node *curr)
		{
		   node *temp;
		   if(curr!=NULL)
		   {
		   	mirror_r(curr->left);
		   	mirror_r(curr->right);
		   	
		   	if(curr->left!=NULL || curr->right!=NULL)
		   	{
		   	    temp=curr->left;
				curr->left=curr->right;
				curr->right=temp;	
			 }
		   }	
		}
		
		void mirror_display()
		{
		  mirror_r(root);	
		}		
 };
 
 int main()
 {
 	bst b1;
 	int ch,v;
 	do
 	{
 	cout<<"\n\tMENU";
 	cout<<"\n\t1.Insert";
 	cout<<"\n\t2.Display";
 	cout<<"\n\t3.Search";
 	cout<<"\n\t4.Minimum Value in the Tree";
 	cout<<"\n\t5.Mirror Display";
 	cout<<"\n\t6.Exit";
 	cout<<"\n\tEnter your choice:";
 	cin>>ch;
 	
 	switch(ch)
 	{
 	   case 1:
		  cout<<"\n\tEnter the value:";
		  cin>>v;
		  b1.insert(v);	
		  break;
		  case 2:
		  	b1.display();
		  	break;
		  	case 3:
		  		cout<<"\n\tEnter the node to be searched";
		  		cin>>v;
		  		b1.search(v);
		  		break;
		  		case 4:
		  			b1.min_val();
		  			break;
		  			case 5:
		  				b1.mirror_display();
		  				break;
		  	   case 6:
		  		cout<<"\n\tThank You";
		  		break;
		  		default:
		  			cout<<"\n\tInvalid Input";
		  			break;
	}
    }while(ch!=6);
}
