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

#define ll long long
#define sz(v) ((v).size())
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define nb(a) ((int)ceil(log((a)+(long double)1.0)/log(((long double)2.0))))

using namespace std;

struct box
{
	int w,v,f;
}b[20];
int n,wt,ans;

bool mycomp(struct box b1, struct box b2)
{
	return ((b1.v/(float)b1.w)>(b2.v/(float)b2.w));
}

int f(int start, int sumw, int sumv)
{
	if(start==n)
	{
		if(sumw<=wt && sumv>ans)
		{
			ans=sumv;
		}
		return 0;
	}
	for(int c=0;c<=b[start].f;c++)
		f(start+1,sumw+c*b[start].w,sumv+c*b[start].v);
	return 0;
}

int solve()
{
	ans=0;
	f(0,0,0);
	return ans;
}

int main(int argc, char **argv)
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>wt;
		REP(i,n) 
		{
			cin>>b[i].w>>b[i].v>>b[i].f;
		}
		sort(b,b+n,mycomp);
		cout<<solve()<<endl;
	}
	return 0;
}

