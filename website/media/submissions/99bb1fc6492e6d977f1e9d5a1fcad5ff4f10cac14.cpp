#include <iostream>
#include <cstdio>
#include <vector>

#define REP(i, n) for(int i=0; i<int(n); i++)
const int MOD = 1000000007;

using namespace std;

// solve (n, n)
vector<int> solve_one(int n) {
	vector<int> ret(n, 0), tmp(n,0);
	ret[0] = 1;
	REP(i, n) {
		REP(j,n) tmp[j] = ret[j];
		REP(j,n) ret[j] += tmp[(n+j-i)%n];
	}
	return ret;
}

// solve (2k , k)
vector<int> solve_two(int k) {
	vector<int> a = solve_one(k);
	vector<int> ret(k, 0);
	REP(i, k) {
		REP(j, k) {
			ret[(i+j)%k] += a[i]*a[j];
		}
	}
	return ret;
}

vector<int> solve_three(int k) {
	
}


void print(const vector<int> &v) {
	REP(i, v.size()) printf("%d ", v[i]); printf("\n");
}

typedef long long ll;
typedef pair<ll, ll> pll;

pll egcd(ll a, ll b) {
	if(b==0) return pll(1,0);
	ll q = a/b;
	pll tmp = egcd(b,a%b);
	pll ret = pll(tmp.second, tmp.first - q * tmp.second);
	return ret;
}

// assume that x < mod
ll invmod(ll x, ll mod) {
	pll tmp = egcd(mod, x);
	ll ret = tmp.second;
	ret = ((ret%mod) + mod)%mod;
	return ret;
}

ll modpow(ll n, ll e, ll mod) {
	if(e==0) return 1ll;
	if(e==1) return (n%mod);
	ll x = modpow(n, e/2, mod);
	x = (x*x)%mod;
	if(e&1) x = (x*n)%mod;
	return x;
}

int main() {
	int T; cin>>T;
	//print(solve_one(2));
	while(T--) {
		ll n, p, k;
		cin>>n>>k;
		p = n/k;
		if(n == 2ll) cout<<2<<endl;
		else cout<<((((modpow(2, n, MOD) - modpow(2, p, MOD))*invmod(k, MOD))%MOD + modpow(2,p,MOD))% MOD + MOD)%MOD<<endl;
	}
}
