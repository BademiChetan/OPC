/* AntiThesis, IIIT-Hyderabad */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 50010
#define INF 100000000


char str[MX];


/*  ------------------- Fast Input ----------------   */

#define BUFSIZE (100000)
char inputbuffer[BUFSIZE];
char *ioptr=inputbuffer+BUFSIZE,*ioend=inputbuffer+BUFSIZE;
int input_eof=0;

#define getchar() ({if (ioptr >= ioend) init_input(); *ioptr++;})
#define eof() (ioptr>=ioend && input_eof)
#define eoln() ({if(ioptr >= ioend) init_input(); *ioptr == '\n';})

void init_input()
{
	if (input_eof)
		return;
	int existing = BUFSIZE - (ioend - inputbuffer);
	memcpy(inputbuffer, ioend, existing);
	int wanted = ioend - inputbuffer;
	int count=fread(inputbuffer + existing, 1, wanted, stdin);
	if (count < wanted)
		input_eof = 1;
	ioend = inputbuffer + BUFSIZE - (wanted - count);
	while (*--ioend > ' ');
	ioend++;
	ioptr=inputbuffer;
}

inline void non_whitespace()
{
	for(;;)
	{
		if(ioptr>=ioend)
			init_input();
		if(*ioptr>' ')
			return;
		ioptr++;
	}
}

inline int getint()
{
	non_whitespace();
	int neg=0;
	if(*ioptr=='-')
	{
		ioptr++;
		neg=1;
	}
	int n=0;
	while(*ioptr>' ')
		n=(n<<3)+(n<<1)+*ioptr++-'0';
	ioptr++;
	if(neg)
		n=-n;
	return n;
}

inline void getString(int n)
{
	non_whitespace();
	for(int i=0;i<n;i++) str[i] = *ioptr++;		
}

/*  -------------- End of Fast Input ------------- */



/* ---- Manber-Myer : O(n log(n) ) Suffix Array Construction ---- */

#define SN 50010

int sarr[SN], sinv[SN];
int cnt[SN], nxt[SN];
bool Bh[SN], B2h[SN];

bool cmpss1(int i, int j){ return str[i]<str[j]; }

void SuffixSort(int n)
{
	int i, j, k, h, s, b;
	for(i=0;i<n;i++) sarr[i] = i;
	sort(sarr,sarr+n,cmpss1);

	SET(Bh,false); SET(B2h,false);
	for(i=1,Bh[0]=true;i<n;i++) 
		Bh[i] = str[sarr[i]]!=str[sarr[i-1]];

	for(h=1;h<n;h<<=1)
	{
		for(i=b=0;i<n;i=j)
		{
			sinv[sarr[i]] = i;
			for(j=i+1;j<n&&!Bh[j];++j) sinv[sarr[j]] = i;
			nxt[i]=j; b++;
		}

		if(b==n) break;
		SET(cnt,0);
		cnt[sinv[n-h]]++;
		B2h[sinv[n-h]] = true;

		for(i=0;i<n;i=nxt[i])
		{
			for(j=i;j<nxt[i];++j)
			{
				s = sarr[j] - h;
				if(s<0) continue;
				sinv[s]+=cnt[sinv[s]]++; 
				B2h[sinv[s]]=true;  
			}

			for(j=i;j<nxt[i];++j)
			{
				s = sarr[j] - h;
				if(s<0 || !B2h[sinv[s]]) continue;
				for(k=sinv[s]+1;!Bh[k]&&B2h[k];k++) B2h[k] = false;
			}
		}

		for(i=0;i<n;++i) sarr[sinv[i]] = i, Bh[i]|=B2h[i];
	}
}

/* ---- End of Manber-Myer ---- */



/* LCP computation of consecutive suffixes - O( n ) */

int lcp[SN];

void lcpConsecutive(int n)
{
	lcp[0] = lcp[n-1] = lcp[n] = 0;
	int i, j, h;
	for(lcp[0]=i=h=0;i<n;++i)
	{
		if(sinv[i]==0) continue;
		for(j=sarr[sinv[i]-1];i+h<n&&j+h<n&&str[i+h]==str[j+h];h++);
		lcp[sinv[i]] = h;
		if(h>0) h--;
	}
}

/* ---- End of LCP ---- */

int n;
int st[4*MX];

#define lc(i) ((i)<<1)
#define rc(i) (((i)<<1)+1)

void initST(int p,int l,int h)
{
	if(l==h){ st[p]=lcp[l]; return; }
	int m = (l+h)>>1;
	initST(lc(p),l,m);
	initST(rc(p),m+1,h);
	st[p] = min(st[lc(p)],st[rc(p)]);
}

int mini(int p,int l,int h,int a,int b)
{
	if(b<l || h<a) return INF;
	if(a<=l && h<=b) return st[p];
	int m = (l+h)>>1;
	return min(mini(lc(p),l,m,a,b),mini(rc(p),m+1,h,a,b));
}

int solve(int m,int k)
{
	int ind = sinv[m], r1 = 0, r2 = 0;


	//left
	if(ind>0 && lcp[ind]>=k)
	{
		int lo = 1, hi = ind;
		if(mini(1,0,n-1,lo,ind)>=k) r1+=ind-lo+1;
		else
		{
			while(hi-lo>1)
			{
				int mid = (lo+hi)>>1;
				if(mini(1,0,n-1,mid,ind)>=k) hi=mid;
				else lo=mid;
			}
			r1+=ind-hi+1;
		}
	}

	//right
	if(ind+1<n && lcp[ind+1]>=k)
	{
		int lo = ind+1, hi = n-1;
		if(mini(1,0,n-1,ind+1,hi)>=k) r2+=hi-lo;
		else
		{
			while(hi-lo>1)
			{
				int mid = (lo+hi)>>1;
				if(mini(1,0,n-1,ind+1,mid)>=k) lo=mid;
				else hi=mid;
			}
			r2+=lo-(ind+1);
		}
	}

	/*
	   REP(i,n) printf("%d ",lcp[i]);
	   puts("");
	   printf("ind = %d, k = %d\n",ind,k);
	   printf("%d %d\n\n",r1,r2);
	 */

	return r1+r2+1;
}

int main()
{
	for(int t=getint();t--;)
	{
		n = getint();
		//scanf(" %s",str);
		getString(n);
		//printf("n = %d, %s\n",n,str);
		SuffixSort(n);
		lcpConsecutive(n);
		initST(1,0,n-1);
		for(int q=getint();q--;)
		{
			//int m = SI, k = SI;
			int m = getint(), k = getint();
			printf("%d\n",solve(m,k));
		}
	}

	return 0;
}
