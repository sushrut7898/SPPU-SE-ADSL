/* 1) Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order
given. After constructing a binary tree -
i. Insert new node
ii. Change a tree so that the roles of the left and right pointers are swapped at every node
iii. display 
*/

#include <iostream>
using namespace std;

class node
{
	int data;
	node *left , *right;
	friend class bst;
};

class bst
{
	node * root ;
	public:
		bst()
		{
			root = NULL;
		}
		void create();
		void insert(node* , node*);
		void swap(node*);
		void inorder(node*);
		void menu();
};

void bst :: create()
{
	node *n;
	char ch;
	do
	{
		n = new node();
		n->left = NULL;
		n->right = NULL;
		cout<<"Enter data to be inserted : ";
		cin>>n->data;
		if(root == NULL)
		{	
			root = n;
		}
		else
		{
			insert(root,n);
		}
		cout<<"Do you want to continue entering"<<endl;
		cin>>ch;
	}while(ch == 'y'||ch == 'Y');
}

void bst :: insert(node* root , node* n)
{
	
	if(n->data < root->data)
	{
		if(root->left == NULL)
		{
			root-> left = n;
	
		}
		else
		{
			insert(root->left , n);
		}
	}
	else
	{
		if(root->right == NULL)
		{
			root->right = n;
			
		}
		else
		{
			insert(root->right , n);
		}
	}
}

void bst :: swap(node* root)
{
	node* temp;
	if(root != NULL)
	{
		swap(root->left);
		swap(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void bst :: inorder(node* temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<"  "<<temp->data;
		inorder(temp->right);
	}
}	

void bst :: menu()
{
	
	int ch;
	do
	{
		cout<<" 1.ENter a new node in the bst "<<endl<<"2.Display BST"<<endl<<"3.Mirror the bst"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1 :
				create();
				break;
				
			case 2 :
				inorder(root);
				break;
				
			case 3:
				swap(root);
				inorder(root);
				break;
		}	
		
	}while(ch != 4);
}

int main()
{
	bst b1;
	b1.menu();
	return 0;
}
