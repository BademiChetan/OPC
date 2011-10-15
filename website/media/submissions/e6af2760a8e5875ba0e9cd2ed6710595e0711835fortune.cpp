#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>

#define PB push_back
#define M 100
#define N 100
#define LL long long



using namespace std;


LL power(LL a,LL b,LL mod)
{
	LL temp;
	if(a==0)
	return 0;
	if(b==0)
	return 1;
	temp=power(a,b/2,mod);
	if(b&1)
	return (temp*temp*a)%mod;
	return (temp*temp)%mod;
}



int main()
{
	
	int tc,n,k;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&n,&k);
		printf("%d\n",power(2,n,k));
	}
	
	return 0;
}
