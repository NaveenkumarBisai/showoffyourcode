
#include<stdlib.h>
#include<stdio.h>


void merge(int arr[],int l, int m, int r)
{
	int i=l, j=m+1, k=0;

	int L[r-l+1];

while(i<=m && j<=r)
{
	if(arr[i]<=arr[j])
	{
		L[k++]=arr[i++];
	}
	else
	{
		L[k++]=arr[j++];
	}
}
	while (i != m+1)
	{
		L[k] = arr[i];
		i++;
		k++;
	}

	while (j != r+1)
	{
		L[k]=	arr[j] ;
		j++;
		k++;
	}
	for(i=l,j=0;i<=r;i++,j++)
	arr[i]=L[j];
}

void MergeSort(int arr[],int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;

		MergeSort(arr,l, m);
		MergeSort(arr,m+1, r);
		merge(arr,l, m, r);
	}
}



int main()
{
int arr[8],x,i;
printf("enter the no of elements\n");
scanf("%d",&x);
printf("enter the elements\n");
for(i=0;i<x;i++)
scanf("%d",&arr[i]);

MergeSort(arr,0,x-1);

printf("sorted array\n");
for(i=0;i<x;i++)
printf("%d\n",arr[i]);
	return 0;
}
