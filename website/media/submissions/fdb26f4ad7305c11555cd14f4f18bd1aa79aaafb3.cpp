#include <cstdio>
#include <vector>

using namespace std;

bool a[100000] = { false };
vector <long long> primes;

long long ans(long long n, long long k)
{
	if(n == 0)
		return 1 % k;
	if(n == 1)
		return 2 % k;
	int p = ans(n / 2, k);
	if(n % 2 == 0)
		return (p * p) % k;
	else
		return (((p * p) % k) * 2) % k;
}

void sieve()
{
	for(int i = 2; i < 100000; i ++)
	{
		if(!a[i])
		{
			primes.push_back((long long) i);
			for(int j = i + i; j < 100000; j += i)
				a[j] = true;
		}
	}
}

long long phi(long long x) {

	long long ret = 1, pow;
	for (int i = 0; x != 1LL && i < primes.size() && primes[i] <= x; i++)
	{
		pow = 1;
		while (!(x%primes[i]))
		{
			x /= primes[i];
			pow *= primes[i];
		}
		ret *= (pow - (pow/primes[i]));
	}
	if(x != 1)
	{
		ret *= (x - 1);
	}
	return ret;
}

int main()
{
	sieve();
	int T;
	scanf(" %d", &T);
	while(T -- > 0)
	{
		long long n, k, fi, t;
		scanf(" %lld %lld", &n, &k);
		fi = phi(k);
		t = ans(n, fi);
		printf("%lld\n", ans(t, k));
	}
	return 0;
}
