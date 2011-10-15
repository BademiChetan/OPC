#include <iostream>

#include <cstring>
#include <cstdio>
#define sz size()
#define pb push_back
#define _(x,a) memset(x,a,sizeof(x))
#define LET(x,a) typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define LL long long
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})

using namespace std;

int main (int argc, char const* argv[]) {
	
	int t;
	cin>>t;
	while(t--) {
		int x, y;
		cin>>x>>y;
		cout<<(x^y)<<endl;
	}
	
	return 0;
}

