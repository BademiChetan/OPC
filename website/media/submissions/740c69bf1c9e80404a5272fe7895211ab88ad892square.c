#include<stdio.h>
int main()
{
	int t, i, X[10000], Y[10000] ;
	
	scanf ( "%d", &t ) ;
	
	for ( i = 0 ; i < t ; i ++ )
		scanf ( "%d %d", &X[i], &Y[i] ) ;
		
	for ( i = 0 ; i < t ; i ++ )
		printf ( "%d\n", Y[i] - X[i] ) ;		
	return 0 ;
}
