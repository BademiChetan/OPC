#include<stdio.h>
#include<stdlib.h>

       int power( int b , int p)
    {
    if( p > 1 )
    return b * power( b , p-1 );
    else
    return b;
    }
       
       

int main()
{
    int x[100],n[100],T,i,j,rem,init=2;
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
  return 0;
}                  
