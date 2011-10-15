#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef pair<int,string> pis;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef long long ll;
typedef unsigned long long ull;
typedef queue<int> qi;
template<class T> inline bool between(const T &x, const T &a, const T &b) { return x >= (a<b ? a : b) && x <= (a>b ? a : b); }
#define foreach(var, container) for(typeof((container).begin()) var = (container).begin(); var != (container).end(); ++var)

int res;

int go(int x, int y)
{
	if (x == 0 && y == 0) return 0;

	int res = go(x/2, y/2) << 1;
	
	if ((x ^ y) & 1) res |= 1;

	return res;
}

int main()
{
	int t, x, y;
	cin >> t;
	
	while (t--)
	{
		cin >> x >> y;
		
		cout << go(x, y) << endl;
		
	}
	return 0;
}





