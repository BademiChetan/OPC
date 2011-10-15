
/*
   Team Ratatouille
   DA-IICT
*/

#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iomanip>

#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define VI vector<int>
#define PI pair<int,int>
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define SI(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define PRI(x) printf("%d\n",x)
#define PRL(x) printf("%lld\n",x)
#define fill(a,b) memset((a),(b),sizeof((a)))
typedef long long LL;
using namespace std;

LL k=1000000007ll;

LL solve(LL a,LL b)
{
	if(b==0) return 1ll;
	if(b==1) return a;
	LL ans = solve(a,b/2);
	ans = (ans * ans)%k;
	if(b%2)
	{   
		ans = (ans * a)%k;
	}   
	return ans%k;
}


LL gogo(LL g, LL m)
{
	
	LL ans = solve(2ll,g-1)-1+k;
	ans%=k;

	if(m==1)
	{
		ans+=g;
		ans%=k;
	}
	ans *= solve(g,k-2);
	ans%=k;

	if(m==1)
	{
		ans*=2;
		ans%=k;
		return ans;
	}
	ans *= solve(2ll,1ll*(g-1)*(m-1)+m);
	ans%=k;
	LL x = solve(g,k-2);
	ans *=x;
	ans%=k;
	return (ans + gogo(g,m-1))%k;
}

void input()
{
	LL n,g,m;
	SL(n);SL(g);
	m = n/g;
	if(n==2)
		cout<<2<<endl;
	else cout<<gogo(g,m)<<endl;
}
int main(){

	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T;
	SI(T);

	while(T-- >0)
	{
		input();
	}

	return 0;

}
