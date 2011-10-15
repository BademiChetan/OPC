
//Author Phinfinity
#include<iostream>
#include<cstdio>
#include<vector>
#include<cassert>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
//#include<climits>
using namespace std;
#define pop_count(n) __builtin_popcount(n)
#define FOR(i,a,b) for(int i= (int)a; i< (int)b; ++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;
#define INF 1000000000

long long modpow(long long a,long long b,long long MOD)
{
        long long ret=1;
        while(b>0)
        {
                if(b&1)
                        ret = (ret*a)%MOD;
                b/=2;
                a*=a;
        }
        return ret%MOD;
}

int primes[32000],pcnt;
void genprimes()
{
   int i,j;
   for(i=0;i<32000;i++)primes[i]=0;
   for(i=2;i<32000;i++)
      if(!primes[i])
	 for(j=i+i;j<32000;j+=i)
	    primes[j]=1;
   pcnt=0;
   for(i=2;i<32000;i++)
      if(primes[i]==0)
	 primes[pcnt++]=i;
}

int eulerphi(int N)
{
   int n=N;
   int i;
   for(i=0;n>1 && primes[i]*primes[i]<=n;i++)
   {
      if(n%primes[i]==0)
      {
	 N=(N/primes[i])*(primes[i]-1);
	 while(n%primes[i]==0)
	    n/=primes[i];
      }
   }
   if(n>1)
      N=(N/n)*(n-1);
   return N;
}

int main()
{
   //CODE GOES HERE>>....
   genprimes();
   LL t,n,k;
   cin>>t;
   while(t--)
   {
      cin>>n>>k;
      if(n<=30)
      {
	 cout<<modpow(2,(1<<n),k)<<endl;
      }
      else
      {
	 int MOD=k;
	 int divcnt=0;
	 while(MOD>1 && MOD%2==0)
	 {
	    divcnt++;
	    MOD/=2;
	 }
	 int phi=eulerphi(MOD);
	 int res=(modpow(2,n,phi)-(divcnt%phi)+phi)%phi;
	 int ans=modpow(2,res,MOD);
	 while(divcnt)
	 {
	    ans=(ans*2)%k;
	    divcnt--;
	 }
	 cout<<ans<<endl;
      }
   }


   return 0;
}
