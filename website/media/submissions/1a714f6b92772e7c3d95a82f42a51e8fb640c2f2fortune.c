#include <stdio.h>

int main (void)


{
 int t,i ;
 unsigned long int k , p , r , N  ,B      ;

scanf("%d" , &t ) ;

unsigned long pow [t];

for (i=1 ; i<= t ; i++)

{
  scanf ("%d %ld" , &N , &k) ;
 
  r=N%k ;
  p=1 ; 
  p<<=r ;
  B=1 ;
  B<<=p ;
  pow[i-1] =B ; 
}

for (i=0 ; i<t ; i++ )
printf("%lu \n" ,pow [i] ) ;

return 0 ;

}