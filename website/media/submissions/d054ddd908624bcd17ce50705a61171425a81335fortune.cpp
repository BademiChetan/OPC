#include <iostream>
using namespace std;

unsigned long long getRem(unsigned long long b, unsigned long long e, unsigned long long m)
{
	if(e == 0) return 1;
	if(e == 1) return b%m;
	unsigned long long res = getRem(b, e/2, m);
	res = (res * res) % m;
	if(e % 2) res = (res * b) % m;
	return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int N,K;
		cin >> N >> K;
		cout << getRem(4%K, N, K) << endl;
	}
}
