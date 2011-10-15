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
        if((sum)%2 ==0 &&((N-1)%3 == 0))
        printf("LOSE\n");
        else if(sum% 2 == 0 && ( (N-1)%3 == 1 || (N-1)%4 == 2))
        printf("WIN\n");
        else if( sum%2 ==1 && (N-1)%3 == 0)
        printf("WIN\n");
        else if(sum%2 ==1 && ((N-1)%3 == 1 || (N-1)%3 == 2))
        printf("LOSE\n");
    }
    return 0;
}
