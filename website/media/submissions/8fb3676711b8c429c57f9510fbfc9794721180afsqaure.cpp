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

int x,y,n;

int solve(int x,int y,int n)
{
	if(x==y) return 0;
	int m = n/2;
	
//	cout<<x<<" "<<y<<" "<<n<<endl;
	if(x>m && y>m)
	{
		return solve(x-m,y-m,m);
	}

	else if(x>m && y<=m)
	{
		return solve(x-m,y+m,m);
	}

	else if(x<=m && y>m)
	{
		return (m)+solve(x,y-m,m);
	}

	else
		return solve(x,y,m);

}


void input()
{
	SI(x);
	SI(y);
	n = 1;
	x++;y++;
	while(n<max(x,y))
	{
		n*=2;
	}

	cout<<solve(x,y,n)<<endl;

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
