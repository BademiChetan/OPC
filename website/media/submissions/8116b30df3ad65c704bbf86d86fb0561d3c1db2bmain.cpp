#include <iostream>
using namespace std;

int main()
{
	long long T, n,k, ret; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		
		long long ret = 1, t = 4;
		while ( n > 0 )
		{
			if (n%2 == 1) ret = (ret*t)%k;
			
			t = (t*t)%k;
			n /= 2;
		}
		cout << ret << endl;
	}
}

