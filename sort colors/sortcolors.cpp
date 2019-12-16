#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],x=0,y=0,z=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			x++;
		else if(a[i]==1)
			y++;
		else
			z++;
	}
	int k=0;
	for(int i=0;i<x;i++)
		a[k++]=0;
	for(int i=0;i<y;i++)
		a[k++]=1;
	for(int i=0;i<z;i++)
		a[k++]=2;
	for(int i=0;i<n;i++)
		cout<<a[i];
}