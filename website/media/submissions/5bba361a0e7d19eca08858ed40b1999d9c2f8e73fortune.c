#include<stdio.h>
#include<stdlib.h>

void main()
{
    int x[1000],n[1000],T,i,j,rem,init=2,index,answer=1;
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
            if(n == 0)
            init = 1;
            else{
            for(index = 1; index <= 2; index++)
            answer = answer * 2;
            }
            }
            init=answer;
            answer=1;
             printf("%d\n",init);
             init=2;
    }      
}                  
