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
int ntest; LL x,y;

long long modpow(LL b, LL mod){
    if(b==1) return 4;
    if(b==0) return 2;
    LL temp = modpow(b/2,mod);
    if(b&1){
        return temp*temp%mod*2;
    }
    return temp*temp%mod;
}
int main () {
//freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    scanf("%d",&ntest);
    while(ntest--){
        scanf("%lld %lld",&x,&y);
        printf("%d\n",modpow(x,y));
    }    
    return 0;
}
