#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

/*long long calc(int n, int mod)
{
	set<int> mp;
	vector<int> v;
	long long k = 2, cnt = 0;
	while ( true )
	{
		if ( mp.count(k) ) break;
		
		cout << k << " : " << cnt << endl;
		
		v.push_back( k );
		st.insert(k);
		k = (2*k)%mod;
	}
	
	cout << n << " " << k << " " << mp[k] << " " << cnt << endl;
	
	n--;
	int ind = (n-mp[k])%(cnt-mp[k]);
	cout << "\t" << ind << endl;
	return mp[ind];
}*/

int main()
{
	long long T, n,k, ret; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		n *= 2;
		
		long long ret = 1, t = 2;
		while ( n > 0 )
		{
			if (n%2 == 1) ret = (ret*t)%k;
	
			t = (t*t)%k;
			n /= 2;
		}
		cout << ret << endl;
	}
}

