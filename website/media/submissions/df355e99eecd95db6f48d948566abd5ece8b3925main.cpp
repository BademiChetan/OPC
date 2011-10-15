#include <iostream>
using namespace std;

int main()
{
	int T,n, a; cin >> T;
	while (T--)
	{
		cin >> n;
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			ret += a;
		}
		for (int i = 1; i < n; ++i) ret -= i;
		
		//cout << ret << " " << ret%2 << endl;
		
		if (ret%2 == 1 or ret%2 == -1) cout << "WIN" << endl;
		else cout << "LOSE" << endl;
	}
}

