
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

int ET(int n)
{
	int i,ans = n;
	for(i=2;i*i<=n;++i)
	{
		if(n % i == 0)
		{
			ans/=i;
			ans *= (i-1);
		}
		while(n % i == 0)
			n/=i;
	}
	if(n == 1)
		return ans;
	else return (ans/n)*(n-1);
}

LL mypow(LL a, int n, LL BASE)
{
	LL ans = 1LL;
	while(n)
	{
		if(n&1)
			ans = (ans * a)%BASE;
		a = (a*a)%BASE;
		n>>=1;
	}
	return ans;
}

int main()
{
	int T,n;
	LL k;
//	cout<<ET(100)<<endl;
//	cout<<ET(13*17)<<endl;
//	cout<<ET(1000000007)<<endl;
//	cout<<ET(3*3*3*3*2*2)<<endl;
	iscan(T);
	while(T--)
	{
		iscan(n);
		llscan(k);
		if(k == 1)
		{
			printf("0\n");
			continue;
		}
		LL phi = ET(k);
		LL p = mypow(2LL,n,phi);
		LL ans = mypow(2LL,p,k);
		printf("%lld\n",ans);
	}
	return 0;
}
