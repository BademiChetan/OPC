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

int N, W;
vi cw, cv, cf;


void go(int w)
{

}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		cin >> N >> W;
		cw.clear(), cv.clear(), cf.clear();
		cw.assign(N, 0), cv.assign(N, 0), cf.assign(N, 0);
		
		for (int i = 0; i < N; i++)
			cin >> cw[i] >> cv[i] >> cf[i];

		int maxv = -1;
		mii dp0;
		dp0.insert(pii(0, 0));
		
		for (int i = 0; i < N; i++)
		{
			int w = cw[i], v = cv[i], f = cf[i];
			mii dp1;
			
			foreach(it, dp0)
			{
				for (int k = 0; k <= f; k++)
				{
					const int ww = it->first + k * w;
					const int vv = it->second + k * v;
					if (ww > W) break;
					
					if (dp1[ww] == 0 || vv < dp1[ww])
						dp1[ww] = vv;
					
					if (vv > maxv)
						maxv = vv;
				}
			}
			
			foreach(it, dp1)
			{
				const int &ww = it->first, &vv = it->second;
				if (dp0[ww] == 0 || vv < dp0[ww])
					dp0[ww] = vv;
			}
		}
		cout << maxv << endl;
	}
	
	return 0;
}
