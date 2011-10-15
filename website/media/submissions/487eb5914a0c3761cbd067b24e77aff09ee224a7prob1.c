# include <stdio.h>
#define max(a,b) ((a)>(b)? (a) : (b))

int powtwo(int n)
{
    if (n==0)return 0;
    int i = 1;
    while(i<=n)
    {    i*=2;
    }
    return (i/2);
}

int number(int x, int y)
{
     int x2,y2;
     int z;
     x2 = powtwo(x);
     y2 = powtwo(y);
     z = max(x2,y2);
	if(x==0 && y==1 || x==1 && y==0) return 1;
	if(x==1 && y==1 || x==0 && y==0) return 0;


     if( x >= z && y >= z)
         return number(x-z,y-z);
     else if ( x >= z && y < z)
          return number(x-z,y)+z;
     else
         return number(x,y-z)+z;
}

int main()
{
     //Input
     int i;//Counter for # testcases;
     int t,x,y;
           
     scanf("%d",&t);    
     for(i = 0; i< t; i++)
     {
         scanf("%d %d",&x,&y);
         printf("%d\n",number(x,y));      
     }
    
    return 0;
}
