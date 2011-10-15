#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item
{
	int v, w, f;
	item(){}
	item(int V, int W, int F) : v(V), w(W), f(F) {}
	bool operator<(const item &i) const
	{
		return 1LL*v*i.w < 1LL*w*i.v;
	}
};

vector<item> v;
vector<int> sum;
int n, w, ret, cnt;

void go(int ind, int w, int val)
{
	//++cnt;
	if (ind == n)
	{
		ret = max(ret, val);
		return;
	}
	//cout << ind << " " << w << " : " << val << " " << sum[ind] << " " << ret << endl;
	if ( val+sum[ind] <= ret ) return;
	
	for (int i = v[ind].f; i >= 0; --i)
		if ( v[ind].w*i <= w )
		{
			go(ind+1, w-v[ind].w*i, val + v[ind].v*i );
		}
	//cout << ind << " " << w << " : " << ret << endl;
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

		sum.resize(n); sum[n-1] = v[n-1].f * v[n-1].v;
		for (int i = n-2; i >= 0; --i) 
			sum[i] = sum[i+1] + v[i].f * v[i].v;
		//for (int i = 0; i < n; ++i) cout << sum[i] << endl;
		
		ret = 0; cnt = 0;
		go( 0, w, 0 );
		//cout << cnt << endl;
		cout << ret << endl;
	}
}

