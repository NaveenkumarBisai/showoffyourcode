#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	cout<<"enter time in HH:MM format"<<endl;
	int h,m;
	cin>>h>>m;
	int angle=0;
	angle=abs(m*6-(((h%12)*30)+(m/2)));
	cout<<angle;
}