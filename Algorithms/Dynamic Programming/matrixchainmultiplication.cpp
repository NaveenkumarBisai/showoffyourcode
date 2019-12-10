#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int matrixchain(int a[],int n)
{
	int dp[n][n];
int q;
int j;
int L,k,i;
	for(int i=1;i<n;i++)
		dp[i][i]=0;

	for(L=2;L<n;L++)
	{
		for(i=1;i<n-L+1;i++)
		{
			j=i+L-1;
			dp[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				
				q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
				if(q<dp[i][j])
					dp[i][j]=q;
			}
		}
	}
	return dp[1][n-1];
}

int main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);

	int res=matrixchain(a,n);

	cout<<res;

}