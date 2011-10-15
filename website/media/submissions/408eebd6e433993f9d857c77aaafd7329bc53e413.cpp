#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

int n, mod;
const int a = 2, e = 2;

int expo(int a, int e, const int MOD) {
    int r = 1;
    while (e > 0) {
        if (e&1) {
            r = (r * (ll)a) % MOD;
        }
        a = (a * (ll)a) % MOD;
        e >>= 1;
    }
    return r;
}

int main(int argc, char** argv) {
	int runs; s(runs);
    while (runs-- > 0) {
        s(n); s(mod);
        vector<int> primes; int tmp = mod;
        for (int i=3; i*i <= tmp; i++) {
            bool in = 0;
            while (tmp%i == 0) {
                tmp /= i; in = 1;
            }
            if (in) primes.pb(i);
        }
        if (tmp > 1) primes.pb(tmp);
        int phi = mod;
        for (int i=0; i < primes.size(); i++) {
            
            phi /= primes[i];
            phi *= primes[i] - 1;
            //cout << primes[i] << " and " << phi << endl;
        }
        int z = expo(2, n, phi);
        int y = expo(2, z, mod);
        printf("%d\n", y);
    }
	return 0;
}
