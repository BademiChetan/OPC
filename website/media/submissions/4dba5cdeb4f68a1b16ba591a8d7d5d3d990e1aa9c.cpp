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

ULL fi(ULL n) 
     { 
       ULL result = n; 
       for(int i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) result -= result / i; 
         while (n % i == 0) n /= i; 
       } 
       if (n > 1) result -= result / n; 
       return result; 
     } 

int main()
{
 int t;
 ULL n,MOD,ans,p,phi;
 scanf("%d",&t);
 while(t--)
 {
           scanf("%llu %llu",&n,&MOD);
           
           phi=fi(MOD);
           p=power(2,n,phi);
           ans=power(2,p,MOD);
           
           printf("%llu\n",ans);          
 }

 return 0;
}
