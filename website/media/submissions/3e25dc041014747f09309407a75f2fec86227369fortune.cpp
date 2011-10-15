#include<cassert>
#include<set>
#include<math.h>
#include<stack>
#include<limits.h>
#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#define REP(i,n) for(i=0;i<n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n) 
#define sd(n) scanf("%lf",&n)
#define pll(n) printf("%l64d",n) 
#define ss(str) scanf("%s",str)
#define sf(n) scanf("%lf",&n)
#define pb push_back
#define LL long long int 
#define pi pair<int,int> 
#define fi first
#define se second
#define FOR(i,a,b) for(i = a ; i < b ; i++ )
#define S scanf
using namespace std ;
/* This function calculates (ab)%c */
LL modulo(long long int a,long long int b,long long int c){
   long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
   while(b > 0){
      if(b%2 == 1){
	 x=(x*y)%c;
      }
      y = (y*y)%c; // squaring the base
      b /= 2;
   }
   return x%c;
}
LL etf( LL t ){
   LL ans = t ;
   LL i ;
   for( i = 2 ; i <= sqrt(t) ; i++ )
   { 
      if( ( t % i ) == 0 )
      {
	 ans = ans - ans / i ;
      }
      while( t%i == 0 )
      {
	 t=t/i;
      }
   }
   if( t > 1 )
   {
      ans = ans - ans/ t ;
   }
   return ans ;
}
int main(int argc, char *argv[])
{
   int t ;
   scanf("%d",&t);
   while( t -- > 0 ){
      LL n , k ;
      S("%lld %lld",&n,&k);
      LL e = etf(k);
      LL mod = modulo(2,n,e);
      printf("%lld\n",modulo(2,mod,k));
   }
   return 0 ;
}
