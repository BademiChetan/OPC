#include<stdio.h>
long arrprime[3000]={2,3};
int nprime;
long gcd(long a,long b)          //Function to calculate GCD of 2 numbers a and b
{
       long i;
       if(b>=a)
       {
	  for(i=a;i>1;i--)
		if(b%i==0&&a%i==0)
			return i;
	  return 1;

       }
       else
	  return gcd(b,a);
}
int isprime(long n)     //Function to check if the given number is prime or not
{                       //Returns 1 for prime and 0 for not prime
	long i;
	for(i=2;i<n;i++)
		if(n%i==0)
			return 0;
	return 1;

}
long powmod(long a,long b,long m)   //Function to calculate (a^b)mod m
{
	long result=1,power=a;
	if(b==0)
		return 1%m;
	while(b>0)
	{
		if(b%2==1)
			result = (result*power)%m;
		power=(power*power)%m;
		b=b/2;
	}
	if(result==1)
	   return power;
	else
	   return result;

}
int lookup(long k)
{
		long f=0,l=nprime-1,mid;
		while(f<=l)
		{
			mid=(l+f)/2;
			if(arrprime[mid]==0)
				return 1;
			else if(arrprime[mid]>k)
				l=mid-1;
			else
				f=mid+1;
		}
		return 0;
}
long phi(long a)
{
	long i,r=0;
	if(lookup(a)==1)
		return a-1;
	else if(isprime(a))
		return a-1;
	
	for(i=1;i<=a;i++)
		if(gcd(i,a)==1)
			r++;
	return r;
}
void calcprimes()
{
	int i;
	nprime=2;
	for(i=5;i<3000;i++)
		if(isprime(i))
			arrprime[nprime++]=i;
}
int main()
{
	int t;
	long n,k,r,r1;
	calcprimes();
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%ld",&k);
		r1=powmod(2,n,phi(k));
		r=powmod(2,r1,k);
		printf("%ld\n",r);
	}
	return 0;
}