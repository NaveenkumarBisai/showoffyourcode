#include<stdio.h>

int main()
{
	int n=7;
	int a=0,b=1,c;
	int i;
	for(i=0;i<n-2;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d",c);
	return 0;
}