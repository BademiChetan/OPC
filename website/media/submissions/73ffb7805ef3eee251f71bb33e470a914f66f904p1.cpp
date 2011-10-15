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
    long int i,j,n,x,y,row,col;
    for (i=0;i<t;++i)
    {
        cin>>x>>y;
        if(x>y)
        { col=x; 
          row=y;
        }
        else if(x<y)
        { col=y;
          row=x;
        }
        else 
        { cout<<0<<endl;
          continue;
        }
        if (col%2==0)
        { cout<<(col+row)<<endl;
          continue;
        }
        else
            { if(col-row==1)
              {   cout<<1<<endl;
                   continue;
              }
              else if(row%2==0)
              { cout<< (col+row)<<endl;
                continue;
              }
              else
              { cout<< (col+row-2)<<endl;
                continue;
              }
            }
          
      }
return 0;
}
