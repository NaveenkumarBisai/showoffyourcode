#include<stdio.h>

int main()
{
	int a[]={7, 3, 5, 5, 4, 3, 4, 8, 8};
	int i,x;
	x=a[0];
	for(i=0;i<8;i++)
	{
		x=x^a[i+1];
	}
	printf("%d",x);
	return 0;
}