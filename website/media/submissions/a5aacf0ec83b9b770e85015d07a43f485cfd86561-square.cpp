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

pii i;

int f( pii v, pii l, pii h )
{
	if (v.fi == v.sc) return v.fi;
	
	int mid = (v.fi+v.sc)>>1;
	pii p = mp( (l.fi+h.fi)>>1, (l.sc+h.sc)>>1 );
	
	if ((i.fi <= p.fi) && (i.sc <= p.sc))
	{
		return f( mp( v.fi, mid ), l, p );
	}
	
	else if ((i.fi > p.fi) && (i.sc > p.sc))
	{
		return f( mp( v.fi, mid ), mp( p.fi+1, p.sc+1 ), h );
	}
	
	if ((i.fi <= p.fi) && (i.sc > p.sc))
	{
		return f( mp( mid+1, v.sc ), mp( l.fi, p.sc+1 ), mp( p.fi, h.sc ) );
	}
	
	else
	{
		return f( mp( mid+1, v.sc ), mp( p.fi+1, l.sc ), mp( h.fi, p.sc ) );
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d", &i.fi, &i.sc);
		printf("%d\n", f( mp( 0,(1<<20)-1 ), mp( 0,0 ), mp( (1<<20)-1,(1<<20)-1 ) ));
	}
	return 0;
}
