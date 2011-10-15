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
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
using namespace std;
int getint(){
	int c = 'a';
	while (!(c >= '0' && c <= '9') && c != '-') c = getchar_unlocked();//();//
	int c2;
	if (c != '-')
		c2 = c;
	else
		c2 = '0';
	int res = 0;
	while((c2 >= '0' && c2 <= '9'))
	{
		res = (res << 3) + (res << 1) + (c2 - '0');
		c2 = getchar_unlocked();
	}
	return res * (c == '-' ? -1 : 1);
}

int n,k;
int g[1024*1024];
int main()
{
	int X;
	int kk=0;
	X=getint();
	while(X--)
	{
		n=getint();
		k=getint();
	//	scanf("%d%d",&n,&k);
		set<int>S;
		S.insert(4);
		g[1]=4;
		long long   prev=4,now,pos=2;
		bool seen=true;
		while(1)
		{
			now=prev*prev;
			now%=k;
			//printf("now is %d\n",now);
			if(pos==n)
			{
				printf("%lld\n",now);
				seen=false;
				break;
			}
			if(S.find(now)!=S.end())break;
			g[pos++]=now;
			
			S.insert(now);
			prev=now;
		}
		if(!seen)continue;
		if(n<pos)
		{
			printf("%d\n",g[n]);
			continue;
		}
		int idx;
		for(int i=1;i<pos;i++)if(now==g[i])
		{
			idx=i;
			break;
		}
		//printf("k is %d idxis %d\n",k,idx);
		n-=idx;
		int l=pos-idx;
		printf("%d\n",g[idx+n%l]);
	}

	return 0;
}
