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

/*Main code begins now */
int testnum;
int N,K;


void preprocess()
{

}

LL pow(LL a,LL n,LL mod)
{
	LL ans=1;
	while(n)
	{
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}

void solve()
{
	int orig=K;
	LL phi=K;
	for(int i=2;i*i<=K;i++)
		if(K%i == 0)
		{
			phi -= phi/i;
			while(K%i == 0)
				K/=i;
		}

	LL z=pow(2,N,phi);
	
	printf("%lld\n", pow(2, z, orig));
}

bool input()
{
	s(N); s(K);
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
