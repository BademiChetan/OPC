

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

ll ans = 0 ;
char in[51111] ;
	
vector<int> P[257] ;

bool find ( int cp, int p, int l ) {
	if ( l == 0 ) { return true ; } 
	int c = in[cp] ;
	int low = 0 ;
	int high = P[c].SZ(); 
   	while ( low <= high ) {
		int mid = ( low + high ) /2 ; 
		if ( P[c][mid] > p ) { high = mid-1 ; } 
		else if ( P[c][mid] < p ) { low = mid+1 ; } 
		else { return find( cp+1, p+1, l-1 ) ; }
	}	
	return false ;
}

void solve ( void ) { 
	int N = input() ;
	scanf("%s",in) ;
	int Q = input() ;
	FOR0(i,257) {
		P[i].clear();
	}
	FOR0(i,N) {
		P[in[i]].PB(i) ;
	}
	FOR0(q, Q) {
		int M = input() ;
		int K = input() ;
		ans = 0 ;
		FOR0(i, P[ in[M] ].SZ() ) {
			if ( find(M+1, P[in[M]][i]+1, K-1 ) ) ans ++ ; 
		}
		cout << ans << endl ;
	}
	return ;
}

int main () {
	init() ;
	int Kases = input() ; 
	FOR0( kases, Kases ) { solve() ; }
	return 0 ;
}
