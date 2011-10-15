#include<stdio.h>
#include<string.h>

int function ( char * orig, char * sub )
{
	int i, j, count = 0, var ;
	char match[50000] ;
	
	for ( i = 0 ; i < strlen ( orig ) ; i ++ )
	{
		for ( j = i, var = 0 ; j < i + strlen ( sub ) ; j++, var++ )
			match[var] = orig[j] ;
		match[var] = 0 ;
		if ( strcmp ( match, sub ) == 0 )
			count ++ ;
	}
			
	return count ;
}

int main()
{
	int var, t, i, j, loop, q[10], m[10][50000], n, k[10][50000], count[10][50000] ;
	char act[50000], sub[50000] ;
	
	do
	scanf ( "%d", &t ) ;
	while ( t > 10 || t < 1 ) ;
	for ( i = 0 ; i < t ; i ++ )
	{
		do 
		scanf ( "%d", &n ) ;
		while ( n < 1 || n > 50000 ) ;
		do
			scanf ( "%s", act ) ;
		while ( strlen ( act ) != n ) ;
		
		do
		scanf ( "%d", &q[i] ) ;
		while ( q[i] < 1 || q[i] > 50000 ) ;
		
		for ( j = 0 ; j < q[i] ; j ++ )
			do
			scanf ( "%d %d", &m[i][j], &k[i][j] ) ; 
			while ( ( m[i][j] < 0 || m[i][j] >= n ) || ( k[i][j] < 1 || k[i][j] + m[i][j] - 1 >= n ) ) ;
		
	}
	
	for ( i = 0 ; i < t ; i ++ )
	{
		for ( j = 0 ; j < q[i] ; j ++ )
		{
			if ( m[i][j] == k[i][j] )
			{
				sub[0] = act[m[i][j]] ;
				var = 1 ;
			}
			else for ( loop = m[i][j], var = 0 ; loop < k[i][j] ; loop ++, var ++ )
				sub[var] = act [loop] ;
			sub[var] = 0 ;
				
			count[i][j] = function ( act, sub ) ;
			
			printf ( "%d\n", count[i][j] ) ;
		}
	}
	return 0;
}
