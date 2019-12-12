#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newnode(int d)
{
	node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void levelorder(struct node *root)
{
	if(root==NULL)
		return;
	 queue<node *> q; 
  
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        node *node1 = q.front(); 
        cout << node1->data << " "; 
        q.pop(); 
  
        if (node1->left != NULL) 
            q.push(node1->left); 
  
        if (node1->right != NULL) 
            q.push(node1->right); 
    } 
}

int main()
{
	node *root=(struct node *)malloc(sizeof(struct node));
	root->data=1;
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(3);
	root->left->right=newnode(8);
	levelorder(root);
	
}