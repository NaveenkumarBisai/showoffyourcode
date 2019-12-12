#include <stdio.h>

int b[10];
char c[10];
char str[10];
int i=0,j=0,k=0,l=0,m,n;
void expand(char *a)
{
    printf("%d ",i);
if(a[i]=='\0')
return;
    if(a[i]>=49 && a[i]<=57)
    {
        b[j++]=a[i]-48;
        i++;
        printf("%d %d\n",b[j-1],j);
        expand(a);
    }
    else if((a[i]>=97 && a[i]<=122) || a[i]=='[')
    {
        c[k++]=a[i];
        i++;
        printf("%c %d\n",c[k-1],k);
        expand(a);
    }
    else if(a[i]==']')
    {
        l=0;
        k--;
        printf("%d ",k);
        while(c[k]!='[')
        {
            str[l++]=c[k];
            k--;
        }
        printf("%d %d ",k,l);
        k--;
        l--;
        j--;
        printf("%d %d %d %d ",k,l,j,b[j]);
        n=l;
        for(m=0;m<b[j];m++)
        {
             l=n;
             printf("%d ",l);
            while(l>=0)
            {
                k++;
                c[k]=str[l--];
            }
        }
        //j--;
        k++;
        printf("%d \n",k);
        i++;
        expand(a);
    }
}

int main()
{
    char d[]="2[a2[bc]]";
    expand(d);
    int i=0;
    while(c[i]!='\0')
    {
    printf("%c",c[i]);
    i++;    
    }
    return 0;
}
