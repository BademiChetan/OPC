#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <set>
#include <map>
#include <numeric>
#include <ctime>
#include <functional>
#include <queue>

using namespace std;

struct cnt
{
       long w;
       long v;
       int f;
       float vbyw;
};


bool operator<(const cnt &a, const cnt &b)
{
 
 return a.vbyw>b.vbyw;
}

int main()
{
    int t;
    scanf("%d",&t);
    int i,j,n;
    long budget;
    long w;
       long v;
       int f;
       cnt c;
       double totalval=0;
    for (i=0;i<t;++i)
    {
           scanf("%d %ld",&n,&budget);
           vector<cnt> r;
           for (j=0;j<n;j++)
           {
               cin>>c.w>>c.v>>c.f;
               c.vbyw=((float)c.v)/c.w;
               r.push_back(c);
           }
           sort(r.begin(),r.end());
           //for(j=0;j<r.size();j++)
           //cout<<r[j].vbyw<<" "<<r[j].w<<" "<<r[j].v<<endl;
           for (j=0;j<r.size();j++)
           {
               
               while ( (budget-r[j].w>=0) && (r[j].f--) )
               {
                     totalval+=r[j].v;
                     budget-=r[j].w;
                     //cout<<budget<<" "<<totalval<<endl;
               }
           }
           cout<<totalval<<endl;
           totalval=0;  
                                
    }
    //system("pause");
    return 0;
}
    
                     
