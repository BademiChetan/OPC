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
LL mod=1000000007;
LL N,K;

struct F
{
	LL zero,one;
	F(LL a,LL b)
	{
		zero=a;
		one=b;
	}
};

F operator * (F a,F b)
{
	return F( ((a.zero*b.zero)%mod + (((a.one*b.one)%mod) * (K-1) )%mod)%mod,
				((a.zero*b.one)%mod + (a.one*b.zero)%mod + (((a.one*b.one)%mod) * (K-2) )%mod)%mod );
}

F powF(F x,int n)
{
	F ans = F(1,0);
	while(n)
	{
		if(n&1) ans = ans*x;
		x = x*x;
		n >>= 1;
	}
	return ans;
}

LL pow(LL x,int n)
{
	LL ans = 1;
	while(n)
	{
		if(n&1) ans = ans*x;
		x = x*x;
		n >>= 1;
	}
	return ans;
}

LL x,y;

void extgcd(LL a,LL b)
{
	if(b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		extgcd(b,a%b);
		LL temp=y;
		y=x-(a/b)*y;
		x=temp;
	}
}

LL inverse(LL a)
{
	extgcd(a,mod);
	while(x<0) x+=mod;
	while(x>=mod) x-=mod;
	return x;
}
	


void preprocess()
{
	
}

void solve()
{
	LL a = pow(2ll,K);
	a = (a+mod-2) % mod;
	a = (a * inverse(K)) % mod;
	LL zero = (a+2)%mod;
	LL one = a;
	
	F x = F(zero,one);
	if(K==2)
		x = F(2,2);
	
	cout<<powF(x, N/K).zero<<endl;
}

bool input()
{
	cin>>N>>K;
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
