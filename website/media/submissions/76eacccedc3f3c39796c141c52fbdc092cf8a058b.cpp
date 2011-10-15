#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;

int memo[102][102][2] ;
int solve(int a,int b,int t)
{
 if(a == 0 && b == 1) return t == 1 ? 0 : 1 ;
 if(a == 1 && b == 0) return t == 1 ? 1 : 0 ;
 if(memo[a][b][t] != -1) return memo[a][b][t] ;
 if(t == 0)
 {
  if(a > 1 && !solve(a - 1,b,1)) return memo[a][b][t] = 1 ;
  if(b > 1 && !solve(a + 1,b - 2,1)) return memo[a][b][t] = 1 ;
  if(a > 0 && b > 0 && !solve(a - 1,b,1)) return memo[a][b][t] = 1 ;
 }
 else
 {
  if(a > 1 && !solve(a - 2,b + 1,0)) return memo[a][b][t] = 1 ;
  if(b > 1 && !solve(a,b - 1,0)) return memo[a][b][t] = 1 ;
  if(a > 0 && b > 0 && !solve(a,b - 1,0)) return memo[a][b][t] = 1 ;  
 }
 return memo[a][b][t] = 0 ;
}

int main()
{
 memset(memo,255,sizeof memo) ;
 int runs ;
 cin >> runs ;
 while(runs--)
 {
  int n,a = 0,b = 0 ;
  cin >> n ;
  while(n--)
  {
   int k ;
   cin >> k ;
   if(k % 2 == 0) a++ ;
   else b++ ;
  }
  int cret = solve(a,b,1) ;
  if(!cret) printf("WIN\n") ;
  else printf("LOSE\n") ;
 }
 return 0 ;
}
