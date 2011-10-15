#include<stdio.h>

int main()
{
    int t, n, a, i, j, sum;
    
    scanf("%d", &t);
    for( i=0; i<t; i++ )
    {
        scanf("%d", &n );
        sum = 0;
        for( j=0; j<n; j++ )
        {
            scanf("%d", &a );
            sum += a;
        }
        if((sum-(n*n-n)/2)%2 == 1)
            printf("WIN\n");
        else
            printf("LOSE\n");
    }   
    return 0;
}
