

int reverse(int x){
int y=0,z;
    z=x;
    if(x>-2147483648)
    x=abs(x);
    while(x>0)
    {
        if((y==214748364 && (x%10)>7) || y>214748364 )
        return 0;
        y=y*10+(x%10);
        x/=10;
        
    }
    if(z<0) 
       if(y<=2147483648)
        y=-y;
       else 
        return 0;
    return y;
}


