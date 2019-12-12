#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int par;
	int data;
	struct node* left;
	struct node* right;
};


int n;
struct node *array[100];
struct node *node1,*root;

void printtree()
{
    int i;
    for(i=0;i<pow(2,n);i++)
    {
        if(array[i]!=NULL)
        {
            printf("%d %d\n",array[i]->data,array[i]->par);
        }
    }
}

void addnode(struct node * node1,int parent,int d)
{	
	if(d==0)
	{
		array[2*parent+1]=node1;
		array[parent]->left=node1;
	}
	else
	{
		array[2*parent+2]=node1;
		array[parent]->right=node1;
	}

}

struct node* createnode(int parent,int x)
{
	struct node *y=(struct node *)malloc(sizeof(struct node));
	y->data=x;
	y->par=parent;
	y->left=NULL;
	y->right=NULL;
	return y;
}

void makefull()
{
	int i=0;
	for(i=0;i<pow(2,n)-1;i++)
	{
		if(array[i]!=NULL)
		{
			if(array[2*i+1]!=NULL && array[2*i+2]==NULL)
			{
				array[2*i+1]=NULL;
			}
			else if(array[2*i+1]==NULL && array[2*i+2]!=NULL)
			{
				array[2*i+2]=NULL;
			}
		}
	}
	printtree();
}

int main()
{
	int i,x,p,d;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	
	printf("enter the root\n");
	scanf("%d %d",&p,&x);
	root=createnode(p,x);
	array[0]=root;
	
	for(i=1;i<n;i++)
	{
		printf("enter the node %d with parent and direction\n",i);
		scanf("%d %d %d",&p,&x,&d);
		node1=createnode(p,x);
		addnode(node1,p,d);
	}
	printtree();
	makefull(root);
	return 0;
}