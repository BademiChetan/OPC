

/*
 * Author: blackBird
 * Email: saketbharamberocks@gmail.com
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std ;

typedef long long ll ;
typedef pair<int,int> ii ;

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i ++ ) 
#define FOR0(i,a) for(int i = 0 ; i < (a) ; i ++ ) 
#define FOR1(i,a) for(int i = 1 ; i < (a) ; i ++ )
#define REP(i,a,b,c) for(int i = (a) ; i < (b) ; i+= (c) ) 
#define PRINT printf 
#define ENDL putchar(10)
#define PB push_back
#define MP make_pair
#define SZ size
#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(all(c),x) != (c).end())
#define SQ(x) (x)*(x)
#define INF 0xffffff00
#define ESP 1e-6
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)

#define FASTIO 1 
#ifndef FASTIO
char *ipos, *opos, InpFile[20000000], OutFile[20000000], DIP[20];
inline int input(int flag=0) {

   while(*ipos <= 32) ++ipos;
   if ( flag  ) return (*ipos++ - '0'); /* For getting Boolean Characters */
   int x=0, neg = 0;char c;
   while( true ) {
	  c=*ipos++; if(c == '-') neg = 1;
	  else {
		 if (c<=32) return neg?-x:x;
		 x=(x<<1)+(x<<3)+c-'0';
	  }
   }
}
inline void output(int x,int flag) {
   int y,dig=0;
   while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
   while (dig--) *opos++=DIP[dig];
   *opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
   ipos = InpFile; opos = OutFile;
   fread_unlocked(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO() {
   fwrite_unlocked(OutFile,opos-OutFile,1,stdout);	
}
#define SIMPLEIO 1
#endif
#ifndef SIMPLEIO
inline int input () { int a ; scanf("%d",&a) ; return a ; } 
inline double inputd () { double d ; scanf("%lf",&d ) ; return d ; } 
#endif 
//----------------------------Main Code Starts Here-------------------------------------------------

void init ( void ) {
}

ll phi ( ll K ) {
	ll limit = sqrt(K)+2 ;
	double n = K ;
	FOR(i,2,limit) {
		if ( K%i == 0 ) {
			while ( K%i == 0 ) { K /= i ; } 
			n *= ( 1 - 1.0/(1.0*i) ) ;
		}
	}
	if ( K != 1 ) {
		n *= ( 1 - 1.0/(1.0*K) ) ;
	}
	return n ;
}

ll modulo(ll a,ll b,ll c){
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

void solve ( void ) { 
	ll N = input() ;
	ll K = input() ;
	ll fi = phi(K) ;
	ll power = modulo ( 2, N, fi ) ;
	ll ans = modulo ( 2, power, K ) ;
	cout << ans << endl ;
	return ;
}

int main () {
	init() ;
	int Kases = input() ; 
	FOR0( kases, Kases ) { solve() ; }
	return 0 ;
}
