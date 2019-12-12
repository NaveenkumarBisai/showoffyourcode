#include<iostream>
#include<cstdlib>

using namespace std;
 int res=0;
struct node
{
	char data;
	struct node * left;
	struct node * right;
};
struct node* newnode(char data1)
{
	struct node *newnode1=(struct node *)malloc(sizeof(struct node));
	newnode1->data=data1;
	newnode1->left=NULL;
	newnode1->right=NULL;
	return newnode1;
}
int compute(struct node* temp)
{
	int x,y;
	if(temp->data=='+')
	{
		x=compute(temp->left);
		y=compute(temp->right);
		return x+y;
	}
	if(temp->data=='*')	
	{
		x=compute(temp->left);
		y=compute(temp->right);
		return x*y;
	}
	if( temp->data >= 48 &&temp->data <= 57 )
	{
		return temp->data-48;
	}
	if(temp->data == NULL)
		return 0;
}
int main()
{
	struct node *root=newnode('*');
	root->left=newnode('+');
	root->right=newnode('+');
	root->left->left=newnode('4');
	root->left->right=newnode('5');
	root->right->right=newnode('4');
	root->right->left=newnode('5');

	res=compute(root);
	cout<<"result"<<res;
}