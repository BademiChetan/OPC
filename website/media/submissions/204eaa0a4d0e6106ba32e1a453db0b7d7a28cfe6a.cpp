// Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
// Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define FOR(i,a,b)          for(int i=a;i<b;i++)
#define pb                  push_back
#define mp                  make_pair
#define s(n)                scanf("%d",&n);
#define sl(n)               scanf("%lld",&n);
#define sf(n)               scanf("%f",&n);
#define fill(a,v)           memset(a,v, sizeof a);
#define all(x)              x.begin(),x.end()
#define maX(a,b)            (a>b?a:b)
#define miN(a,b)            (a<b?a:b)

map<float,pair<pair<float,float> ,float> > mape;
pair<float,float> pare;
void solve()
{
  int n,w,budget,value;
  float p,q,r,temp,temp1;
  s(n);s(w);
  FOR(i,0,n)
  {   scanf("%f %f %f",&p,&q,&r);
      temp=q/p;
      temp*=(-1);
      pare = mp(p,q);
      mape[temp] = mp(pare,r);
          }
map<float,pair<pair<float,float> , float> > :: iterator it = mape.begin();
 budget=0;
 value=0;
  while(budget<w&& it!= mape.end())
 {
    r=(*it).second.second ;
    p=(*it).second.first.first;
    q=(*it).second.first.second;
//    printf("%f %f %f\n",p,q,r);
   for(int i=0;i<r && budget<w;i++)
     { value+=q; 
       budget+=p;
          }
      it++;
    }
if(budget-w>0)
 {  budget-=p;
    temp=w-budget;
    value-=q;
  for(it = mape.begin();it!=mape.end();it++)
     {
         if(r<=(*it).second.first.first)
           {p=(*it).second.first.first;
            q=(*it).second.first.second;
            r=(*it).second.second;
            while(budget<w && r--)
            { value+=q;
              budget+=p;
              }}
          if(budget>=w)
              break;
       }
     }
    printf("%d\n",value);
 }
int main()
{
    int t;
    cin >> t;
    while(t--)
      solve();
    return 0;
}
