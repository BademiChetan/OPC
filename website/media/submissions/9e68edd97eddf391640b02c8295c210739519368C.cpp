#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>

#define oo 1000000005
#define eps 1e-11

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

using namespace std;

const double PI = 2.0 * acos (0.0);

typedef long long LL;
typedef pair <int, int> PII;

void factor( int n, vector< int > &v ){
    int sq = int( sqrt( ( double )n ) );
    for( int i = 2; i <= sq; i++ ){
        if( n % i ) continue;
        v.push_back( i );
        n /= i--;
	   sq = int( sqrt( ( double )n ) );
    }
    if( n > 1 ) v.push_back( n );
}

int phi( int n ){
    vector< int > p;
    factor( n, p );
    for( int i = 0; i < ( int )p.size(); i++ )
    {
        if( i && p[i] == p[i - 1] ) continue;
        n /= p[i];
        n *= p[i] - 1;
    }
    return n;
}

int ntest; 
LL m,mod;
int k;

LL modpow(int b){
    if(b==1) return 2%mod;
    if(b==0) return 1%mod;
    LL r = modpow(b/2);
    if(b&1) return r*r%mod*2%mod;
    else return r*r%mod;
}

int main () {
   //freopen("test.in","r",stdin);    freopen("test.out","w",stdout);
   scanf("%d",&ntest);
   while(ntest--){
        scanf("%d %lld",&k,&m);
        mod = 1LL*phi(m);
        //cout << mod << endl;
        LL temp = modpow(k);
        mod = m;
        printf("%lld\n", modpow(temp));
   }
   return 0;
}
   
