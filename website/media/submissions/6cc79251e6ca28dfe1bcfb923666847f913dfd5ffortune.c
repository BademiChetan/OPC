#include<stdio.h>
int main()
{
	int t, i, sum[1000], j, n[1000], k[1000] ;
	
	scanf ( "%d", &t ) ;
	
	for ( i = 0 ; i < t ; i ++ )
	{	
		scanf ( "%d %d", &n[i], &k[i] ) ;
		sum [i] = 2 ;
	}
	
	for ( i = 0 ; i < t ; i ++ )
	{	
		for ( j = 0 ; j < n[i] ; j ++ )
			sum[i] *= sum[i] ;
			
		printf ( "%d\n", sum[i] % k[i] ) ;
	}
	return 0 ;
}
