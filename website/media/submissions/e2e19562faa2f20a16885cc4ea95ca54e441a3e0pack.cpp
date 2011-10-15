#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(a, b)   for (int a = 0; a < int(b); a++)
#define FOR(a,b,c)  for (int a = int(b); a < int(c); a++)    

typedef pair<int,int> pii;

int cost[10], val[10], num[10];

map<pair<int,int>, int> m;


int solve(int i, int j) {
     
   if (i == 0)  return m[pii(i, j)]; 
    if (m[pii(i, j)] != 0)  return m[pii(i, j)];

    int a;
    a = solve((i-1), j);
     REP(k, num[i]+1)  a = max(a, solve((i-1), j-k*cost[i]) + k*val[i]);
               
     m[pii(i,j)] = a;
    return a;
}

bool cmp(int i, int j)
{
    return (cost[j]*val[i] > cost[i]*val[j]);
}

int main()
{
    int T, N, W;
    int a, b;
    scanf("%d", &T);
    bool G;
    


    while (T--)
    {
        m.clear();
        scanf("%d %d", &N, &W);
        
        REP(i, N)   scanf("%d %d %d", &cost[i], &val[i], &num[i]);

        G = false;
        REP(i, N)   if (cost[i] < 10000) G = true;

        if (G)
        {
            
            int ar[10], ans = 0;
            REP(i, N)   ar[i] = i;

            sort(ar, ar+N, cmp);

            REP(i, N)    
            {
                if (num[ar[i]]*cost[ar[i]] <= W)    ans += num[ar[i]]*val[ar[i]];
                else
                {
                    ans += (W/cost[ar[i]])*val[ar[i]];
                    break;
                }
            }
            printf("%d\n", ans);

                        
            
                

        }
        else
        {
        
        
        
        REP(i, W+1) m[pair<int,int>(0,i)] = (i/cost[0] <= num[0]) ?  (i/cost[0])*val[0] : m[pii(0, i-1)];

        //REP(i, W+1) best[0][i] = (i/cost[0] <= num[0]) ?  (i/cost[0])*val[0] : best[0][i-1];
        
        solve(N, W);

        printf("%d\n", m[pii(N, W)]);
    
        }
    }
    return 0;
}
        

