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
string s;
int n;
map<string,int> ans;

void init()
{
	int i,j;
	for(i=0;i<n;i++)
	for(j=1;j<=(n-i);j++)
	ans[s.substr(i,j)]++;
}

int main(int argc, char **argv)
{
	int t,q,m,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		ans.clear();
		init();
		cin>>q;
		while(q--)
		{
			cin>>m>>k;
			cout<<ans[s.substr(m,k)];
		}
	}
	return 0;
}

