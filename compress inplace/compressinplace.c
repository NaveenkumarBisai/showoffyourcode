#include<stdio.h>
int main()
{
    int i=0,count=1,j=0,k=0;
    char a[]="aabcbcaaab\0";
    while(a[i]!='\0')
    {   
       a[j]=a[i];
       j++;
       k=i+1;
       while(a[i]==a[k])
       {
           count++;
           k++;
        }
        i=k;
        if(count>1)
        {
            a[j]=count+48;
        j++;}
        count=1;
        //i++;
    }
    a[j]='\0';
   // i=0;
    printf("%s",a);
    return 0;
}