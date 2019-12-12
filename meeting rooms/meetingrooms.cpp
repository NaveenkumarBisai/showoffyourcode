#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct interval
{
	int time;
	char c;
};

bool compare(interval i1,interval i2)
{
	return i1.time<i2.time;
}

int main()
{
	int n,res=0,max=0;
	cout<<"enter the no of meetings"<<endl;
	cin>>n;
	interval in[2*n];
	cout<<"enter the meeting timings"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>in[2*i].time>>in[2*i+1].time;
		in[2*i].c='s';
		in[2*i+1].c='e';
	}
	sort(in,in+2*n-1,compare);
	for(int i=0;i<2*n;i++)
	{
		if(in[i].c=='s')
			res++;
		else
			res--;
		if(max<res)
			max=res;
	}
	cout<<max;
}