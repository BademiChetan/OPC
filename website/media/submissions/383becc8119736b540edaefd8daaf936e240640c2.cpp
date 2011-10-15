#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
using namespace std;
int n,k;
int g[1000000+32];
int main()
{
	int X;
	scanf("%d",&X);
	while(X--)
	{
		scanf("%d%d",&n,&k);
		set<int>S;
		S.insert(4);
		g[1]=4;
		long long  prev=4,now,pos=2;
		while(1)
		{
			now=prev*prev;
			now%=k;
			if(S.find(now)!=S.end())break;
			g[pos++]=now;
			S.insert(now);
			prev=now;
		}
		if(n<pos)
		{
			printf("%d\n",g[n]);
			continue;
		}
		int idx;
		for(int i=1;i<pos;i++)if(now==g[i])
		{
			idx=i;
			break;
		}
		n-=idx;
		int l=pos-idx;
		printf("%d\n",g[idx+n%l]);






	}

	return 0;
}
