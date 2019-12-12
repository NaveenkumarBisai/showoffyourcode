#include<iostream>
using namespace std;

int main()
{
	int a[]={0,1,2,5,7,8,9,9,10,11,12};
	int n=sizeof(a)/sizeof(a[0]);
	int j=0,k=0;

	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1]<2)
			k++;
		else
		{
			cout<<a[j]<<"->"<<a[k]<<" ";
			k=k+1;
			j=k;
		}
	}
	if(j==n-1)
	cout<<a[n-1]<<"->"<<a[n-1]<<" ";
	else
	cout<<a[j]<<"->"<<a[k]<<" ";
}