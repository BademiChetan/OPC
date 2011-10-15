
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int main(){
	int ans,x[100],y[100],a,b,t,i;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&a,&b);
		for(i=0;i<=31;i++)
		{
			x[i]=a%2;
			y[i]=b%2;
			a/=2;
			b/=2;
		}
		for(i=31;i>=0;i--)
		{
			if(x[i]!=y[i])
			{
				ans+=(1LL<<i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
