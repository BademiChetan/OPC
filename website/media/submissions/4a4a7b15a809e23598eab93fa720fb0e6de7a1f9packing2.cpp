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

/*  -------------- End of Fast Input ------------- */

#define MX ((1<<20)+5)

int N, W, ans;
int w[11], v[11], f[11];

PI T1[MX], T2[MX];
int ww[55], vv[55];

void solve1(int l,int h,int &n)
{
	int m = 0;

	FOR(i,l,h)
		for(int j=1,s=0;j<=f[i];s+=j,j<<=1)
		{   
			int k = j;
			if(s+j>f[i]) k = f[i] - (j-1);
			ww[m] = w[i]*k, vv[m++] = v[i]*k;
		}

	n = 1;
	T1[0] = MP(0,0);

	REP(i,(1<<m))
	{
		int cw = 0, cv = 0;
		REP(j,m) if((i&(1<<j))) cw+=ww[j], cv+=vv[j];
		if(cw<=W){ T1[n++] = MP(cw,cv); ans=max(ans,cv); }
	}

	//printf("n = %d\n",n);
}

void solve2(int l,int h,int &n)
{
	int m = 0;

	FOR(i,l,h)
		for(int j=1,s=0;j<=f[i];s+=j,j<<=1)
		{   
			int k = j;
			if(s+j>f[i]) k = f[i] - (j-1);
			ww[m] = w[i]*k, vv[m++] = v[i]*k;
		}

	n = 1;
	T2[0] = MP(0,0);

	REP(i,(1<<m))
	{
		int cw = 0, cv = 0;
		REP(j,m) if((i&(1<<j))) cw+=ww[j], cv+=vv[j];
		if(cw<=W){ T2[n++] = MP(cw,cv); ans=max(ans,cv); }
	}
	
	//printf("n = %d\n",n);
}

int main()
{
	int n1, n2;

	for(int t=getint();t--;)
	{
		N = getint();
		W = getint();
		REP(i,N)
		{
			w[i] = getint();
			v[i] = getint();
			f[i] = getint();
		}

		ans = 0;

		if(N<=5)
		{
			solve1(0,N,n1);
			printf("%d\n",ans);
			continue;
		}

		solve1(0,N/2,n1);
		solve2(N/2,N,n2);

		++n1; ++n2;
		sort(T1,T1+n1);
		sort(T2,T2+n2);

		int maxSoFar = 0;
		
		for(int i=n1-1,j=0;i>=0;i--)
		{
			while(j<n2 && T1[i].F + T2[j].F <= W ) maxSoFar = max(maxSoFar,T2[j].S), j--;
			ans = max( ans, T1[i].S + maxSoFar);
		}

		printf("%d\n",ans);
	}

	return 0;
}


