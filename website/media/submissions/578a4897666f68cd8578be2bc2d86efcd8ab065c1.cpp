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
int g[128];
int main()
{
	int X;
	scanf("%d",&X);
	while(X--)
	{
		int  t,n,sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			sum+=t;
		}
		int diff=0;
		for(int i=0;i<n-1;i++)diff+=(i+1);
		sum = sum-diff;
		puts(sum%2?"WIN":"LOSE");

	}

	return 0;
}
