#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> PII;
typedef long long LL;
#define MAXN 100001
#define MAXP 9600
bool isPrime[MAXN];
int primes[MAXP];
int sz;

void inline preCompute()
{
	for(int i=2;i*i<MAXN;i++)
		if(!isPrime[i])
			for(int j=i*i;j<MAXN;j+=i)
				isPrime[j] = 1;
	// find primes upto 10^5
	for(int i=2;i<MAXN;i++)
	if(!isPrime[i])
	primes[sz++] = i;
}
int findETF(int N)
{
	// find etf of N
	int ret = N;
	for(int i=0;i<sz && N>1;i++)
	{
		if(N % primes[i]) continue;
		// divisible
		ret /= primes[i];
		ret *= (primes[i] - 1);
		while(N % primes[i] == 0) N /= primes[i];
	}
	// check for last prime
	if(N > 1)
	{
 		// N is prime
 		ret /= N;
		ret *= (N - 1);
	}
	return ret;
}
int inline modexp(LL base, int pwr, int MOD)
{
	LL res = 1;
	while(pwr)
	{
		if(pwr & 1)
		res = (res * base) % MOD;
		base = (base * base) % MOD;
		pwr >>= 1;
	}
	return res;
}
int brute(int N, int K)
{
	int res = 2;
	for(int i=1;i<=N;i++)
	res = (res * res) % K;
	return res;
}
int main() {
	preCompute();
	//printf("%d\n",sz);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N, K;
		scanf("%d %d", &N, &K);
		if(K == 1)
		printf("0\n");
		else
		{
			int etf = findETF(K);
			//printf("ETF:%d\n", etf);
			// find order
			int order = etf;// it is atmost etf
			for(int d = 2; d * d <= etf;d++)
			{
				if(etf % d == 0)
				{
					int d1 = d, d2 = etf/d;
					// d1 and d2 are divs
					int m1 = modexp(2, d1, K);
					if(m1 == 1)
					{
						order = d1;
						break;
					}
					int m2 = modexp(2, d2, K);
					if(m2 == 1)
					order = min(order, d2);
				}
			}
			// find 2 ^ 2 ^ N
			int tmp = modexp(2, N, order);
			int res = modexp(2, tmp, K);
			printf("%d\n", res);
			//assert(res == brute(N,K));
		}
	}
	return 0;
}

