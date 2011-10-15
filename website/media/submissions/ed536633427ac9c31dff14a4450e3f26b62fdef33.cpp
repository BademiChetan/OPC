
/*Kaushik Iska*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair
#define all(x) (x.begin(),x.end())
#define rep(i,n) for(int i=0;i<n;i++)
#define print(x) cout<<#x<<" is "<<x<<endl;
#define inf 2000000000
#define eps 1e-8

using namespace std;

int n,k;

int modp(int base,int exp,int mod)
{
	if(exp == 0)return 1;
	long long tmp = modp(base,exp/2,mod);
	tmp = tmp * tmp;
	tmp = tmp%mod;
	if(exp%2)tmp = tmp*base;
	tmp = tmp%mod;
	int ret = tmp;
	return ret;
}

int main(){
	int nt;
	scanf("%d",&nt);
	while(nt--)
	{
		scanf("%d%d",&n,&k);
		int ans = modp(2,n*2,k);
		printf("%d\n",ans);
	}
	return 0;
}
