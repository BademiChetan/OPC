#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

#define ULL unsigned long long

using namespace std;


ULL mulmod(ULL a,ULL b,ULL MOD)
{
ULL result=0;
a=a%MOD;     
while(b)
{
if (b&1)
{result+=a;
result%=MOD;
}
a+=a;
a%=MOD;        
b/=2;        
}     
 return result%MOD;    
}

ULL power(ULL exp,ULL n,ULL MOD)
{
ULL result=1;
while(n)
{
  if (n&1)
  {result=mulmod(result,exp,MOD);
  }
  exp=mulmod(exp,exp,MOD);
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
           
           printf("%lld\n",power(4,n,MOD));          
 }

 return 0;
}
