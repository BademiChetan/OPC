
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

int main()
{
	int T,n,a[110],i,j,sum;
	iscan(T);
	while(T--)
	{
		iscan(n);
		REP(i,n)
			iscan(a[i]);
		int t = 1;
		i = n-2;
		while(i>=0)
		{
			a[i] = a[i]+a[i+1]-t;
			++t;
			--i;
		}
		if(a[0] % 2 == 0)
			printf("LOSE\n");
		else
			printf("WIN\n");

	}
	return 0;
}
