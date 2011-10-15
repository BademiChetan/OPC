#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std ;
#define MOD 1000000007
#define MAXN 50002
#define LG 15
typedef pair<int,int> PII ;
char buff[MAXN] ;
int n,where[MAXN] ;

/*
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
pair<PII,int> L[MAXN] ;
int P[LG][MAXN] ;
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
*/


char str[MAXN];
int suffix[MAXN];
int group[MAXN];
int tg[MAXN];

struct comp
{
 int h;
 comp(int h):h(h) {}
 bool operator () (const int& s1 , const int& s2) const
 {
  return group[s1]<group[s2] || group[s1]==group[s2] && group[s1+h]< group[s2+h];
 }
};

void buildSA()
{
 for(int i = 0;i < n;i++) str[i] = buff[i] ;

 int n;
 for(n=0 ; n==0 || str[n-1] ; n++)
 {
  suffix[n] = n ;
  group[n] = str[n];
 }
 sort(suffix,suffix+n,comp(0));
 tg[0] = tg[n-1] = 0;
 for(int h=1 ; tg[n-1]!=n-1 ; h<<=1)
 {
  comp c(h);
  sort(suffix,suffix+n,c);
  for(int i=1 ; i<n ; ++i)
   tg[i] = tg[i-1]+c(suffix[i-1],suffix[i]);
  for(int i=0 ; i<n ; ++i)
   group[suffix[i]] = tg[i];
 } 
}

int rank[MAXN];
int lcp[MAXN];

void buildLCP()
{
  int n;
 for(n=0 ; n==0 || str[n-1] ; n++) rank[suffix[n]] = n;
  
  int c=0;
  for(int i=0 ; i<n ; i++)
  {
   if(rank[i])
   {
    int j= suffix[rank[i]-1];
    while(str[i+c] == str[j+c])
    c++;
   }
   lcp[rank[i]]=c;
   if(c) c--;
  }
}


/*
int tree[4 * MAXN] ;
void create(int k,int low,int high)
{
 if(low == high) { tree[k] = lcp[low + 1] ; return ; }
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
*/

int fast[LG][MAXN],LOG[MAXN] ;
void create2()
{
// for(int i = 0;i < n;i++) fast[0][i] = lc[i] ;
 for(int i = 0;i < n;i++) fast[0][i] = lcp[i + 1] ;
// for(int i = 0;i < n;i++) cout << lcp[i + 1] << endl ; cout << endl ;

 for(int j = 1;1 << j <= n;j++)
 {
  for(int i = 0;i + (1 << j) <= n;i++)
  {
   int q1 = fast[j - 1][i],q2 = fast[j - 1][i + (1 << j - 1)] ;
   fast[j][i] = min(q1,q2) ;
  }
 }
 memset(LOG,255,sizeof LOG) ;
 for(int i = 0;1 << i <= n;i++) LOG[1 << i] = i ;
 for(int i = 1;i < MAXN;i++) if(LOG[i] == -1) LOG[i] = LOG[i - 1] ;
}

int query(int low,int high)
{
 int k = LOG[high - low + 1] ;
 int q1 = fast[k][low] ;
 int q2 = fast[k][high - (1 << k) + 1] ;
 return min(q1,q2) ;
}


#define getcx getchar_unlocked
inline void s( int &n )
{
	n=0;
	int ch=getcx();
	while(ch < '0' || ch > '9' ) ch=getcx();
	while(ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}

inline void readstr(char *a)
{
	int ch=getcx();
	while( isspace(ch) ) ch=getcx();
 int sz = 0;
	while (!isspace(ch))
 {
  a[sz++] = ch;
  ch = getcx();
 }
 a[sz] = 0;
}


int main()
{
 int runs ;
 
 s(runs) ;
// scanf("%d",&runs) ;
 while(runs--)
 {
  memset(str,0,sizeof str) ;

//  scanf("%d",&n) ;
//  scanf("%s",buff) ;
  s(n) ;
  readstr(buff) ;

//  preprocess() ;
//  solve() ;
  buildSA() ;
  buildLCP() ;

//  create(1,0,n - 1) ;
 create2() ;
  
  for(int i = 0;i < n;i++) where[suffix[i + 1]] = i ;

  
  int q ;
  
  s(q) ;
//  scanf("%d",&q) ;
  while(q--)
  {
   int start,len ;
   s(start) ; s(len) ;
//   scanf("%d%d",&start,&len) ;

   start = where[start] ;
//   cout << start << endl ;
   
   int low1 = 0,high1 = start + 1 ;
   while(low1 + 1 < high1)
   {
    int mid = low1 + (high1 - low1) / 2 ;
 //   int qr = query(1,0,n - 1,start - mid + 1,start) ;
    int qr = query(start - mid + 1,start) ;
    if(qr >= len) low1 = mid ;
    else high1 = mid ;
   }
   
   int low2 = 0,high2 = n - start + 1 ;
   while(low2 + 1 < high2)
   {
    int mid = low2 + (high2 - low2) / 2 ;
//    int qr = query(1,0,n - 1,start,start + mid - 1) ;
    int qr = query(start + 1,start + 1 + mid - 1) ;

    if(qr >= len) low2 = mid ;
    else high2 = mid ;
   }
   
   int ret = low1 + low2 ;
   if(ret < 0) ret = 0 ;
   ret++ ;
   
   printf("%d\n",ret) ;
  }
 }
 return 0 ;
}


