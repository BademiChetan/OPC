#include<cstdio>
typedef long long LL;
LL phi(LL n) {
	if (n==1LL) return 0LL;
	LL ret = n;
	for (LL i=2LL; i<=n/i; i++) {
		if (n%i==0LL) ret -= ret/i;
		while(n%i==0) n/=i;
	}
	if ( n != 1LL) ret -= ret/n;
	return ret;
}

LL mPow( LL B, LL P, LL M ) {
    if ( P == 0LL ) return 1LL % M;
    LL ret = mPow( B, P/2LL, M ) % M;
    ret = ( ret * ret ) % M;
    if ( P%2LL == 1LL ) ret = ( (B%M) * (ret%M) ) % M;
    return ret;
}
int main() {
    int ntc;
    scanf("%d", &ntc);
    while(ntc--) {
        LL n,m;
		scanf("%lld %lld", &n, &m);
		LL nx = mPow( 2LL, n, phi(m) );
		printf("%lld\n", mPow(2LL,nx,m));
	}
	return 0;
}
