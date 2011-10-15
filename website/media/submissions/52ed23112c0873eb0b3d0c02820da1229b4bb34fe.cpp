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
 int runs ;
 
 
 cin >> runs ;
 while(runs--)
 {
  cin >> n >> k ;
  int ret = 0 ;
  for(int i = 0;i < 1 << n;i++)
  {
   int sum = 0 ;
   for(int j = 0;j < n;j++) if(i & 1 << j) sum += j ;
   sum %= 2 ;
   if(sum == 0) ret++ ;
  }
//  cout << ret << endl ;
//  continue ;
  
  if(k == 2)
  {
   int tot = power(2,2 * n / k - 1) ;
   cout << tot << endl ;
   continue ;
  }
  memset(ct,0,sizeof ct) ;
  ret = power(2,n) ;
  ret -= power(2,n / k) ;
  if(ret < 0) ret += MOD ;
  ret = 1LL * ret * power(k,MOD - 2) % MOD ;
  ret += power(2,n / k) ;
  if(ret >= MOD) ret -= MOD ;
  
  cout << ret << endl ;
 }
 return 0 ;
}
