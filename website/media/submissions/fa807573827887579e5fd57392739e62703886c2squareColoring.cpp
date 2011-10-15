#include<stdio.h>
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
      if( x % 2 == 1 || (x == y) ){
	 printf("%d\n",x-y);
      }
      else{
	 printf("%d\n",x+y);
      }
   }
   return 0 ;
}
