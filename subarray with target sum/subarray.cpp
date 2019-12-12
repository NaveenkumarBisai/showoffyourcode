#include<iostream>
using namespace std;
int main()
{
	int a[]={15, 2, 4, 8, 9, 5, 10, 23};
	int sum=24,p=0,q=0;
	int i,k=a[0],n=sizeof(a)/sizeof(a[0]);
	for(i=1;i<n;i++)
	{
		k=k+a[i];
		q++;
		while(k>sum)
		{
			k-=a[p];
			p++;
		}
		if(k==sum)
			break;
	}
	if(i==n)
		printf("doesn't exist\n");
	else
	for(i=p;i<=q;i++)
		printf("%d",a[i]);
}