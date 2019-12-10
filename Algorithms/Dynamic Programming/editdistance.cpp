/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.
*/

#include<iostream>
#include<string>
using namespace std;

int minimum(int x,int y,int z)
{
	if(x>y)
	{
		if(y>z)
			return z;
		else return y;
	}
	else if(x>z)
		return z;
	else 
		return x;
}
int findmini(string a ,string b,int m,int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;

	
		if(a[m-1]!=b[n-1])
		{
			int x=findmini(a,b,m-1,n-1);
			int y=findmini(a,b,m,n-1);
			int z=findmini(a,b,m-1,n);
			return 1+minimum(x,y,z);
		}
		else
		{
			return findmini (a,b,m-1,n-1);
		}
}

int main()
{
	int mini=0;
	string a="sunday",b="saturday";
		int m=a.length(),n=b.length();
	mini=findmini(a,b,m,n);	
	cout<<mini;
}
