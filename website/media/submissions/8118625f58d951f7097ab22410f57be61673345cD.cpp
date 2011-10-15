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
int ntest,x,y;
int mod = 1000000007;

LL modpow(int a, int b){
    if(b==1) return a%mod;
    if(b==0) return 1%mod;
    LL r = modpow(a,b/2);
    if(b&1) return r*r%mod*a%mod;
    else return r*r%mod;
}

LL N,K;
int main () {
    //freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    scanf("%d",&ntest);
    while(ntest--){
        scanf("%lld %lld",&N,&K);
        LL temp = modpow(2,N);
        //cout << temp << endl;
        int t=N/K;
        LL temp2 = modpow(2,t)*(K-1)%mod;
        temp = (temp+temp2+mod)%mod;
        //cout << modpow(K,mod-2) << endl;
        temp = temp*modpow(K,mod-2)%mod;
        cout << temp << endl;
    }
    return 0;
}
