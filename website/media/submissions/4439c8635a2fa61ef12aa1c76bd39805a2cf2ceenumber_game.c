#include<stdio.h>
int main()
{
        int T,x,N,i,sum,j;
        scanf("%d",&T);
        for(i=0;i<T;i++)
        {
                scanf("%d",&N);
                sum=0;
                for(j=0;j<N;j++)
                {
                        scanf("%d",&x);
                        sum=sum+x;
                }
                sum=sum-(N*(N-1))/2;
                if(sum%2) printf("WIN\n");
                else printf("LOSE\n");
        }
        return 0;
}
