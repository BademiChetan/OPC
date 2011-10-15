#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std ;
#define MOD 1000000007
#define MAXN 100002
typedef pair<int,int> PII ;
char buff[MAXN] ;
int n,P[20][MAXN] ;
pair<PII,int> L[MAXN] ;
int where[MAXN] ;

int pw[MAXN],code[MAXN] ;
int getCode(int low,int len)
{
 if(len == 0) return 0 ;
 int high = low + len - 1 ;

 if(low == 0) return code[high] ;
 int ret = (code[high] - 1LL * code[low - 1] * pw[high - low + 1]) % MOD ;
 if(ret < 0) ret += MOD ;
 return ret ;
}

void preprocess()
{
 pw[0] = 1 ;
 for(int i = 1;i < MAXN;i++) pw[i] = 1LL * pw[i - 1] * 255 % MOD ;
 code[0] = buff[0] ;
 for(int i = 1;i < n;i++) code[i] = (1LL * code[i - 1] * 255 + buff[i]) % MOD ;
}

int order[MAXN],lc[MAXN] ;
void solve()
{
 int i,j,k ;
 
 for(i = 0;i < n;i++) P[0][i] = buff[i] - 'a' ;
 for(k = j = 1;j >> 1 < n;k++,j <<= 1)
 {
  for(i = 0;i < n;i++)
  {
   L[i].first.first = P[k - 1][i] ;
   L[i].first.second = i + j < n ? P[k - 1][i + j] : -1 ;
   L[i].second = i ;                
  }
  sort(L,L + n) ;
  for(i = 0;i < n;i++)
   if(i == 0 || L[i].first != L[i - 1].first)
    P[k][L[i].second] = i ;
   else P[k][L[i].second] = P[k][L[i - 1].second] ;
 }
 
 for(int i = 0;i < n;i++) order[i] = L[i].second ;
 for(int i = 0;i < n;i++) where[order[i]] = i ;

 for(int i = 1;i < n;i++)
 {
  int len1 = n - order[i],len2 = n - order[i - 1] ;
  int low = -1,high = min(len1,len2) + 1 ;
  while(low + 1 < high)
  {
   int mid = low + (high - low) / 2 ;
   int code1 = getCode(order[i - 1],mid) ;
   int code2 = getCode(order[i],mid) ;
   if(code1 == code2) low = mid ;
   else high = mid ;
  }
  lc[i] = low ;
 }
 
// for(int i = 0;i < n;i++) cout << order[i] << " " << lc[i] << endl ;
}

int tree[4 * MAXN] ;
void create(int k,int low,int high)
{
 if(low == high) { tree[k] = lc[low] ; return ; }
 int mid = (low + high) / 2 ;
 create(2 * k,low,mid) ;
 create(2 * k + 1,mid + 1,high) ;
 tree[k] = min(tree[2 * k],tree[2 * k + 1]) ;
}

#define INF (int)1e9
int query(int k,int low,int high,int qlow,int qhigh)
{
 if(low >= qlow && high <= qhigh) return tree[k] ;
 if(low > qhigh || high < qlow) return INF ;
 int mid = (low + high) / 2 ;
 int ret1 = query(2 * k,low,mid,qlow,qhigh) ;
 int ret2 = query(2 * k + 1,mid + 1,high,qlow,qhigh) ;
 return min(ret1,ret2) ;
}

int main()
{
 int runs ;
 scanf("%d",&runs) ;
 while(runs--)
 {
  scanf("%d",&n) ;
  scanf("%s",buff) ;

  preprocess() ;
  solve() ;
  create(1,0,n - 1) ;
  
  int q ;
  scanf("%d",&q) ;
  while(q--)
  {
   int start,len ;
   scanf("%d%d",&start,&len) ;
   start = where[start] ;
   
   int low1 = 0,high1 = start + 1 ;
   while(low1 + 1 < high1)
   {
    int mid = low1 + (high1 - low1) / 2 ;
    int qr = query(1,0,n - 1,start - mid + 1,start) ;
    if(qr >= len) low1 = mid ;
    else high1 = mid ;
   }
   
   int low2 = 0,high2 = n - start + 1 ;
   while(low2 + 1 < high2)
   {
    int mid = low2 + (high2 - low2) / 2 ;
    int qr = query(1,0,n - 1,start,start + mid - 1) ;
    if(qr >= len) low2 = mid ;
    else high2 = mid ;
   }
   
   int ret = low1 + low2 - 1 ;
   if(ret < 0) ret = 0 ;
   ret++ ;
   
   printf("%d\n",ret) ;
  }
 }
 return 0 ;
}


