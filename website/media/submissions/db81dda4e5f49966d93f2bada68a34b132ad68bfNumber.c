#include<stdio.h>
int main()
{
int i,j,t,n[100],a[100][100];
do
scanf("%d",&t);
while ( t < 1 || t > 100 ) ;
for(i=0;i<t;i++)
{
do
scanf("%d",&n[i]);
while ( n[i] < 1 || n[i] > 100 ) ;
for(j=0;j<n[i];j++)
do
scanf("%d",&a[i][j]);
while ( ! ( a[i][j] >= 1 && a[i][j] <= 100 ) ) ;
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
