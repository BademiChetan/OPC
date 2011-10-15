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

const int LEN=1<<16;
int p[LEN], cnt[LEN], c[LEN];
int pn[LEN],cn[LEN];
int C[17][LEN];


int build_sufar(string s) {
	int n=s.sz;
	CLR(cnt,0);
	for (int i=0; i<n; ++i)
		++cnt[(int)s[i]];
	for (int i=1; i<256; ++i)
		cnt[i] += cnt[i-1];
	for (int i=n-1; i>=0; --i)
		p[--cnt[(int)s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i=1; i<n; ++i) {
		if (s[p[i]] != s[p[i-1]]) ++classes;
		c[p[i]] = classes-1;
	}
	CPY(C[0],c);

	int maxh=0;
	for (int h=0; (1<<h)<n; ++h) {
		for (int i=0; i<n; ++i) {
			pn[i] = p[i] - (1<<h);
			if (pn[i] < 0) pn[i] += n;
		}
		CLR(cnt,0);
		for (int i=0; i<n; ++i)
			++cnt[c[pn[i]]];
		for (int i=1; i<classes; ++i)
			cnt[i] += cnt[i-1];
		for (int i=n-1; i>=0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i=1; i<n; ++i) {
			int mid1 = (p[i] + (1<<h)) % n, mid2 = (p[i-1] + (1<<h)) % n;
			if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
				++classes;
			cn[p[i]] = classes-1;
		}
		CPY(c,cn);
		CPY(C[h+1],cn);
		maxh=h+1;
	}
	return maxh;
}

// k =  max(i) : (1<<(i+1))>=l
int compare (int i, int j, int l, int k) {
	pair<int,int> a = make_pair (C[k][i], C[k][i+l-(1<<(k-1))]);
	pair<int,int> b = make_pair (C[k][j], C[k][j+l-(1<<(k-1))]);
	return a == b ? 0 : a < b ? -1 : 1;
}

// LCP LOG
int lcp(int a, int b, int h) {
	int maxh=h; // maxh in build;
	int res=0;

	int x=maxh+1;
	while(x--) {
		if (C[x][a]==C[x][b]) {
			res+=1<<x;
			a+=1<<x;
			b+=1<<x;
		}
	}
	return res;
}

int ID[55555];

int par[55555];
int ac[55555];
int getp(int x) {return par[x]=(par[x]==x?x:getp(par[x]));}
void join(int a, int b, int c) {
	a=getp(a);
	b=getp(b);
	if (rand()&1) swap(a,b);
	par[a]=b;
	ac[b]=c;
}
int Z[55555];

int RES[55555];
pair<PII,int> RQ[55555];
PII G[55555];

int main() {	
#ifdef NEV_DEBUG
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
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
	//FOR(i,0,10) FOR(j,0,10) printf("%2d%c",rec(i,j),(j==9)?'\n':' ');
	//exit(0);

	//cout << build_sufar(string(50001,'a')) << endl;

	int tn=gi();
	while(tn--) {
		int n=gi();
		string s=gs()+' ';
		//FOR(i,0,s.sz-1) if (!isalpha(s[i])) error();

		int h=build_sufar(s);
		FOR(i,0,s.sz) ID[p[i]]=i;
		int q=gi();
		int Gn=0;
		FOR(i,0,s.sz-1) G[Gn++]=mp(lcp(p[i],p[i+1],h),i);

		int RQn=0;

		for(int i=0; i<q; ++i) {
			int x=ID[gi()];
			int k=gi();
			RQ[RQn++]=mp(mp(k,x),i);
		}
		sort(G,G+Gn);
		sort(RQ,RQ+RQn);
		FOR(i,0,s.sz) {par[i]=ac[i]=i; Z[i]=1;}
		int p1=Gn-1;
		RFOR(i,RQn,0) {
			while(p1>=0 && G[p1].first>=RQ[i].first.first) {
				int zz=Z[ac[getp(G[p1].second)]]+Z[ac[getp(G[p1].second+1)]];
				join(getp(G[p1].second),getp(G[p1].second+1),ac[getp(G[p1].second)]);
				Z[ac[getp(G[p1].second)]]=zz;
				--p1;
			}
			RES[RQ[i].second]=Z[ac[getp(RQ[i].first.second)]];
		}
		FOR(i,0,q) printf("%d\n",RES[i]);
	}

	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NEV_DEBUG
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}