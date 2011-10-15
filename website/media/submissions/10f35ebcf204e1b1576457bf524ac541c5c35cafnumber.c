#include<stdio.h>

main()
{
    int t, n, a, i, j, odd=0, even=0, sum;
    
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
        if( (sum - (n*(n-1))/2)%2 == 1 )
            printf("WIN\n");
        else
            printf("LOSE\n");
    }   
    return 0;
}
