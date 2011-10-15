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

int C[11];
int L[11];
int W[11];
int N;

vector<PII> E;
PII v1[1<<20],v2[1<<20];

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
		int n=gi();
		N=n;
		int w=gi();
		E.clear();
		FOR(i,0,n) {
			scanf("%d%d%d",C+i,W+i,L+i);
			for(int j=1; j<=L[i]; j*=2) {
				E.pb(mp(C[i]*j,W[i]*j));
				L[i]-=j;
			}
			if (L[i]) E.pb(mp(C[i]*L[i],W[i]*L[i]));
		}
		if (E.sz==1) {
			printf("%d\n",E[0].second);
		}
		int nn1=0;
		int nn2=0;
		int n1=E.sz/2;
		FOR(m,0,1<<n1) {
			int c=0;
			int w=0;
			FOR(j,0,n1) if (m&(1<<j)) {
				c+=E[j].first;
				w+=E[j].second;
			}
			v1[nn1++]=mp(c,w);
		}
		int n2=E.sz-n1;
		FOR(m,0,1<<n2) {
			int c=0;
			int w=0;
			FOR(j,0,n2) if (m&(1<<j)) {
				c+=E[n1+j].first;
				w+=E[n1+j].second;
			}
			v2[nn2++]=mp(c,w);
		}
		sort(v2,v2+nn2);
		FOR(i,1,nn2) v2[i].second=max(v2[i].second,v2[i-1].second);
		int best=0;
		FOR(i,0,nn1) {
			int r=v1[i].second;
			int c=w-v1[i].second;
			int p=upper_bound(v2,v2+nn2,mp(c,2000*1000*1000))-v2;
			if (p==0) continue;
			--p;
			r+=v2[p].second;
			if (best<r) best=r;
		}

		printf("%d\n",best);
	}

	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NEV_DEBUG
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}