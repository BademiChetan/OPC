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
  scanf("%d",init);
  return 0;
}                  