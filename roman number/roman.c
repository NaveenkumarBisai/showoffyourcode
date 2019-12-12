#include<stdio.h>
/*Roman numerals are based on the following symbols:
I     1
IV    4
V     5
IX    9 
X     10
XL    40
L     50
XC    90
C     100
CD    400
D     500
CM    900
M     1000
Numbers are strings of these symbols in descending order. In some cases, subtractive notation is used to avoid repeated characters. The rules are as follows:
1.) I placed before V or X is one less, so 4 = IV (one less than 5), and 9 is IX (one less than 10)
2.) X placed before L or C indicates ten less, so 40 is XL (10 less than 50) and 90 is XC (10 less than 100).
3.) C placed before D or M indicates 100 less, so 400 is CD (100 less than 500), and 900 is CM (100 less than 1000).*/

void convert(char *c)
{
	int i=0,val=0;
	int x=0,y=0;
	while(c[i]!='\0')
	{
	    if(y<x)
	    y=x-y;
	    else
		y=x;
		if(c[i]=='I')
			x=1;
		else if(c[i]=='V')
			x=5;
		else if(c[i]=='X')
			x=10;
		else if(c[i]=='L')	
			x=50;
		else if(c[i]=='C')
			x=100;
		else if(c[i]=='D')
			x=500;
		else if(c[i]=='M')
			x=1000;
		val+=x;
		if(y<x)
		{
			val=val-2*y;
		}
		i++;
	}
	printf("%d",val);
}

int main()
{
	char c[]="IXXM";
	convert(c);
	return 0;
}