#include<stdio.h>
int main()
{
	int k, t, i, j, X[100], Y[100], col[100][100], maxx, maxy, val ;
	
	scanf ( "%d", &t ) ;
	
	maxx = X[0] = 0 ;
	maxy = Y[0] = 0 ;
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf ( "%d %d", &X[i], &Y[i] ) ;
		if ( X[i] > maxx )
			maxx = X[i] ;
		if ( Y[i] > maxy )
			maxy = Y[i] ;
	}

	for ( j = 0 ; j <= maxy ; j ++ )
	{
		val = j ;
		for ( i = 0 ; i <= maxx ; i ++ )
		{
			col[i][j] = val-- ;
			if ( val < 0 )
				val = maxy ;
		}
	}
	
	
	for ( i = 0 ; i < t ; i ++ )
		printf ( "%d\n", col[X[i]][Y[i]] ) ;
	return 0 ;
}
