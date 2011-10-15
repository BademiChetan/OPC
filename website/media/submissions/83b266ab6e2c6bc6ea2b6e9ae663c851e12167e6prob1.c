#include<stdio.h>

int main()
{
    long long int t, x, y, i;
    scanf("%lld", &t);
    for( i=0; i<t; i++ )
    {
        scanf("%lld%lld", &x, &y);
        printf( "%lld\n", x^y );
    }   
    return 0;
}
