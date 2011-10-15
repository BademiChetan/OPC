#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x[100],n[100],T,i,j,rem,init=2;
    printf("\nEnter the no of test cases\n");
    scanf("%d",&T);
    printf("\nEnter N and X\n");
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
                               init=pow(init,2);
                               }
             printf("\n%d",init);
             init=2;
    }                  
  scanf("%d",init);
  return 0;
}                  
