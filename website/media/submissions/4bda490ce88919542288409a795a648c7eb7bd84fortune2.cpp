// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int  phi(int n)
{
	int ans,i,sq;
	ans=n;
	sq=(int)(sqrt((double) n));

	if(n%2==0)
		ans-=ans/2;
	while(n%2==0)
		n/=2;

	for(i=3;n>1 && i<=sq;++i)
		if(n%i==0)
		{
			ans-=ans/i;
			while(n%i==0)
				n/=i;
		}

	if(n>1)
		ans-=ans/n;
	return ans;

}

int pow(int b,int n, int m) {
	if(n == 0) return 1;
	int x = pow(b, n>>1, m);
	int y = ((LL) x * x) % m;
	if(n&1) {
		return  ((LL) y * b) % m;
	} else {
		return y;
	}
}


int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, k;
		scanf("%d %d" ,&n, &k);
		int p = pow(2,n,phi(k));
		printf("%d\n",pow(2,p,k));
	}
	return 0;
}

