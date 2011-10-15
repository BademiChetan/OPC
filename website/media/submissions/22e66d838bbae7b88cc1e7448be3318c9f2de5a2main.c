/*
 * main.c
 *
 *  Created on: 25-Sep-2011
 *      Author: pritesh
 */

#include<stdio.h>

long long int totient(long long int k)
{
    long long int k2=k,i;
    for(i=3;i*i<k2;i++)
    {
        if(k%i==0)
        {
            k-=k/i;
            while(k2%i==0) k2/=i;
        }
    }
    if(k2>1)
    {
        k-=k/k2;
    }
    return k;
}

long long int power(long long int base, long long int exp, long long int rem)
{
long long int result = 1;
while (exp)
{
if (exp & 1)
{result = (result*base)%rem;}
exp >>= 1;
base = (base*base)%rem;
}
return result;
}

int main()
{
    int t,m; scanf("%d",&t);
    m=t;
    long long int a[1000],i=0;
    for(;t>0;t--)
    {
        long long int n,k,r;
	    long long int c;
        scanf("%lld",&n);scanf("%lld",&k);
        long long int phi=totient(k),l=0;
        long long int j=phi;
        while(j%2==0) {j/=2;l++;}
        long long int x=(n-l)%totient(j);
        c=power(2,(long long int)(x+l),phi);
        r=power(2,c,k);
        a[i]=r;
        i++;
    }
    for(i=0;i<m;i++)
    	printf("%lld\n",a[i]);
    return 0;
}
