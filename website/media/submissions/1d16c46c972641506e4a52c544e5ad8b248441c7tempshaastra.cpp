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
#include <ctime>
#include <string>
#include <string.h>
#define pb push_back

#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,n) for(int i=0;i<n;i++)
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define disvec(v) { for(int vec_index=0;vec_index<v.size();vec_index++) cout<<v[vec_index]<<" "; cout<<endl;}
using namespace std;
typedef  long long LL;
typedef  long long ll;
int dp[110][110][3];
int solve(int odd,int even,int turn){
	if(odd==0 && even==1)
		return 0;
	if(odd==1 && even==0)
		return 1;
	if(dp[odd][even][turn]!=-1)
		return dp[odd][even][turn];
	int ret=0;
	if(turn){
		if(odd>=2){
			int flag=0;
			int t=odd-1,u=even;
			if(t==0 && u==1)ret|=0,flag=1;
			if(t==1 && u==0)ret|=1,flag=1;
			if(!flag)
				ret|=(!(solve(odd-1,even,0)));
		}
		if(even>=2){
			int t=odd+1,u=even-2;int flag=0;
			if(t==0 && u==1)ret|=0,flag=1;
			if(t==1 && u==0)ret|=1,flag=1;
			if(!flag)
				ret|=(!(solve(odd+1,even-2,0)));
		}
		if(odd>=1 && even>=1){
			int t=odd-1,u=even;int flag=0;
			if(t==0 && u==1)ret|=0,flag=1;
			if(t==1 && u==0)ret|=1,flag=1;
			if(!flag)
				ret|=(!(solve(odd-1,even,0)));
		}
	}
	else{
		if(odd>=2){
			int t=odd-2,u=even+1;int flag=0;
			if(t==0 && u==1)ret|=0,flag=1;
			if(t==1 && u==0)ret|=1,flag=1;
			if(!flag)
				ret|=(!(solve(odd-2,even+1,1)));
		}
		if(even>=2){
			int t=odd,u=even-1;int flag=0;
			if(t==0 && u==1)ret|=0,flag=1;
			if(t==1 && u==0)ret|=1,flag=1;
			if(!flag)
				ret|=(!(solve(odd,even-1,1)));
		}
		if(odd>=1&&even>=1){
			int t=odd,u=even-1;int flag=0;
			if(t==0 && u==1)ret|=0,flag=1;
			if(t==1 && u==0)ret|=1,flag=1;
			if(!flag)
				ret|=(!(solve(odd,even-1,1)));
		}
	}
	return dp[odd][even][turn]=ret;	
}
int main(){
	int t=GI;
	while(t--){
		int n=GI;
		int a[201];int sum=0;
		FOR(i,n){
			cin>>a[i];
			sum+=a[i];
		}
		if(n==1){
			if(a[0]&1)cout<<"WIN\n";
			else cout<<"LOSE\n";
			continue;
		}n--;
		sum-=(n*(n+1)/2);
		if(sum%2)cout<<"WIN\n";
		else cout<<"LOSE\n";
	}
    GI;
    return 0;
}
