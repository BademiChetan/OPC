#include<stdio.h>
#define M 1000
int main()
{
	int k, t, i, j, X[M], Y[M], col[M][M], val ;
	static int Y1[M] ;
	
	scanf ( "%d", &t ) ;
	
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf ( "%d %d", &X[i], &Y[i] ) ;
		Y1[i] = Y[i] ;
	}

	for ( j = 0 ; j <= M ; j ++ )
	{
		val = j ;
		for ( i = 0 ; i <= M ; i ++ )
		{
			col[i][j] = val-- ;
			if ( val < 0 )
				val = M ;
		}
	}
	
	for ( i = 0 ; i < t ; i ++ )
		printf ( "%d\n", col[X[i]][Y1[i]] ) ;
	return 0 ;
}