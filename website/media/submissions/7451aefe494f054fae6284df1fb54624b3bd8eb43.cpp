#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

bool isprime(int x) {
	for(int i=2; (i*i)<=x; i++) if(x%i == 0) return false;
	return true;
}

bool isnp[100009];
const int MAX = 2000000000;

ll modpow(ll n, ll e, ll mod) {
	if(e==0) return 1ll;
	if(e==1) return (n%mod);
	ll x = modpow(n, e/2, mod);
	x = (x*x)%mod;
	if(e&1) x = (x*n)%mod;
	return x;
}

int main() {
	memset(isnp, 0, sizeof(isnp));
	for(int i=2; (i*i) <= MAX; i++) {
		if(isnp[i]) {
			for(int j=i+i; (j*j)<=MAX; j+=i) isnp[j]=1;
		}
	}
	
	
	int T; cin>>T;
	
	ll n, k, K;
	while(T--) {
		cin>>n>>k;
		K = k;
		ll phi = 1;
		int e;
		for(int p=2; (p*p)<=k; p++) {
			if(isnp[p]) continue;
			
			// p is prime
			if(k%p == 0) {
				phi *= (p-1);
				k /= p;
				
				while(k%p == 0) {
					phi *= p;
					k /= p;
				}
			}
		}
		if(k>1) phi *= (k-1);
		
		//cout<<"phi = "<<phi<<endl;
		
		ll r = modpow(2, n, phi);
		ll ans = modpow(2, r, K);
		//cout<<"r = "<<r<<endl;
		cout<<ans<<endl;
	}

}