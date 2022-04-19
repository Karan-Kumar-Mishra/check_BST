#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class node
{
public:
    int info;
    node *left;
    node *right;
};
node* create(int data)
{
    node *ptr= new node;
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        cout<<root->info<<" ";
        inorder(root->right);
    }
}

node* min(node *root)
{
  node *temp=root;
  while(temp->left!=NULL)
  {
   temp=temp->left;
  }
  return temp;
}
node* max(node *root)
{
  node *temp=root;
  while(temp->right!=NULL)
  { 
   temp=temp->right;
  }
  return temp;
}
int isBST(node *root,node *min=NULL,node *max=NULL )
{
  if(root==NULL)
  {
   return 1;
  }
  if(min!=NULL && root->info <=min->info)
  {
   return 0;
  }
  if(max!=NULL && root->info >=max->info )
  {
   return 0;
  }
  
  int l= isBST(root->left,min,root);       
  int r= isBST(root->right,root,max);
  return l && r ;
} 
int main()
{
    
     
    clrscr();
    node *root,*p1,*p2,*p3,*p4;
    root=create(40);
    p1=create(20);
    p2=create(50);
    p3=create(10);
    p4=create(30);
   
    root->left=p1;
    root->right=p2;
  
    p1->left=p3;
    p1->right=p4;
   
    
    inorder(root);
    cout<<endl<<endl;
    
    if(isBST(root,NULL,NULL))
    {
     cout<<"this is a bst"<<endl;
    }
    else
    {
     cout<<"this is not a bst"<<endl;
    }
  
    cout<<endl<<endl;
    inorder(root);
  
    return 0;
}