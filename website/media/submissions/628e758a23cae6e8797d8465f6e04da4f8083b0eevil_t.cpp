
//Author : Deepan
#include <vector>
#include <list>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <deque>
#include <fstream>
#include <stack>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class A, class B> A cvt(B x) {stringstream s;s<<x;A r;s>>r;return r;}

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REV(i,a,b) for(int i= (int )a ; i >= (int)b ; --i)
#define REP(i,n) FOR(i,0,n)
#define DEP(i,n) REV(i,n,0)
#define PB push_back
#define PP pop()
#define EM empty()
#define INF 1000000000
#define PF push_front
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define V(x) vector< x >
#define Debug false
#define PRINT(x)        cout << #x << " " << x << endl
#define LET(x,a) 	    __typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define PRESENT(c,x) 	((c).find(x) != (c).end())
#define SZ(x) 		x.size()
#define CPRESENT(c,x) 	(find(c.begin(),c.end(),x) != (c).end())
#define D(N) 		int N
#define S(N)		scanf("%d",&N)
#define T(t) int t;scanf("%d",&t);while(t--)
#define Pln(N)		printf("%d\n",N);
#define P(N)		printf("%d ",N);
#define FASTIO          1

typedef pair<int,int>   PI;
typedef pair<int,PI>    TRI;
typedef V( int )        VI;
typedef V( PI  )        VII;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

/* FastIO, generally required these days ;) */

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
inline void FlushFASTIO(vi ) {
   fwrite_unlocked(OutFile,opos-OutFile,1,stdout);	
}
#endif

long long int p(long long int n,long long int k)
{
	if(n==0)
		return 1;
	long long int r=p(n/2,k);
	if(n%2)
		r=(((r*r)%k)*2)%k;
	else
		r=(r*r)%k;
	return r%k;

}
int main()
{
	long long int n,k;
	T(t)
	{
	//	S(n);
	//	S(k);
		scanf("%lld%lld",&n,&k);

		printf("%lld\n",(p(n*2,k))%k);
	}

	return 0;
}
