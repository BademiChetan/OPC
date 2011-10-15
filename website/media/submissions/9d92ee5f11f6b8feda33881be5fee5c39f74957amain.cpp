#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item
{
	long long v, w, f;
	item(){}
	item(int V, int W, int F) : v(V), w(W), f(F) {}
	bool operator<(const item &i) const
	{
		return v*i.w < w*i.v;
	}
};

vector<item> v;
int n, w;

int go(int ind, int w)
{
	if (ind == n) return 0;
	
	int ret = 0;
	for (int i = v[ind].f; i >= 0; --i)
		if ( v[ind].w*i <= w )
		{
			ret = max( ret, go(ind+1, w-v[ind].w*i) + (int)v[ind].v*i );
		}
	//cout << ind << " " << w << " : " << ret << endl;
	return ret;
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		cin >> n >> w;
		
		v.clear(); v.resize( n );
		
		int wi, vi, fi;
		for (int i = 0; i < n; ++i)
		{
			cin >> wi >> vi >> fi;
			v[i] = item( vi, wi, fi );
		}
		sort( v.rbegin(), v.rend() );
		
		long long ret = go( 0, w );
		cout << ret << endl;
	}
}

