#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
#define SIZE(A) ((int)(A.size()))
#define REP(i,N) for(int i=0;i<(int)N;i++)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define TR(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define GI ({int t; scanf("%d",&t);t;})
#define GL ({ long long  t; scanf("%lld",&t);t;})
#define ALL(x)  (x.begin(),x.end())
#define INF 1000000000
#define LINF 1000000000000000000LL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define MAXN 100005
#define LOGMAXN 18
char s[MAXN];
int n;
int arr[MAXN];
int lcp[MAXN];
int rank[MAXN];
int table[MAXN][LOGMAXN];
int logarithm[MAXN];
void processRMQ(){
    int i, j;
    for (i = 0; i <= n; i++) table[i][0] = i;
    for (j = 1; (1 << j) <= n; j++)
        for (i = 0; i + (1 << j) <= n; i++)
            if (lcp[table[i][j - 1]] < lcp[table[i + (1 << (j - 1))][j - 1]])
                table[i][j] = table[i][j - 1];
            else
                table[i][j] = table[i + (1 << (j - 1))][j - 1];
}
inline int query(int i, int j){
    int k=logarithm[j-i+1];
    if( lcp[table[i][k]] < lcp[table[j-(1<<k)+1][k]] )
        return table[i][k];
    else
        return table[j-(1<<k)+1][k];
}

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
struct SuffixArray {
    inline bool leq(int a1, int a2, int b1, int b2) { return (a1 < b1 || (a1 == b1 && a2 <= b2)); }
    inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {return (a1 < b1 || (a1 == b1 && leq(a2,a3,b2,b3)));}
    static void radixSort(int *a, int *b, int *r, int n, int alphabetSize) { int cnt[alphabetSize + 1], t, sum = 0;
    memset(cnt,0,sizeof(cnt)); REP (i,n) cnt[r[a[i]]]++; REP (i,alphabetSize+1){t = cnt[i];cnt[i] = sum;sum += t;}
    REP (i,n) b[cnt[r[a[i]]]++]=a[i];
    }
    void suffixArray(int *s, int *SA, int n, int alphabetSize) {
        int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2, name = 0, c0 = -1, c1 = -1, c2 = -1;
        int s12[n02 + 3], SA12[n02 + 3], s0[n0], SA0[n0];
        s12[n02] = s12[n02+1] = s12[n02+2] = 0;
        SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
        for(int i = 0, j = 0; i < n + n0 - n1; ++i){ if((i % 3) != 0) s12[j++] = i; }
        radixSort(s12, SA12, s+2, n02, alphabetSize);
        radixSort(SA12, s12, s+1, n02, alphabetSize);
        radixSort(s12, SA12, s, n02, alphabetSize);
        REP (i,n02) {
            if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
                name++; c0 = s[SA12[i]]; c1 = s[SA12[i] + 1]; c2 = s[SA12[i] + 2];
            }
            if (SA12[i]%3 == 1) s12[SA12[i]/3] = name;
            else s12[SA12[i]/3 + n0] = name;
        }
        if (name < n02) { suffixArray(s12, SA12, n02, name); REP(i,n02) s12[SA12[i]] = i+1;}
        else { REP(i,n02) SA12[s12[i] - 1] = i; }
        for(int i = 0,j = 0; i < n02; ++i) if(SA12[i] < n0) s0[j++] = 3 * SA12[i];
        radixSort(s0, SA0, s, n0, alphabetSize);
        for(int p = 0, t = n0 - n1, k = 0; k < n; k++){
            int i = GetI(), j = SA0[p];
            if( (SA12[t]<n0) ?
                (leq(s[i],s12[SA12[t]+n0],s[j],s12[j/3])) :
                (leq(s[i],s[i+1],s12[SA12[t]-n0+1],s[j],s[j+1],s12[j/3+n0]))          ){
                SA[k]=i;t++; if(t == n02) for(k++;p<n0;p++,k++) SA[k] = SA0[p];
            }
            else { SA[k]=j;p++; if(p == n0) for(k++;t<n02;t++,k++) SA[k] = GetI(); }
        }
    }
    void calculateSuffixArray(char *s, int n, int *res) {
        if (n == 1) { res[0] = 0; return; }
        int _s[n+3];REP(i,n) _s[i] = (int)(s[i]);
        _s[n] = _s[n + 1] = _s[n + 2] = 0;
        suffixArray(_s, res, n, 1000);
    }
    void calculateLcp(char *s, int n, int *P, int *lcp, int *rank) {
        fill(lcp, lcp + n, 0);
        REP (i,n) rank[P[i]] = i;
        int h=0;
        REP (i,n) {
            if (rank[i] > 0) {
                int j = P[rank[i] - 1];
                while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
                lcp[rank[i]] = h;
                if (h > 0) --h;
            }
        }
    }

}S;

int solve(int index,int length){
    int leftindex, rightindex ;
    int low,high,mid;
    
    if( lcp[index] < length ){
        leftindex = index + 1 ;
    }else{
        leftindex = index ;
        low = 1 ; 
        high = index ;
        while ( low <= high ){
            mid = ( high + low + 1 ) / 2 ;
            if( lcp[query(mid,index)] >= length ){
                leftindex = mid ;
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }
    }
    
    if( lcp[index+1] < length ){
        rightindex = index ;
    }else{
        rightindex = index + 1 ;
        low = index + 1 ; 
        high = n - 1  ;
        while ( low <= high ){
            mid = ( high + low + 1 ) / 2 ;
//             cout << low << ' ' << mid << ' ' << high << ' ' << lcp[query(index+1,mid)] << endl ;
            if( lcp[query(index+1,mid)] >= length ){
                rightindex = mid ;
                low = mid + 1 ;
            }else{
                high = mid - 1 ;
            }
        }
    }
//     cout << "ans = " << index << ' ' << leftindex << ' ' << rightindex << endl ;
    return rightindex - leftindex + 2 ;
}

int main(){
    // preprocess
    logarithm[1] = 0 ;
    logarithm[2] = 1 ;
    for ( int i = 3 ; i < MAXN ; i ++ )
        if( ( i & ( i -1 ) ) == 0 )
            logarithm[i] = logarithm[i-1] + 1 ;
        else
            logarithm[i] = logarithm[i-1] ;
//     REP(i,20) cout << logarithm[i] << ' ' ; cout << endl; 
    int tests;
    cin >> tests;
    while( tests -- ){
        cin >> n ;
        scanf("%s",s);
        S.calculateSuffixArray(s,n,arr);
        S.calculateLcp(s,n,arr,lcp,rank);
        processRMQ();
//         cout << s << endl;
//         REP(i,n) printf("%d ",arr[i]); cout<<endl;
//         REP(i,n) printf("%d ",lcp[i]); cout<<endl;
//         FOR(i,1,n-1){
//             FOR(j,1,n-1){
//                 cout << lcp[query( min(i,j) , max(i,j) )] << ' ' ;
//             }
//             cout << endl; 
//         }
//         cout << "\n\n____________________________________\n\n";
        int q ;
        int index , length ;
        cin >> q ;
        while ( q -- ) {
            scanf("%d %d",&index,&length) ; 
//             for ( int i = 0 ; i < length ; i ++ ) cout << s[ index + i ] ; cout << endl ;
            printf("%d\n",solve( rank[index] , length )) ; 
        }
    }
    return 0;
}