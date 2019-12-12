#include<iostream>
#include<cstdlib>

using namespace std;
void rearrange(char *a,int n)
{
	int i=0;
	int b[26]={0},max=0;
	char *c=(char *)malloc(n*sizeof(char));
	while(a[i]!='\0')
	{
		b[a[i]-97]++;
		if(max<b[a[i]-97])
			max=b[a[i]-97];
		i++;	
	}
	if(n%2==0)
	{
		if(max>n/2)
		{
			cout<<"not possible"<<endl;
			return;
		}
	}
	else
	{
		if(max>(n+1)/2)
		{
			cout<<"not possible"<<endl;
			return;
		}
	}
	int j=0,k=0;
	i=0;
	while(i<n-1)
	{
		while(b[a[i]-97]>0)
		{
			c[j]=a[i];
			j=j+2;
			if(j>=n-1)
			{
				k++;
				j=k;
			}
			b[a[i]-97]--;
		}
		i++;	
	}
	c[n-1]='\0';
	printf("%s",c);
	return;	
}
int main()
{
	char a[]="aaaaaaabbbbbbbccccccc";
	int n=sizeof(a)/sizeof(a[0]);
	rearrange(a,n);
	return 0;
}