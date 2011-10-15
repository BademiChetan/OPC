
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

int n,k;

LL solve(int a,int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	
	LL ans = solve(a,b/2);
	ans = (ans * ans)%k;

	if(b%2)
	{
		ans = (ans * a)%k;
	}

	return ans%k;
}


void input()
{
	SI(n);
	SI(k);
	LL ans= solve(2,n);
	ans = solve(2,ans);
	cout<<ans<<endl;
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
