#include <iostream>
using namespace std;
class node
{
   int data;
   node *left,*right;
   int lth,rth;
   friend class tbt;
};
class tbt
{  
   node *root=new node(),*dummy;
   public:
   tbt()
    {
       root=NULL;
    }
   void create();
   void insert(node *,node *);
   void inorder();
};
void tbt::create()
{
  char ch;
  do
  {
   node *ptr;
   ptr=new node();
   cout<<"\n ENTER THE DATA FOR THE NODE ";
   cin>>ptr->data;
   ptr->left=ptr->right=NULL;
   ptr->rth=ptr->lth=0;
   if(root==NULL)
     {
        root=ptr;   
        //node *dummy;
        dummy=new node();
        dummy->data=-9999;
        dummy->left=root;
        dummy->right=NULL;
        dummy->lth=1;
        dummy->rth=0;
        root->left=root->right=dummy;
     }
   else
    {
       insert(root,ptr);
    }
    cout<<"\n DO U WANT TO ENTER MORE NODES ";
    cin>>ch;
}while(ch=='y'||ch=='Y');
}
void tbt::insert(node *root,node *n1)
{
   if((n1->data)<(root->data))
     {
         if((root->lth) == 0)
            {
                n1->left=root->left;
                root->left=n1;
                root->lth=1;
                n1->right=root;
            }
          else
            {
               insert(root->left,n1);
            }
     }
   else if((n1->data)>(root->data))
     {
           if((root->rth)==0)
            {
                n1->right=root->right;
                root->right=n1;
                root->rth=1;
                n1->left=root;
            }
            else
            {
                insert(root->right,n1);
            }
     }
}
void tbt::inorder()
{
   node *temp;
   //temp=new node();
   temp=root;
   while(temp!=dummy)
     {
        while(temp->lth == 1)
        {
            temp=temp->left;
        }
        cout<<"->"<<temp->data;
        while(temp->rth == 0)
        {
           temp=temp->right;
           if(temp == dummy)
                return;
            cout<<"->"<<temp->data;
        }
        if(temp->rth==1)
        {
           temp=temp->right;
        }
     }
}
int main()
{
  tbt t1;
  t1.create();
  t1.inorder();
  return 0;
}
