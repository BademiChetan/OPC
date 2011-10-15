#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define U unsigned long long int 

U function(U n, U k)
{
	if(n == 1)
	{
		return ((2%k)*(2%k))%k;
	}
	U ans;
	ans = function(n/2, k);
	if(n%2 == 0) return ((ans%k)*(ans%k))%k;
	else return ((ans%k) * (2%k))%k;
}

int main()

{
	U n;
	U k;
	U product;
	int t;
	int i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%llu%llu", &n, &k);
		i;
		printf("%llu\n", function(n, k));
	}
	return 0;
}
