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
int main()
{
	int t,n,a,ans=0;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		rep(i,n) {
			cin>>a;
			ans+=a;
			ans-=(i+1);
		}
		ans-=n;
		if(ans%2) cout<<"WIN\n";
		else cout<<"LOSE\n";
	}
	return 0;
}
