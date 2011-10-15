#include<stdio.h>
#include<stdlib.h>

       int power( int b , int p)
    {
    if( p > 1 )
    return b * power( b , p-1 );
    else
    return b;
    }
       
       

void main()
{
    int x[1000],n[1000],T,i,j,rem,init=2;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
                    scanf("%d",&n[i]);
                    scanf("%d",&x[i]);
                    }
    for(i=0;i<T;i++)
    {
            rem=n[i]%x[i];
            for(j=1;j<=rem;j++)
            {
                               init=power(init,2);
                               }
             printf("%d\n",init);
             init=2;
    }                  
}                  
