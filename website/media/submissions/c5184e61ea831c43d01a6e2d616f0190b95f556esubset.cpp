#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)

typedef long long LL;
inline int getint() { int x; scanf("%d",&x); return x; }
// Euler Phi Function
int phi(int n)
{
	int ret = n;
	for(int i=2;i*i<=n;++i) {
		if(n%i==0) ret -= ret/i;
		while(n%i==0) n/=i;
	}
	if(n>1) ret-=ret/n;
	return ret;
}

// Powered By TimoAI 2.2

const LL MOD = 1000000007;

LL __fastpow(LL a,LL b,LL m) {
	if(b<=0) return 1;
	if(a==0) return 0;
	LL c = __fastpow(a,b/2,m);
	c=(c*c)%m;
	if(b%2==1) c=(c*a)%m;
	return c;
}

// calc 1/a mod m, gcd(a,m)==1
LL __inverse(LL a,LL m) {
	return __fastpow(a,phi(m)-1,m);
}

LL solve(int N,int M) {
	LL ret = 0;
	for(int i=1;i*i<=M;i+=2) {
		if(M%i!=0) continue;
		int a = i;
		int b = M/i;
		ret += (phi(a) * __fastpow(2,N/a,MOD));
		ret %= MOD;
		if(a!=b && b%2==1) {
			ret += (phi(b) * __fastpow(2,N/b,MOD));
			ret %= MOD;
		}
	}
	return (ret * __inverse(M,MOD)) % MOD;
}

int main() {
	REP(nc,getint()) {
		int N=getint();
		int K=getint();
		cout<<solve(N,K)<<endl;
	}
	return 0;
}
