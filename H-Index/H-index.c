#include <stdio.h>

int a[5]={1,0,0,0,0};
int c[5]={0};
void hindex()
{
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		c[i]=i+1;
		if(c[i]==a[i])
			{
				printf("%d",i+1);
				return;
			}
	}
	printf("h-index not present\n");
	return;
}
int main()
{
	
	//printf("enter the array\n");
	//first sort the array if it is not sorted then proceed further
	hindex();

	return 0;
}