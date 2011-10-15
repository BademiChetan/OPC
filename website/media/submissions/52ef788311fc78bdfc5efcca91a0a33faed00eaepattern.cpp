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

int main()
{
   // freopen("test.in", "r", stdin);
   // freopen("test.out", "w", stdout);
    int T,N;
    cin>>T;
    REP(i,T){
             cin>>N;
             int sum=0;
             REP(i,N){
                      int a;
                      cin>>a;
                      sum=(sum+a)%2;
                      }
             REP(i,N){
                      if(!(i%2)) sum=1-sum;
                      }
             if(sum) cout<<"WIN"<<endl;
             else cout<<"LOSE"<<endl;
             }
    return 0;
}
