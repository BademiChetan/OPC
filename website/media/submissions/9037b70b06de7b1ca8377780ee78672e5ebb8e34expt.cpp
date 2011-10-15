#include<stdio.h>

long long exp(long long b,long long k)
{
	if(b==0)return 1;
	if(b==1)return 2;

	//printf("%lld \t", b);

	long long t=exp(b/2,k);

	if(b%2==0)return (t*t)%k;
	else return (t*t*2)%k;
	
}
/*
long long gcd(long long a, long long b) {
	long long tmp;

	if ( a < b) {
		tmp = a;
		a = b;
		b = a;
	}

	while (b>0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return b;
}

long long phi(long long x) {

//	long long ret = 1,i,pow;
	long long tot = 1, pos = x-1;

	while(pos > 1) {
		if (gcd(pos, x) == 1) {
			tot++;
		}
		pos--;
	}

	for (i = 2; x != 1; i++) {
		pow = 1;
		while (!(x%i)) {
			x /= i;
			pow *= i;
		}
		ret *= (pow - (pow/i));
	}
	return ret;


	return tot;
}
*/
static int my_gcd(int a, int b)
{
	int q,r,t;

	/* Normalize so that 0 < a <= b */
	if((a == 0)||(b == 0)) return -1;
	if(a < 0) a = -a;
	if(b < 0) b = -b;
	if(b < a){
		t = b;
		b = a;
		a = t;
	}

	/* Now a <= b and both >= 1. */

	q = b/a;
	r = b - a*q;
	if(r == 0) 
		return a;

	return my_gcd(a,r);
}

/* In conditional statement form, phi can be defined together with another
 * function of 2 variables we denote as phiphi. We have phi(n) = phiphi(n,2)
 * and phiphi(y,x) = if(x = y-1 then x else if( x|y then
 * 	if((x,y/x)=1 then phi(x)phi(y/x) else x phi(y/x)) else phi(y,x+1))))
 */

static long long  phiphi(long long int,long long int);
static long long int phi(long long int n)
{
	if(n<0)n=-n;
	/* handle a few trivial boundary cases */
	if(n<=1)return 0;
	if(n==2)return 1;
	if(n==3)return 2;
	return phiphi(n,2);
}

/* This only gets called with y >= 3 and y > x >= 2 */

static long long  phiphi(long long int y, long long int x)
{
	int z;

	if(x+1 == y)return x; /* phi(prime p) = p-1 */
	if((y%x)==0){
		if(my_gcd(x,z=y/x)==1)
			return phi(x)*phi(z); /* multiplicative property */
		else
			return x*phi(z); /* This is a tricky case. It may
					    happen when x is a prime such
					    that a power of x divides y. In
					    case y = p^n, phi(y) = p^(n-1)(p-1)
					   */
	}
	else return phiphi(y,x+1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k;
		scanf("%lld %lld",&n,&k);	
		long long b=exp(n,phi(k));
		//printf("%lld\n",b);
		printf("%lld\n",exp(b,k));
	}
	return 0;
}
