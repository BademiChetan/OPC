#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

long long power(long long n,long long MOD)
{
long long result=1,exp=4;

while(n)
{
  if (n&1)
  {result*=exp;
  result%=MOD;
  }
  exp=(exp*exp)%MOD;
  n=n/2;
}
return result%MOD;
}

int main()
{
 int t;
 long long n,MOD;
 scanf("%d",&t);
 while(t--)
 {
           scanf("%lld %lld",&n,&MOD);
           
           printf("%lld\n",power(n,MOD));          
 }

 return 0;
}
