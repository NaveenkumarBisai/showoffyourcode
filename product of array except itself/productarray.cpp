#include<iostream>

using namespace std;
int main()
{
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	int b[n]={0},product=1;
	for(int i=0;i<n;i++)
	{
		product*=a[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=product/a[i];
		cout<<b[i]<<endl;
	}
}