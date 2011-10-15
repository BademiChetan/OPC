#include<stdio.h>
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
long phi(long a)
{
	long i,r=0;
	for(i=1;i<=a;i++)
		if(gcd(i,a)==1)
			r++;
	return r;
}
int main()
{
	int t;
	long n,k,r,r1;
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