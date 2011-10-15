#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>

#define oo 1000000005
#define eps 1e-11

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

using namespace std;


typedef long long LL;
typedef pair <int, int> PII;
int ntest,x,y;

#define MAXN 65536
#define MAXLG 17
string A;
struct entry {
    int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;
int cmp(struct entry a, struct entry b){
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
int q;
int S[MAXN],l[MAXN];
int lcp(int x, int y){
    int k, ret = 0;
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
        if (P[k][x] == P[k][y])
            x+= 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}
int main () {
    freopen("test.in","r",stdin);    freopen("test.out","w",stdout);
    cin>>ntest;
    while(ntest--){
        cin>>N;
        cin>>A;
        //cout << A << endl;
        for (i = 0; i < N; i ++)
            P[0][i] = A[i] - 'a';
        for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1){
            for (i = 0; i < N; i ++){
                L[i].nr[0] = P[stp - 1][i];
                if(i + cnt < N) L[i].nr[1] = P[stp - 1][i + cnt];
                else  L[i].nr[1] = -1;
                L[i].p = i;
            }
            //sort(L, L + N, cmp);
            for (i = 0; i < N; i ++)
                if(i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1])
                    P[stp][L[i].p] =  P[stp][L[i - 1].p] ;
                 else  P[stp][L[i].p] = i;
        }
        int T[MAXN];
        for(int i=0; i<N; i++){
            S[i] = P[stp-1][i];
            T[P[stp-1][i]] = i;          
        }        
        memset(l,0,sizeof l);
        for(int i=0; i<N-1; i++){
            l[i] = lcp(T[i],T[i+1]);    
              
        }        
        scanf("%d",&q);
        int s,mx;
        while(q--){
            scanf("%d %d",&s,&mx);
            cout << 2 << endl;
            /* int o = S[s];         
            //cout << "O="          << o << endl;
            int e;
            for( e=0 ; e+o < N && l[e+o]>=mx;  e++);       
           //cout << "E=" << e << endl;
            int f;
            for(f=1; f<=o && l[o-f]>=mx;  f++);//cout << s << " "<< f << " " << l[o-f] << endl; 
           // cout << "F=" << f << endl;
            cout <<  e+f << endl;                */
        } 
    }   
    return 0;
}
