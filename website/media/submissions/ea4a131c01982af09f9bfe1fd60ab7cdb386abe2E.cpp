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
typedef pair<LL, LL > PLL;

/*Main code begins now */
int testnum;
vector<pair<LL,PLL> > arr;
LL N,W;
LL sum[12];
map<pair<LL,int>, LL> dp;


void preprocess()
{

}

LL solve(LL wt,int i)
{
	if(dp.count(mp(wt,i)) > 0) return dp[mp(wt,i)];
	//printf("Called %lld %d\n",wt,i);
	if(i==0)
	{
		LL cnt=min(arr[i].second.second, wt/arr[i].first);
		return dp[mp(wt,i)]=cnt*arr[i].second.first;
	}
	else
	{
		LL hi = min(wt/arr[i].first, arr[i].second.second);
		LL left = wt - sum[i];
		LL lo = min(arr[i].second.second,max(0ll, left/arr[i].first));
		//printf("lo=%lld  hi=%lld\n",lo,hi);
		
		LL best=0;
		for(LL cnt=lo;cnt<=hi;cnt++)
			best = max(best, cnt*arr[i].second.first + solve(wt-cnt*arr[i].first, i-1));
		return dp[mp(wt,i)]=best;
	}
}
	

void solve()
{
	sum[0]=0;
	for(int i=0;i<N;i++)
	{
		sum[i+1] = sum[i] + arr[i].first * arr[i].second.second;
	}
	
	cout<<solve(W,N-1)<<endl;;
}

bool input()
{
	cin>>N>>W;
	arr.clear();
	dp.clear();
	LL a,b,c;
	for(int i=0;i<N;i++)
	{
		cin>>a>>b>>c;
		arr.pb(mp(a,mp(b,c)));
	}
	sort(arr.begin(),arr.end());	
	return true;
}


int main()
{
	preprocess();
	int T; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}
