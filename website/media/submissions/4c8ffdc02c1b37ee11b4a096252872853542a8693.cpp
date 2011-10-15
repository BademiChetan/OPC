#include <stdio.h>

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

long long phi(long long x) {

	long long ret = 1,i,pow;

for (i = 2; x != 1; i++) {
pow = 1;
while (!(x%i)) {
x /= i;
pow *= i;
}
ret *= (pow - (pow/i));
}
return ret;
}

int main()
{
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
