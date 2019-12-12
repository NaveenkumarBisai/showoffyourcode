#include<stdio.h>
#define MAX 100
int main()
{
	int a[]={1,2,3,4,5,6};
	int min=0;
	int max=0;
	//int count=0;
	int i;
	if(a[0]>=a[1]) {
		min=1;
		max=0;
		}
	else {
		min=0;
		max=1;
		}	
	for(i=2;i<6;i++)
		if(a[i]<=a[min])
			{
				min=i;
			}
		else if(a[i]>a[max])
			{
				max=i;
				count++;
			}			}
	//	else if()	

	printf("%d %d %d",a[min],a[max],count);	
	return 0;
}