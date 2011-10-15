#include<stdio.h>
#include<string.h>

int function ( char * orig, char * sub )
{
	int i, j, count = 0, var ;
	char match[500] ;
	
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
	int var, t, i, j, loop, q[10], m[10][500], n, k[10][500], count[10][500] ;
	char act[1000], sub[1000] ;
	
	scanf ( "%d", &t ) ;
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf ( "%d", &n ) ;
		do
			scanf ( "%s", act ) ;
		while ( strlen ( act ) != n ) ;
		
		scanf ( "%d", &q[i] ) ;
		
		for ( j = 0 ; j < q[i] ; j ++ )
			scanf ( "%d %d", &m[i][j], &k[i][j] ) ; 
		
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
