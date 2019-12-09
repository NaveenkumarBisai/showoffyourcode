#include <stdio.h>

int main()
{
 int i,a[]={2,4,5,3,6,3,1},b[]={1,1,1,1,1,1,1};
 if(a[0]>a[1])
 b[0]++;
 for(i=1;i<6;i++)
    {
        if(a[i]>a[i-1])
        b[i]++;
        if(a[i]>a[i+1])
        b[i]++;
    }
if(b[6]>b[5])
b[6]++;
for(i=0;i<7;i++)
printf("%d ",b[i]);
    return 0;
}
