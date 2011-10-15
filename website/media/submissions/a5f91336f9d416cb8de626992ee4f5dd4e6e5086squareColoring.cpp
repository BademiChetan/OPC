#include<stdio.h>
#include<math.h>
int main(){
   int t ;
   scanf("%d",&t);
   while( t -- > 0 ) {
      int x, y ;
      scanf("%d %d",&x,&y);
      if( x < y ){
	 x = x ^ y ;
	 y = y ^ x ;
	 x = x ^ y ;
      }
      int n = log2(x);
      bool flip = false ;
      int ans = x ;
      int sign = 1;
      int fact = 2 ;
      /*
      for( int i = 31 ; i >=0 ; i-- ){
       if( x & (1<<(31-i)) ) sign = sign * -1 ;
       if( y & (1<<i) ){
        ans = ans + sign*(1<<i);
       }
      }*/
      printf("%d\n",x^y);
   }
   return 0 ;
}
