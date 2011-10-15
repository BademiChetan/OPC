#include<stdio.h>
int main()
{
int i,j,t,n[100],a[100][100];
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%d",&n[i]);
for(j=0;j<n[i];j++)
scanf("%d",&a[i][j]);
}
for ( i = 0 ; i < t ; i ++ )
{
	for ( j = 0 ; j < n[i] - 1 ; j ++ )
		a[i][j+1] = a[i][j] + a[i][j+1] - ( j + 1 ) ;
		
	if ( a[i][j] % 2 )
		printf ( "WIN\n" ) ;
	else
		printf ( "LOSE\n" ) ;
		
}
}
