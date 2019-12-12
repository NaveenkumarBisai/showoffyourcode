#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={1,2,2,1},b[]={2,2};
	int n1=sizeof(a)/sizeof(a[0]),n2=sizeof(b)/sizeof(b[0]);
	int max1,max2;
	max1=*max_element(a,a+n1);
	max2=*max_element(b,b+n2);

	int c[max1]={0},d[max2]={0};
	for(int i=0;i<n1;i++)
	{
		c[a[i]-1]++;
	}
	for(int i=0;i<n2;i++)
	{
		d[b[i]-1]++;
	}
	int i=0,j=0;
	while(i<max1 && j<max2)
	{
		if(c[i]>0 && d[i]>0)
			cout<<i+1<<endl;
			i++;j++;
	}
}