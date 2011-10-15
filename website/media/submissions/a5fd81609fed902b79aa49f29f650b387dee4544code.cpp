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
int mod=1000*1000*1000+7;
inline int MUL(int a, int b) {return 1ll*a*b%mod;}
inline int ADD(int a, int b) {return (a+b>=mod)?a+b-mod:a+b;}
inline int SUB(int a, int b) {return (a-b<0)?a+mod-b:a-b;}

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

LL powmod(LL x, int n, LL mod) {
	LL r=1;
	while(n) {
		if (n&1) r=1ll*r*x%mod;
		n>>=1;
		x=1ll*x*x%mod;
	}
	return r;
}

int main() {	
#ifdef NEV_DEBUG
    freopen("in.txt","r",stdin);
	/*
	freopen("in.txt","w",stdout);
	
	FOR(i,0,1000) {
		if (rand()&1) printf("?");
		else printf("%d",rand()&1);
	} printf("\n");
	FOR(i,0,500) {
		printf("?",ccc[rand()%3]);
	} printf("\n");
	exit(0);
	//*/
	 
    clock_t beg = clock();
#else
    //freopen("gas.in","r",stdin);
    //freopen("gas.out","w",stdout);	 
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//FOR(i,0,10) FOR(j,0,10) printf("%2d%c",rec(i,j),(j==9)?'\n':' ');
	//exit(0);
	int tn=gi();
	while(tn--) {
		
		LL n=gi();
		LL mod=gi();
		
		n=powmod(2,n,phi(mod));
		cout << powmod(2,n,mod) << endl;
	}

	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NEV_DEBUG
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}