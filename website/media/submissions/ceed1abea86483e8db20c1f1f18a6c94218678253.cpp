#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOREACH(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

typedef long long LL; typedef pair<LL,LL> PLL;
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

int nums[3];
int n = 3;
const int LIM=1<<10;

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


// ST = res
// ND = mod
LL __chinese( vector< PLL > data ) {
	LL M = 1; FOREACH(it,data) M *= it->ND;
	LL ret = 0;
	// DEBUG(M);
	FOREACH(it,data) {
		LL Mi = M / it->ND;
		LL temp = it->ST * Mi * __inverse(Mi,it->ND);
		// DEBUG(temp);
		ret += temp;
		ret %= M;
	}
	return ret;
}

LL brutal(LL base,int pos, LL M, int ppow,int prime) {

	if(pos==n) return base%M;
	int j = n;
	LL pj = 1;
/*
	int sj = 0;
	LL tempBase=base;
	while(tempBase%prime==0) {
		tempBase /= prime;
		sj++;
	}
*/

	//printf("start = %d\n",j);
	while(j-1 >= pos) {
		LL k = 1;
		REP(loop,pj) {
			if(k >= LIM) return 0;
			k*=nums[j-1];
		}
		pj = k;
		if(pj >= LIM) return 0;
		j--;
	}
	return __fastpow(base,pj,M);
}

LL solve(int,LL);
LL doit(int,int);

PLL solve(int pos, LL M, int ppow,int prime) {
	LL a = nums[pos];
	if(__gcd(a,M)==1) {
		LL b = solve( pos+1, phi((int)M) );
		return MP( __fastpow(a,b,M), M );
	}
	return MP( brutal(a, pos+1, M, ppow, prime), M);
}

LL solve(int pos,LL M) {
	if(M==1) return 0;
	if(pos==n) return 1;
	LL a = nums[pos];
	if(a==1) return a % M;
	if(a==0) return 0;

	LL m = M;

	vector< PLL > data;
	for(LL i=2;i*i<=m;i++) {
		if(m%i!=0) continue;
		LL p=1;
		int ppow = 0;
		while(m%i==0) {
			m/=i;
			p*=i;
			ppow++;
		}
		data.PB( solve(pos, p, ppow, i) );
	}
	if(m>1) data.PB( solve(pos, m, 1, m) );


	LL resCH = __chinese(data);

	return resCH;
}



int main() {
	REP(nc,getint()) {
		int N = getint();
		int K = getint();
		nums[0] = nums[1] = 2;
		nums[2] = N;
		cout<<solve(0,K)<<endl;
	}
	return 0;
}
