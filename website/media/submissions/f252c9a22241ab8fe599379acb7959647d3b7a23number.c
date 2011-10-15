#include<stdio.h>

int main()
{
    long int t, n, a, i, j, sum, s1;
    
    scanf("%ld", &t);
    for( i=0; i<t; i++ )
    {
        scanf("%ld", &n );
        s1=n*(n-1)/2;
        sum = 0;
        for( j=0; j<n; j++ )
        {
            scanf("%ld", &a );
            sum += a;
        }
        if((sum-s1)%2== 1)
            printf("WIN\n");
        else
            printf("LOSE\n");
        //printf("%ld %ld\n", sum,s1);
    }   
    return 0;
}
