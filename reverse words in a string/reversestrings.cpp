#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c[]="the cat in the hat\0";
	int n=sizeof(c)/sizeof(c[0]);
	char a[n];
	
	int i=0,j=0,k=0;
	for(i=0;i<n;)
	{
		while(c[i]!=' '&& i!=n-1)
		{
			a[j++]=c[i];
			i++;
		}
		if(i==n-1)
		break;
		
		j--;
		i--;
		
		while(j>=0)
		{
			c[k]=a[j];	
			k++;
			j--;
		}
		j=0;
		i=i+2;
		k=i;
		
	}
	cout<<c;
	return 0;
}