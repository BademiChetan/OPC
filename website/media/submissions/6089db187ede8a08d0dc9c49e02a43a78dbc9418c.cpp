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
 ULL n,MOD,ans;
 scanf("%d",&t);
 while(t--)
 {
           scanf("%llu %llu",&n,&MOD);
           
           ans=power(2,n,MOD);
           
           ans=power(2,ans,MOD);
           printf("%llu\n",ans);          
 }

 return 0;
}
