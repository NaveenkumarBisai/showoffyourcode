// C program to print all permutations with duplicates allowed 
#include <stdio.h> 
#include <string.h> 

/* Function to swap values at two pointers */
void swap(char* x, char* y) 
{ 
  char temp; 
  temp = *x; 
  *x = *y; 
  *y = temp; 
} 

/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char* a, int l, int r) 
{ 
  int i; 
  if (l == r) 
    printf("%s\n", a); 
  else { 
    for (i = l; i <= r; i++) { 
      swap((a + l), (a + i)); 
      permute(a, l + 1, r); 
      swap((a + l), (a + i)); // backtrack 
    } 
  } 
} 

/* Driver program to test above functions */
int main() 
{ 
  char str[] = "ABC"; 
  int n = strlen(str); 
  permute(str, 0, n - 1); 
  return 0; 
} 

/*#include<iostream>
using namespace std;
int a[]={1,2,3,4,5};
int n=sizeof(a)/sizeof(a[0]);
int b[5],x=1;    
void permute(int pos,int size)
{
   // count++;
    if(size==2)
    {
       b[x++]=a[pos+1];
       b[x++]=a[pos+2];
       for(int j=0;j<n;j++)
       printf("%d ",b[j]);
       printf("\n");
       x=x-2;
       b[x++]=a[pos+2];
       b[x++]=a[pos+1];
       for(int j=0;j<n;j++)
       printf("%d ",b[j]);
       printf("\n");
       x=1;
    }
    else
    {
    for(int i=pos+1;i<n;i++)
    {
        b[x++]=a[i];
        int k;
        k=a[pos+1];
        a[pos+1]=a[i];
        a[i]=k;
        permute(pos+1,size-1);
        k=a[pos+1];
        a[pos+1]=a[i];
        a[i]=k;
    }
    }
    
}
int main()
{
    for(int i=0;i<n;i++)
    {
        b[0]=a[i];
        int j;
        j=a[0];
        a[0]=a[i];
        a[i]=j;
        permute(0,n-1);
        j=a[0];
        a[0]=a[i];
        a[i]=j;
    }
}*/