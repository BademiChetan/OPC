#include<queue>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<map>
#include<fstream>
using namespace std;
#define dbg(x) cout << #x << " -> " << (x) << "\t";
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define sz size()
#define psi pair<string,int>
#define all(x) x.begin(),x.end()
#define GI ({int t;scanf("%d",&t); t;})
#define flush(x) memset(x,0,sizeof(x))
#define ll long long
#define mod 1000000007
#define st string
int ref[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int solve(int x,int y)
{
	if(x<4 && y<4) return ref[x][y];
	int g=max((int)pow(2.0,(int)log2(x)),(int)pow(2.0,(int)log2(y)));
	g*=2;
	///cout<<x<<" "<<y<<" "<<g<<endl;
	int a=x,b=y;
	if(a>=g/2) a-=g/2;
	if(b>=g/2) b-=g/2;
	if((x>=g/2 && y<g/2) || (x<g/2 && y>=g/2)) return (g/2+solve(a,b));
	else return solve(a,b);
}
int main()
{
	int t,n,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	return 0;
}
