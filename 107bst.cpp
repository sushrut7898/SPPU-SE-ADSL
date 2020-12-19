#include<iostream>
using namespace std;
class node
{
  public:
  node *right,*left;
  int data;
};
class bst
{
   node *root;
   public:
   bst()
     {
        root=NULL;
     }
   void create();
   void insert(node *,node *);
   void inorder(node *);
   void display();
   void mirror();
   void swapper(node *);
   int longest(node *);
   void length();
};
void bst::create()
{
 char ch;
 node *ptr;
do
  {
  
  ptr=new node();
  ptr->right=ptr->left=NULL;
  cout<<"\n ENTER THE DATA FOR NODE ";
  cin>>ptr->data;
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
void bst::insert(node *root,node *n1)
{
   if((root->data)>(n1->data))
      {
          if((root->left)==NULL)
              {
                   root->left=n1;
              }
          else
              {
                    insert(root->left,n1);
              }
      }
   else
      {
            if((root->right)==NULL)
               {
                    root->right=n1;
               }
             else
               {
                    insert(root->right,n1);
               }
      }
}
void bst::inorder(node *temp)
{
  // node *temp;
   //temp=root;
   if(temp!=NULL)
      {
          inorder(temp->left);
          cout<<"->"<<temp->data;
          inorder(temp->right);
      }
}
void bst::display()
{
    inorder(root);
}
void bst::mirror()
{
   swapper(root);
}
int bst::longest(node *t)
{
    if(t==NULL)
        return 0;
    return(((longest(t->left))>=(longest(t->right)))?((longest(t->left))+1):((longest(t->right))+1));
}
void bst::length()
{
   longest(root);
}
void bst::swapper(node *temp)
{
    node *n1;
    n1=new node();
    if(temp!=NULL)
   {
    swapper(temp->left);
    swapper(temp->right);
    n1=temp->left;
    temp->left=temp->right;
    temp->right=n1;
   }
}
int main()
{
   bst t1;
   t1.create();
   t1.display();
   cout<<"\n";
   t1.mirror();
   t1.display();
   cout<<"\n";
   t1.length();
   cout<<"\n";
 //  t1.display();
   return 0;
}
