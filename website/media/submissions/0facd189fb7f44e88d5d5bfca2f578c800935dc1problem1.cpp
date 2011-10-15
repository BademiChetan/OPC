#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define PI 3.14159265

#define FOR(i,a,n) for(int i=a,_n=n; i<_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int arr[][10] = {
                {0,1,2,3,4,5,6,7},
                {1,0,3,2,5,4,7,6},
                {2,3,0,1,6,7,4,5},
                {3,2,1,0,7,6,5,4},
                {4,5,6,7,0,1,2,3},
                {5,4,7,6,1,0,3,2},
                {6,7,4,5,2,3,0,1},
                {7,6,5,4,3,2,1,0},
                };
int main(){
    int t;
    scanf("%d", &t);
    
    while (t--){
          int a, b; scanf("%d %d", &a, &b);
          //baris berapa?
          int x = a/8;
          int y = b/8;
          int ret = x+y;
          
          printf("%d\n", ret*8+arr[a%8][b%8]);      
    }
    return 0;
}
