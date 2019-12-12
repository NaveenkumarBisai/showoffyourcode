#include<iostream>
using namespace std;

void addone(int a[],int n)
{
	int i=n-1,v;
	if(n==1&&a[i]==9)
		{
		    a[i]=0;
			cout<<"1";
			return;
		}
	if(a[i]<9)
	{
		a[i]=a[i]+1;
		return;
	}
	else
	{
		a[i]=0;
		addone(a,i);
	    return;
	}
}

int main()
{
	int a[]={4,1,5,9};
	int n=sizeof(a)/sizeof(a[0]);

	addone(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i];
	return 0;
}