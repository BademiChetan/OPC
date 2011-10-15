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

int main()
{
    int t;
    scanf("%d",&t);
    int i;
    long j,n,q;
    long m,k;
    long found=0,count=0;
    for (i=0;i<t;++i)
    {
           scanf("%ld",&n);
           string str;
           cin>>str;
           
           scanf("%d",&q);
           //cout<<q;
           for (j=0;j<q;j++)
           {
               scanf("%d %d",&m,&k);
               //cout<<m<<"\t"<<k; 
               string str2=str.substr(m,k);
               found=str.find(str2,found);
               while (found!=string::npos)
               
               {
                     ++count;
                     found=str.find(str2,found+1);
                    
               
               }
               cout<<count<<endl;
               found=0;
               count=0;
           }
           /*for (j=0;j<n;j++)
           {
               printf("%d ",a[j]);
           }
           cout<<endl;
           */
    }
    system("pause");
    return 0;
}
    
                     
