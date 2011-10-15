#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
using namespace std;

#define fi first
#define sc second
#define cs c_str
#define mp make_pair
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define RESET(a,b) memset( (a), b, sizeof(a) )
#define ren(a,b,c) for (int a=b; a<c; ++a)
#define renl(a,b,c) for (ll a=b; a<c; ++a)
#define red(a,b,c) for (int a=b; a>=c; --a)
#define redl(a,b,c) for (ll a=b; a>=c; --a)
#define repi(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

const double eps = 1e-9;
typedef long long ll;
typedef pair <int,int> pii;

//lintaor1's template

int main()
{
	int T;
	
	scanf("%d",&T);
	while (T--)
	{
		int gjl=0, gnp=0, n, i;
		
		scanf("%d",&n);
		ren (x,0,n)
		{
			scanf("%d",&i);
			++( (i&1)?gjl:gnp );
		}
		
		if ((n>>1)&1)
		{
			if (gjl!=gnp) printf("WIN\n"); else printf("LOSE\n");
		}
		else
		{
			if (gjl==gnp) printf("WIN\n"); else printf("LOSE\n");
		}
	}
	
	return 0;
}
