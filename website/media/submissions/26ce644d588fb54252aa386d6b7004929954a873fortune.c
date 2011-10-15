#include<stdio.h>
int main()
{
	int t, i, j, n[1000], k[1000], sum[1000] ;
	
	scanf ( "%d", &t ) ;
	
	for ( i = 0 ; i < t ; i ++ )
	{	
		scanf ( "%d %d", &n[i], &k[i] ) ;
	}
	
	for ( i = 0 ; i < t ; i ++ )
	{	
		for ( j = 0 ; j < n[i] ; j ++ )
			sum[i] = ( j == 0 )? ( 2 * 2 ) : ( sum[i] * sum[i] ) ;
			
		sum[i] = sum[i] % k[i] ;
		printf ( "%d\n", sum[i] ) ;
	}
	return 0 ;
}
