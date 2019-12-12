#include<stdio.h>
#define MAX_INT 100
int a[]={3, 2, 5, 1, 1, 9, 3, 4};
int c[8];
void jumptoend()
{
	int i,j;
	int min;
	c[7]=0;
	for(i=6;i>=0;i--)
	{
		min=MAX_INT;
		j=i+1;
		while(j<=i+a[i] || j<=7)
			{
				if(c[j]<min)
					min=c[j];
				j++;
			}
		c[i]=min+1;	
	}
	printf("%d",c[0]);
	return;
}
int main()
{
	jumptoend();
	/* code */
	return 0;
}