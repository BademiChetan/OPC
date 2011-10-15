//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;



/*
 *
 * Naive O(N * (logN)^2) suffixArray
 * I here never create suffix array though, only ranks are stored in P
 */

typedef pair<int,int> pii;

const int maxn = 1 << 16;
const int maxlog = 16;
int P[maxlog+1][maxn], Q[maxn];
pair< pii, int> suff[maxn];

int L, stp, len;

void suffixArray(char * s)
{
	 L = strlen(s);
	for(int i = 0; i < L; i++)
		P[0][i] = s[i] - 'a';
	for(stp = 1, len = 1; (len >> 1) < L; stp ++, len <<= 1)
	 {
		for(int i = 0; i < L; i++)
			   suff[i] = make_pair( pii(P[stp-1][i], i + len < L ? P[stp-1][i + len] : -1), i);
		sort(suff, suff + L);
		for(int i = 0, r = 0; i < L; i++, r++)
		  {
			   P[stp][suff[i].second] = r;
			while( i + 1 < L && suff[i].first == suff[i+1].first)
					P[stp][suff[++i].second] = r;
		  }
	 }
}

int lcp(int x, int y)		// What is the length of the common prefix of suffixes starting at x & y
{
	if(x == y) return L - x;
	int ans = 0;
	for(int k = stp -1; k >=0 && x < L && y < L; k --)
		if(P[k][x] == P[k][y])
			   x += (1 << k),  y += (1 << k), ans += (1 << k);
	return ans;
}


/*Main code begins now */
int testnum;
int N;
int q;
int m, k;
char str[1<<16];

void preprocess()
{

}

int revmap[1<<16];
void solve()
{
	suffixArray(str);
	for(int i = 0; i < N; i++)
		revmap[P[stp-1][i]] = i;
	
	s(q);
	for(int i = 0; i < q; i++)
	{
		s(m);
		s(k);
		
		int lo1, hi1, mid;
		
		int rank = P[stp-1][m];
		
		//left
		lo1 = 0, hi1 = rank;
		while(lo1 < hi1)
		{
			mid = (lo1 + hi1)/2;
			if(lcp(m, revmap[mid]) >= k)
			{
				hi1 = mid;
			}
			else 
				lo1 = mid+1;
		}
		
		int lo2, hi2, mid2;
		lo2 = rank, hi2 = N-1;
		
		while(lo2 < hi2)
		{
			mid = (lo2 + hi2 + 1)/2;
			if(lcp(m, revmap[mid]) >= k)
			{
				lo2 = mid;
			}
			else 
				hi2 = mid-1;
		}
		
		int ans = hi2 - lo1 + 1;
		printf("%d\n", ans);
	}
}

bool input()
{
	s(N);
	scanf("%s", str);
	return true;
}


int main()
{
	preprocess();
	int T;
	s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}


