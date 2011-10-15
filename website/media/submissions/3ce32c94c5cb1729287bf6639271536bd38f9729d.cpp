#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;
typedef pair<int,int> P ;
#define MAXN 1100000
int n,B,c[20],v[20],q[20] ;

int sa,sb ;
P a[MAXN],b[MAXN] ;
void create(int k,int lim,int cost,int profit,int which)
{
 if(k == lim)
 {
  if(which == 0) a[sa++] = P(cost,profit) ;
  else b[sb++] = P(cost,profit) ;
  return ;
 }
 for(int i = 0;i <= q[k];i++)
 {
  create(k + 1,lim,cost,profit,which) ;
  cost += c[k] ;
  profit += v[k] ;
 }
}

int main()
{
 int runs ;
 cin >> runs ;
 while(runs--)
 {
  cin >> n >> B ;
  for(int i = 0;i < n;i++) cin >> c[i] >> v[i] >> q[i] ;
  int na = n / 2 ;
  int nb = n - na ;
  
  sa = sb = 0 ;
  create(0,na,0,0,0) ;
  create(na,n,0,0,1) ;
  
//  for(int i = 0;i < sa;i++) cout << a[i].first << " " << a[i].second << endl ;
  
  sort(b,b + sb) ;
  for(int i = 1;i < sb;i++) b[i].second = max(b[i].second,b[i - 1].second) ;
  
  int mx = 0 ;
  for(int i = 0;i < sa;i++) if(a[i].first <= B)
  {
   int low = -1,high = sb ;
   while(low + 1 < high)
   {
    int mid = low + (high - low) / 2 ;
    if(a[i].first + b[mid].first <= B) low = mid ;
    else high = mid ;
   }
   mx = max(mx,a[i].second + b[low].second) ;
  }
  printf("%d\n",mx) ;
 }
 return 0 ;
}
