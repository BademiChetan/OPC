#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <utility>
#include <sstream>
#include <numeric>
#define _bc(i) __builtin_popcount(i)
#define fr(i,a,n) for(i=(a);i<(n);i++)
#define fre(i,a,n) for(i=(a);i<=(n);i++)
#define all(v) (v).begin(),(v).end()
#define sz size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define BE begin()
#define EN end()
#define VI vector <int>
#define VS vector <string>
#define MII map<int,int>
#define IT iterator
#define INF 0x7ffffff0		//2^31-16 = 2147483647 
#define MINF 0x80000000		//-2^31   = 2147483648
using namespace std;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef long long lint;
typedef unsigned long long ull;
#define SS ({int x;scanf("%d",&x);x;})

lint mod(int a,int x,int p)
{
	lint res=1;
	while(x>1)
	{
		if(x&1)
			res=(res*a)%p;
		a=(a*a)%p;
		x>>=1;
	}
	return res;
}

int main()
{
	int i,j,t,p,q,r;
	t=SS;
	while(t--)
	{
		vector<pair<double,int> > v;
		VI vv;
		VII v2;
		int n,k,ans=0;
		n=SS;k=SS;
		for(i=0; i<n;i++)
		{
			scanf("%d%d%d",&p,&q,&r);
			v.PB(II((double)q/p,i));
			vv.PB(r);
			v2.PB(II(p,q));
		}
		sort(all(v));
		for(i=0; i<v.sz; i++)
		{
			int ind=v[i].SE;
			for(j=1;j<=vv[ind];j++)
			{
				if(k>v2[ind].FI)
				{
					k-=v2[ind].FI;
					ans+=v2[ind].SE;
				}
				else
					break;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}





















