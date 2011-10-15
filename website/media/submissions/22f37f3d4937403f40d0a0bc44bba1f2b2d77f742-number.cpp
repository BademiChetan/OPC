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

bool S(int n, int gj, int gn);
bool P(int n, int gj, int gn);

int dp[2][102][102];

int main()
{
	RESET(dp,-1);
	dp[0][1][0] = 1; dp[0][0][1] = 0;
	dp[1][1][0] = 1; dp[1][0][1] = 0;
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
		
		printf("%s\n", (S( n&1, gjl, gnp ))?"WIN":"LOSE");
	}
	
	return 0;
}

bool S(int n, int gj, int gn)
{
	if ((gj<0) || (gn<0)) return 1;
	if (dp[n][gj][gn] != -1) return dp[n][gj][gn];
	int &ret = dp[n][gj][gn] = 0;
	if ( (P( n, gj-1, gn )) || (P( n, gj+1, gn-2 )) ) ret = 1;
	return ret;
}

bool P(int n, int gj, int gn)
{
	if ((gj<0) || (gn<0)) return 0;
	if (dp[n][gj][gn] != -1) return dp[n][gj][gn];
	int &ret = dp[n][gj][gn] = 1;
	if ( (!S( n, gj, gn-1 )) || (!S( n, gj-2, gn+1 )) ) ret = 0;
	return ret;
}
