#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;
typedef pair<int,int> P ;
int ct[102] ;

#define MOD 1000000007
int power(int a,int b)
{
 if(b == 0) return 1 ;
 int ret = power(a, b / 2) ;
 ret = 1LL * ret * ret % MOD ;
 if(b & 1) ret = 1LL * a * ret % MOD ;
 return ret ;
}

int main()
{
 int n,k ;
 while(cin >> n >> k)
 {
  if(k == 2)
  {
   int tot = power(2,n) ;
   tot -= power(2,n / 2) ;
   if(tot < 0) tot += MOD ;
   cout << tot << endl ;
   continue ;
  }
  memset(ct,0,sizeof ct) ;
  int ret = power(2,n) ;
  ret -= power(2,n / k) ;
  if(ret < 0) ret += MOD ;
  ret = 1LL * ret * power(k,MOD - 2) % MOD ;
  ret += power(2,n / k) ;
  if(ret >= MOD) ret -= MOD ;
  
  cout << ret << endl ;
 }
 return 0 ;
}
