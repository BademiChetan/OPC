
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
#define MX 102
typedef long long LL;
using namespace std;

int A[MX];



void input()
{
	int n;
	SI(n);
	int sum = 0;

	for(int i=1;i<=n;i++) 
	{
		int a;
		SI(a);
		sum+=a;
	}
	sum+=((n*(n-1))/2);
	if(sum%2)
		cout<<"WIN"<<endl;
	else
		cout<<"LOSE"<<endl;
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
