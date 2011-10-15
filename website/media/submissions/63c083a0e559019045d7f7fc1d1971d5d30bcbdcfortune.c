#include<stdio.h>
#include<stdlib.h>
int power(int x, int n) {
    int index,answer=1;
  if(n == 0)
    return 1;
  else{
        for(index = 1; index <= n; index++)
        answer = answer * x;
        return answer;
        }
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
    scanf("%d",&init);
}                  
