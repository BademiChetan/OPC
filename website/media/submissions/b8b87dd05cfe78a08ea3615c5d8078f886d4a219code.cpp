#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stack>
#include <cassert>
#include <memory.h>
#ifdef NEV_DEBUG
#include <ctime>
#endif
#pragma comment(linker,"/STACK:64000000")
using namespace std;
const double pi = 3.1415926535897932384626433832795;
double eps=1e-9; 
//double eps=1e-15; // atan up to 1e-15

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

#define sz size()
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(int i=(a),_b(b); i<_b; ++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b); i>=_b; --i)
#define CLR(a,b) memset(a,b,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define sqr(a) ((a)*(a))

char ch[1<<20];
inline string gs() {scanf("%s",ch); return string(ch);}
inline string gl() {gets(ch); return string(ch);}
inline int gi() {int x;scanf("%d",&x); return x;}
void error(){int ttt=0; cout << 7/ttt;}
LL gcd(LL a, LL b) {
	return (!a)?b:gcd(b%a,a);
}
LL mod=1000*1000*1000 + 7;
inline LL MUL(LL a, LL b) {return 1ll*a*b%mod;}
inline LL ADD(LL a, LL b) {return (a+b>=mod)?a+b-mod:a+b;}
inline int SUB(int a, int b) {return (a-b<0)?a+mod-b:a-b;}

int isprime(int x) {
	FOR(i,2,x) if (x%i==0) return 0; else if (i*i>x) break;
	return 1;
}

int brut(int n, int k) {
	int r=0;
	FOR(i,0,1<<n) {
		int s=0;
		FOR(j,0,n) if (i&(1<<j)) s+=j+1;
		if (s%k==0) ++r;
	}
	return r;
}

LL powmod(LL x, int n) {
	LL r=1;
	while(n) {
		if (n&1) r=MUL(r,x);
		n>>=1;
		x=MUL(x,x);
	}
	return r;
}

int phi(int x) {
	int r=x;
	for(int i=2; i*i<=x; ++i) {
		if (x%i==0) {
			r-=r/i;
			while(x%i==0) x/=i;
		}
	}
	if (x>1) r-=r/x;
	return r;
}

LL solve(int n, int k) {
	LL res=0;
	for(int i=1; i*i<=k; ++i) {
		if (k%i==0) {
			if (i&1) {
				res=ADD(res,MUL(powmod(2,n/i),phi(i)));
			} 
			if(i!=k/i && ((k/i)&1)) {
				res=ADD(res,MUL(powmod(2,n/(k/i)),phi(k/i)));
			}
		}
	}
	return MUL(res,powmod(k,mod-2));
}

int main() {	
#ifdef NEV_DEBUG
    freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	/*
	freopen("in.txt","w",stdout);
	cout << 1 << endl;
	cout << 50000 << endl;
	string s(50000,'a');
	FOR(i,0,1000) s[rand()%50000]='b';
	cout << s << endl;
	cout << 50000 << endl;
	FOR(i,0,50000) {
		int x=rand()%50000;
		int k=1+rand()%(50000-x);
		cout << x << " " << k << endl;
	}
	exit(0);
	//*/
	 
    clock_t beg = clock();
#else
    //freopen("gas.in","r",stdin);
    //freopen("gas.out","w",stdout);	 
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if (!isprime(mod)) {
	//	cerr << "WWWWW"<<endl; exit(0);
	//}
	/*
	FOR(i,0,200) {
		int x=1+rand()%20;
		int k=1+rand()%x;
		while(x%k) {
			k=1+rand()%x;
		}
		int v1=brut(x,k)%mod;
		int v2=solve(x,k);
		if (v1!=v2) {cerr << "WRONG!!!\n"; exit(0);}
		else cerr << "ok";
	}cerr << endl;
	//*/
	

	int tn=gi();
	while(tn--) {
		int x=gi();
		int y=gi();
		while(x%y || x<y);
		cout << brut(x,y) << endl;
	}
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NEV_DEBUG
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}