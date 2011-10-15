#include <iostream>
#include <cmath>
using namespace std;

int t[4][4] = { {0,1,2,3},
                {1,0,3,2},
                {2,3,0,1},
                {3,2,1,0} };

int main()
{
	int T; cin >> T;
	while (T--)
	{
		int a,b; cin >> a >> b;
		
		int ret = 0, k = 1;
		while ( a > 0 or b > 0 )
		{
			ret += t[a%4][b%4] * k;
			k *= 4;
			a /= 4;
			b /= 4;
		}
		
		cout << ret << endl;
	}
}

