/* Big mod */
#include<stdio.h>
long square(long s){
return s*s;
}
long bigmod(long b, long p, long m){
if (p == 0)
return 1;
else if (p%2 == 0)
return square( bigmod (b,p/2,m)) % m; // square(x) = x * x
else
return ((b % m) * bigmod( b,p-1,m)) % m;
}
int main(){
long n,k,sum[1000];
int i,t;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%ld%ld",& n,& k);
sum[i] = bigmod( 4, n, k);
}
for(i=0;i<t;i++)
printf("%ld\n", sum[i]);

return 0;
}
