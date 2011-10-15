#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define SET(x,a) memset(x,a,sizeof(x))
#define all(a) (a.begin(),a.end())
#define rall(a) (a.rbegin(),a.rend())
#define INF (int)1e9
#define EPS (double)1e-9

typedef unsigned long long ULL;
typedef long long LL;
typedef set <int> si;
typedef pair< int,int > ii;
typedef pair< int, ii > pi;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;

LL getans(int b, int k) {
	if (b == 1) return 2;
	LL mid = getans(b/2, k);
	(mid *= mid)%=k;
	if (b%2) (mid *= 2)%=k;
	return mid;
}

const int MAXN=100000+5;
bool p[MAXN];

int etf(int n){
    //precalculate the primes outside using sieve
    //if p[i] is 0, 'i' is prime
    p[0]=p[1]=1;
    for(int i=2;i*i<=MAXN;i++){
        if(!p[i])    for(int j=i*i;j<=MAXN;j+=i)    p[j]=1;              
    }
    int m=n;
    if(n==1)    return 1;
    for(int i=2;(LL)i*i<=n;i++){
        if(!p[i])    if(!(m%i)){
            n=(n/i)*(i-1);
            while(!(m%i))m/=i;
        }
    }
    if(m!=1)    n=(n/m)*(m-1);
    return n;
}


int main() {
	int T = GI;
	while(T--) {
		int N = GI, K = GI;
		int p = etf(K);
		int po = getans(N, p);
		printf("%d\n", (int)getans(po, K));
	}	
	return 0;
}
