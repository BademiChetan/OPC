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
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long lint;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> p;


typedef long long lint;
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b){
        if(b&1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b>>=1;
    }
    return x%c;
}

/* This function calculates (ab)%c */
lint modulo(lint a,lint b,lint c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b){
        if(b&1){
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b>>=1;
    }
    return x%c;
}

 lint fi(lint n)
     {
       lint result = n;
       for(lint i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        lint r=fi(k);
        lint po=modulo(2,n,r);
        lint ans=modulo(2,po,k);
        cout<<ans<<"\n";
    }
    return 0;
}
