#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <queue> 
using namespace std ; 

int valmax[2000000];
typedef long long LL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define DOW(i,a,b) for(int i=(a); i>=(b); i--)
#define REP(i,n)   for(int i=0; i<(n); i++)
#define ALL(v) v.begin(),v.end()
#define MEMSET(v,h) memset(v,h,v.sizeof(v))
#define SZ(v) (int)v.size()
#define PB push_back
#define MP make_pair
#define Nmax 10005

vector< pair<int, int> > a1,a2;

int main()
{
   //freopen("test.in", "r", stdin);
   //freopen("test.out", "w", stdout);
   int T,N,Budget;
   int w[50],v[50];
   cin>>T;
   cin>>N>>Budget;
   int m=0;
   REP(i,N){
            int wx,vx,fx;
            cin>>wx>>vx>>fx;
            int mu2=0;
            REP(i,4){
                     if(mu2 + (1<<i) >fx){
                                fx-=mu2;
                                m++;
                                w[m]=fx*wx;
                                v[m]=fx*vx;
                                break;
                                }
                     mu2+=((1<<i));
                     m++;
                     w[m]=wx*(1<<i);
                     v[m]=vx*(1<<i);
                     } 
            }
  // FOR(i,1,m) cout<<w[i]<<" "<<v[i]<<endl;
   int div2=m/2;
   int k1=(1<<div2);
   REP(x,k1){
            int sum1=0;
            int val1=0;
            DOW(i,div2-1,0)
                       if((x>>i)&1){
                                    sum1+=w[i+1];
                                    val1+=v[i+1];
                                    }
            a1.PB(make_pair(sum1,val1));
            }
   int k2=1<<(m-div2);
   REP(x,k2){
            int sum2=0;
            int val2=0;
            DOW(i,m-div2-1,0)
                       if((x>>i)&1){
                                    sum2+=w[i+div2+1];
                                    val2+=v[i+div2+1];
                                    }
            a2.PB(make_pair(sum2,val2));
            }
            
   //REP(i,k2) cout<<a2[i].first<<" "<<a2[i].second<<endl;
   a1.PB(make_pair(0,0));
   a2.PB(make_pair(0,0));
   k1++;
   k2++;
   sort(a1.begin(), a1.end());
   sort(a2.begin(), a2.end());
   valmax[0]=a1[0].second;
   FOR(i,1,k1-1) valmax[i]=max(valmax[i-1],a1[i].second);
   int j=k1-1;
   int res=0;
   REP(i,k2){
            while((j>=0) && (a1[j].first+a2[i].first>Budget)) 
                       j--;
            if(j<0) break;
            res=max(res,a2[i].second+valmax[j]);
            }
   cout<<res<<endl;
   return 0;
}
