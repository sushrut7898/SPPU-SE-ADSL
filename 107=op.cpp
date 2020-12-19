#include<iostream>
using namespace std;
class node 
{
   public:
   node *left,*right;
   int data;
};
class btree
{
   node *root;
   public:
   btree()
     {
        root=NULL;
     }
   void create();
   void insert(node *,node *);
   void display();
   void inorder(node *);
   const btree& operator =(const btree&);
   void copy(node *t1,node *&t2);
};
const btree& btree::operator =(const btree& othertree)
{
     if(this!=&othertree)
        {
            if(othertree.root==NULL)
                  root=NULL;
             else
                 copy(othertree.root,root);
        }
      return *this;
}
void btree::create()
{
    node *ptr;
    char ch;
    do
      {
         ptr=new node();
         cout<<"\n ENTER THE VALUE TO BE ENTERED ";
         cin>>ptr->data;
         ptr->right=ptr->left=NULL;
         if(root==NULL)
              {
                 root=ptr;
              }
          else
              {
                 insert(root,ptr);
              }
          cout<<"\n DO U WANT TO ENTER MORE NODES ";
          cin>>ch;
      }while(ch=='y'||ch=='Y');  
}    
void btree::insert(node *root,node *n1)
{
      char ch;
      cout<<"\n ENTER THE SIDE U WANT TO ENTER THE DATA ";
      cin>>ch;
      if(ch=='l'||ch=='L')
          {
              if(root->left==NULL)
                  {
                     root->left=n1;
                  }
              else
                  {
                       insert(root->left,n1);
                  }
          }
        else if(ch=='r'||ch=='R')
          {
                if(root->right==NULL)
                  {
                      root->right=n1;
                  }
                else
                  {
                       insert(root->right,n1);    
                  }
          }
}
void btree::inorder(node *temp)
{
    if(temp!=NULL)
       {
           inorder(temp->left);
           cout<<" -> "<<temp->data;
           inorder(temp->right);
       }
}
void btree::display()
{
    inorder(root);
}   
void btree::copy(node *b1,node *&b2)   
{
    if(b1==NULL)
      {
         b2=NULL;
      }
     else
     {
        b2=new node();
        b2->data=b1->data;
        copy(b1->left,b2->left);
        copy(b1->right,b2->right);
     }
}
int main()
{
   btree b1,b2;
   b1.create();
   b1.display();
   return 0;
}
    
    
    
    
    
    
    
