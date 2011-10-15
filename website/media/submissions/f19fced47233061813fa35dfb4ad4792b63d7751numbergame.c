#include<stdio.h>
int main()
{
    int T,N,x,i,j,sum;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        sum=0;
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%d",&x);
            sum = sum+x;
        }
        if((sum+ N-1 )%2 ==0)
        printf("LOSE\n");
        else
        printf("WIN\n");
    }
    return 0;
}
