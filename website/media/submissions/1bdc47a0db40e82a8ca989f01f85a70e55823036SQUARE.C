#include<stdio.h>
#define MAX 100
int main()
{
	const int x[MAX], y[MAX] ;
	int i, j, val, t, col[MAX][MAX] ;

	scanf ( "%d", &t ) ;

	for ( i = 0 ; i < t ; i ++ )
		scanf ( "%d %d", &x[i], &y[i] ) ;

	for ( j = 0 ; j <= MAX ; j++ )
	{
		val = j ;
		for ( i = 0 ; i <= MAX ; i ++ )
		{
			col[i][j] = val-- ;
			if ( val < 0 )
				val = MAX ;
		}
	}

	for ( i = 0 ; i < t ; i ++ )
		printf ( "%d\n", col[x[i]][y[i]] ) ; 

/*	for ( i = 0 ; i <= MAX ; i ++ )
	{
		for ( j = 0 ; j <= MAX ; j ++ )
			printf ( "%3d", col[i][j] ) ;
		printf ( "\n" ) ;
	}               */
	return 0 ;
}