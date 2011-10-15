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
vector<pair<int,PII> > arr;
int N,W;


vector<PII> a;
vector<PII> b;


void preprocess()
{

}

void solve(int wt,int val,int i,bool up)
{
	if(i==-1) return;
	//printf("%d %d %d %d\n",wt,val,i,up);
	assert (wt >= 0 && wt <= W);
	if((!up && i==0) || (up && i==N-1))
	{
		int cnt=min(arr[i].second.second, (W-wt)/arr[i].first);
		for(int j=0;j<=cnt;j++)
		{
			int nwt = wt+j*arr[i].first;
			int nval = val+j*arr[i].second.first;
			assert(nwt >= 0 && nwt <= W);
			assert(nval >= 0);
			if(!up)
				a.pb(mp(nwt,nval));
			else
				b.pb(mp(nwt,nval));
		}
	}
	else
	{
		int cnt=min(arr[i].second.second, (W-wt)/arr[i].first);
		for(int j=0;j<=cnt;j++)
		{
			int nwt = wt+j*arr[i].first;
			int nval = val+j*arr[i].second.first;
			assert(nwt >= 0 && nwt <= W);
			assert(nval >= 0);
			solve(nwt,nval,(up? i+1 : i-1),up);
		}
	}

}

vector<PII> aa;
vector<PII> bb;	

void solve()
{
	a.clear();
	b.clear();
	a.pb(mp(0,0));
	b.pb(mp(0,0));
	solve(0,0,N/2-1,false);
	solve(0,0,N/2,true);
	
	sort(all(a));
	sort(all(b));
	
	//for(int i=0;i<a.size();i++)
	//	cout<<a[i].first<<" "<<a[i].second<<endl;
		
	//for(int i=0;i<b.size();i++)
	//	cout<<b[i].first<<" "<<b[i].second<<endl;
		
	aa.clear();
	bb.clear();
	
	for(int i=0;i<a.size();i++)
	{
		while(i<a.size()-1 && a[i].first == a[i+1].first) i++;
		aa.pb(a[i]);
	}
	
	for(int i=1;i<aa.size();i++)
		aa[i].second=max(aa[i].second,aa[i-1].second);
	
	for(int i=0;i<b.size();i++)
	{
		while(i<b.size()-1 && b[i].first == b[i+1].first) i++;
		bb.pb(b[i]);
	}
	
	for(int i=1;i<bb.size();i++)
		bb[i].second=max(bb[i].second,bb[i-1].second);
	
	
	
	//cout<<a.size()<<" "<<b.size()<<endl;
	
	vector<PII>::iterator it1 = aa.begin();
	vector<PII>::reverse_iterator it2 = bb.rbegin();
	
	int best=0;
	while(it1!=aa.end() && it2!=bb.rend())
	{
		//printf("%d %d, %d %d\n",(*it1).first,(*it1).second,(*it2).first,(*it2).second);
		if((*it1).first + (*it2).first <= W)
		{
			best = max(best, (*it1).second+(*it2).second);
			it1++;
		}
		else
			it2++;
	}
	while(it1 != aa.end())
	{
		if((*it1).first <= W)
			best=max(best, (*it1).second);
		else
			assert(false);
		it1++;
	}
	while(it2 != bb.rend())
	{
		if((*it2).first <= W)
			best=max(best, (*it2).second);	
		else
			assert(false);
		it2++;
	}
	
	cout<<best<<endl;
}

bool input()
{
	cin>>N>>W;
	arr.clear();
	int a,b,c;
	for(int i=0;i<N;i++)
	{
		cin>>a>>b>>c;
		arr.pb(mp(a,mp(b,c)));
	}
	//sort(arr.begin(),arr.end());	
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
