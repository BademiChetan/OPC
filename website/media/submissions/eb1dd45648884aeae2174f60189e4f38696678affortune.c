#include<stdio.h>
int main()
{
int T,l,n,k,f;
scanf ("%d", &T);
for (l=0;l<T;l++)
{
scanf ("%d %d", &n,&k); 
int i,j;
int primes[100000];
for (i=0;i<100000;i++)
primes [i]=1;
primes[0]=0; primes[1]=0;
for (i=2;i<1000;i++)
{
if (primes[i]==0)
continue;
for (j=i*i;j<100000;j++)
primes[j]=0;
}
f=k;
for (i=2; i<(k/2)+1;i++)
{
if (primes[i]==1 && k%primes[i]==0 )
f=f*(primes[i]-1)/primes[i];
}
f=n%f;
int pow=1;
for (i=1; i<=f;i++)
pow=2*pow;

printf ("%d\n",pow%k);
}
return 0;
}


