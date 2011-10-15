
#include<iostream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define llscan(n) scanf("%lld",&n)
#define cscan(n) scanf("%c",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP make_pair
#define PB push_back
#define LL long long
#define _MAX 10000
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(i=0;i<n;++i)

int solve(int y, int x)
{
	if(x == 0)
		return y;
	if(x == 1)
	{
		if(y&1)
			return y-1;
		return y+1;
	}

	int lg = 2;
	while(lg*2<=x)	lg = lg*2;
	if(y/lg % 2 == 0)
	{
		return solve(y+lg, x-lg);
	}
	else
		return solve(y-lg, x-lg);
}

int main()
{
	int T,x,y,ans;
	iscan(T);
	while(T--)
	{
		iscan(x);
		iscan(y);
		ans = solve(y, x);
		printf("%d\n",ans);
	}
	return 0;
}
