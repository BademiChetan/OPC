#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T; cin >> T;
	while (T--)
	{
		int a,b; cin >> a >> b;
		cout << (int)abs(1.0*a-b) << endl;
	}
}

